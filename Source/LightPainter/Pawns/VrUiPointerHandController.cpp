// Fill out your copyright notice in the Description page of Project Settings.

#include "VrUiPointerHandController.h"

#include <Components/WidgetInteractionComponent.h>
#include <InputCoreTypes.h>

AVrUiPointerHandController::AVrUiPointerHandController()
{
	Pointer = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("Pointer"));
	Pointer->SetupAttachment(GetRootComponent());
}

void AVrUiPointerHandController::TriggerPressed()
{
	Pointer->PressPointerKey(EKeys::LeftMouseButton);
}

void AVrUiPointerHandController::TriggerReleased()
{
	Pointer->ReleasePointerKey(EKeys::LeftMouseButton);
}