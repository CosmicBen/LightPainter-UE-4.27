// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingGameMode.h"

#include <Kismet/GameplayStatics.h>
#include <Kismet/StereoLayerFunctionLibrary.h>
#include "Saving/PainterSaveGame.h"

const FString APaintingGameMode::SLOT_NAME = "SlotName";

void APaintingGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	SlotName = UGameplayStatics::ParseOption(Options, SLOT_NAME);
	UE_LOG(LogTemp, Warning, TEXT("SlotName: %s"), *SlotName);
}

void APaintingGameMode::BeginPlay()
{
	Super::BeginPlay();

	Load();
}

void APaintingGameMode::Load()
{
	UPainterSaveGame* Painting = UPainterSaveGame::Load(SlotName);

	if (Painting)
	{
		Painting->DeserializeToWorld(GetWorld());
		UStereoLayerFunctionLibrary::HideSplashScreen();
		UE_LOG(LogTemp, Warning, TEXT("Loaded: %s"), *SlotName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Found: %s"), *SlotName);
	}
}

void APaintingGameMode::Save()
{
	UPainterSaveGame* Painting = UPainterSaveGame::Load(SlotName);

	if (Painting)
	{
		Painting->SerializeFromWorld(GetWorld());
		Painting->Save();
	}
}

void APaintingGameMode::SaveAndQuit()
{
	Save();

	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenu"));
}