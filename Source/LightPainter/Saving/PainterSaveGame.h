// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/SaveGame.h>
#include "PainterSaveGame.generated.h"

class AStroke;

USTRUCT()
struct FStrokeState
{
	GENERATED_BODY()

	UPROPERTY()
	TSubclassOf<class AStroke> Class;

	UPROPERTY()
	TArray<FVector> ControlPoints;
};

UCLASS()
class LIGHTPAINTER_API UPainterSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	static UPainterSaveGame* Create();
	static UPainterSaveGame* Load(FString SlotName);

	bool Save();

	void SetState(FString NewState) { State = NewState; }
	FString GetState() const { return State; }
	FString GetSlotName() const { return SlotName; }

	void SerializeFromWorld(UWorld* World);
	void DeserializeToWorld(UWorld* World);

private:
	// State
	UPROPERTY()
	FString State;

	UPROPERTY()
	FString SlotName;

	UPROPERTY()
	TArray<FStrokeState> Strokes;

	void ClearWorld(UWorld* World);
};