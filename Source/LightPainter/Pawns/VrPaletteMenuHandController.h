// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <Components/WidgetComponent.h>
#include "VrHandControllerBase.h"
#include "VrPaletteMenuHandController.generated.h"

UCLASS()
class LIGHTPAINTER_API AVrPaletteMenuHandController : public AVrHandControllerBase
{
	GENERATED_BODY()
	
public:
	AVrPaletteMenuHandController();

private:
	// Components
	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* PaletteMenu;
};