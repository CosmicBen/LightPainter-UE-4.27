// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include "GameFramework/SaveGame.h"
#include "PainterSaveGame.h"
#include "PainterSaveGameIndex.generated.h"

UCLASS()
class LIGHTPAINTER_API UPainterSaveGameIndex : public USaveGame
{
	GENERATED_BODY()
	
public:
	static UPainterSaveGameIndex* Load();

	void AddSaveGame(UPainterSaveGame* SaveGame);

	TArray<FString> GetSlotNames() const { return SlotNames; }

	bool Save();

private:
	static const FString SLOT_NAME;

	UPROPERTY()
	TArray<FString> SlotNames;
};