// Fill out your copyright notice in the Description page of Project Settings.

#include "VrHandControllerBase.h"

AVrHandControllerBase::AVrHandControllerBase()
{
	PrimaryActorTick.bCanEverTick = false;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);

	MotionController->SetShowDeviceModel(true);
}

void AVrHandControllerBase::SetHand(EControllerHand Hand)
{
	MotionController->SetTrackingSource(Hand);
}