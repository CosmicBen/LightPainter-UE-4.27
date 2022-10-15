// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/GameModeBase.h>
#include "PaintingGameMode.generated.h"

UCLASS()
class LIGHTPAINTER_API APaintingGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

protected:
	virtual void BeginPlay() override;

public:
	static const FString SLOT_NAME;

	void Load();
	void Save();

	UFUNCTION(BlueprintCallable)
	void SaveAndQuit();

private:
	// State
	FString SlotName;
};