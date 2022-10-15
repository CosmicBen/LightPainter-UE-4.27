// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Pawn.h>
#include <Camera/CameraComponent.h>
#include "VrHandControllerBase.h"
#include "VrPawn.generated.h"

UCLASS()
class LIGHTPAINTER_API AVrPawn : public APawn
{
	GENERATED_BODY()

public:
	AVrPawn();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	// Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AVrHandControllerBase> LeftHandControllerClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AVrHandControllerBase> RightHandControllerClass;

	UPROPERTY(EditDefaultsOnly)
	float PaginationThumbstickThreshold = 0.75f;

	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* VrRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	// Reference
	UPROPERTY()
	AVrHandControllerBase* RightHandController;

	UPROPERTY()
	AVrHandControllerBase* LeftHandController;

	// State
	int32 LastPaginationOffset = 0;

	void RightTriggerPressed() { if (RightHandController) { RightHandController->TriggerPressed(); } }
	void RightTriggerReleased() { if (RightHandController) { RightHandController->TriggerReleased(); } }

	void PaginateRightAxis(float AxisValue);
	void UpdateCurrentPage(int32 Offset);
};