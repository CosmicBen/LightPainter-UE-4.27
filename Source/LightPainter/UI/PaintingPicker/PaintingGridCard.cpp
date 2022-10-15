// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGridCard.h"

#include <Kismet/GameplayStatics.h>
#include <Kismet/StereoLayerFunctionLibrary.h>
#include "../../PaintingGameMode.h"

void UPaintingGridCard::SetPaintingName(FString NewPaintingName)
{
	PaintingName = NewPaintingName;

	SlotName->SetText(FText::FromString(PaintingName));

	Button->OnClicked.AddDynamic(this, &UPaintingGridCard::CardButtonClicked);
}

void UPaintingGridCard::CardButtonClicked()
{
	UStereoLayerFunctionLibrary::ShowSplashScreen();
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Canvas"), true, APaintingGameMode::SLOT_NAME + "=" + PaintingName);
}