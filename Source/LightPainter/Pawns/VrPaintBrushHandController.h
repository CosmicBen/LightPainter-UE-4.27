// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Actor.h>
#include "../Drawing/Stroke.h"
#include "VrHandControllerBase.h"
#include "VrPaintBrushHandController.generated.h"

UCLASS()
class LIGHTPAINTER_API AVrPaintBrushHandController : public AVrHandControllerBase
{
	GENERATED_BODY()
	
public:	
	AVrPaintBrushHandController();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void TriggerPressed() override;
	void TriggerReleased() override;

private:
	// Config
	UPROPERTY(EditAnywhere)
	TSubclassOf<AStroke> StrokeClass;

	// State
	AStroke* CurrentStroke;
};