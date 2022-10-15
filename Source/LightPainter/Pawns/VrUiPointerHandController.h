// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include "VrHandControllerBase.h"
#include "VrUiPointerHandController.generated.h"

class UWidgetInteractionComponent;

UCLASS()
class LIGHTPAINTER_API AVrUiPointerHandController : public AVrHandControllerBase
{
	GENERATED_BODY()

public:
	AVrUiPointerHandController();

	void TriggerPressed() override;
	void TriggerReleased() override;

private:
	UPROPERTY(VisibleAnywhere)
	UWidgetInteractionComponent* Pointer;
};