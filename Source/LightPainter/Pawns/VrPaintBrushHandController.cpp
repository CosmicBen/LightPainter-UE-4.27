// Fill out your copyright notice in the Description page of Project Settings.

#include "VrPaintBrushHandController.h"

#include <Engine/World.h>

AVrPaintBrushHandController::AVrPaintBrushHandController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AVrPaintBrushHandController::BeginPlay()
{
	Super::BeginPlay();
}

void AVrPaintBrushHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentStroke)
	{
		CurrentStroke->Update(GetActorLocation());
	}
}

void AVrPaintBrushHandController::TriggerPressed()
{
	CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeClass);
	CurrentStroke->SetActorLocation(GetActorLocation());
	CurrentStroke->SetOwner(this);
}

void AVrPaintBrushHandController::TriggerReleased()
{
	CurrentStroke = NULL;
}