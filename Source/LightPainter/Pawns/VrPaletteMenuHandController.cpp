// Fill out your copyright notice in the Description page of Project Settings.

#include "VrPaletteMenuHandController.h"

AVrPaletteMenuHandController::AVrPaletteMenuHandController()
{
	PaletteMenu = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaletteMenu"));
	PaletteMenu->SetupAttachment(GetRootComponent());
}