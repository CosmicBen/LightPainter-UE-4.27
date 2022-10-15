// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Actor.h>
#include <MotionControllerComponent.h>
#include "VrHandControllerBase.generated.h"

UCLASS()
class LIGHTPAINTER_API AVrHandControllerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AVrHandControllerBase();

	void SetHand(EControllerHand Hand);

	virtual void TriggerPressed() {}
	virtual void TriggerReleased() {}

private:
	// Components
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;
};