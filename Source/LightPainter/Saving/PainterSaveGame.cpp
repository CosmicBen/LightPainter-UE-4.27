// Fill out your copyright notice in the Description page of Project Settings.


#include "PainterSaveGame.h"

#include <EngineUtils.h>
#include <Kismet/GameplayStatics.h>
#include <Misc/Guid.h>
#include "../Drawing/Stroke.h"
#include "PainterSaveGameIndex.h"

UPainterSaveGame* UPainterSaveGame::Create()
{
	UPainterSaveGame* NewSaveGame = Cast<UPainterSaveGame>(UGameplayStatics::CreateSaveGameObject(UPainterSaveGame::StaticClass()));
	NewSaveGame->SlotName = FGuid::NewGuid().ToString();
	if (!NewSaveGame->Save()) { return NULL; }

	UPainterSaveGameIndex* Index = UPainterSaveGameIndex::Load();
	Index->AddSaveGame(NewSaveGame);
	Index->Save();

	return NewSaveGame;
}

UPainterSaveGame* UPainterSaveGame::Load(FString SlotName)
{
	USaveGame* LoadedSaveGame = UGameplayStatics::LoadGameFromSlot(SlotName, 0);
	if (LoadedSaveGame)
	{
		return Cast<UPainterSaveGame>(LoadedSaveGame);
	}

	return Create();
}

bool UPainterSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}

void UPainterSaveGame::SerializeFromWorld(UWorld* World)
{
	Strokes.Empty();

	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		Strokes.Add(StrokeItr->SerializeToStruct());
	}
}

void UPainterSaveGame::DeserializeToWorld(UWorld* World)
{
	ClearWorld(World);

	for (FStrokeState StrokeState : Strokes)
	{
		AStroke::SpawnAndDeserializeFromStruct(World, StrokeState);
	}
}

void UPainterSaveGame::ClearWorld(UWorld* World)
{
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		StrokeItr->Destroy();
	}
}