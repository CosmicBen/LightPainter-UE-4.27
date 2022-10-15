// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingPicker.h"

#include "../../Saving/PainterSaveGame.h"
#include "../../Saving/PainterSaveGameIndex.h"
#include "ActionBar.h"

APaintingPicker::APaintingPicker()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	PaintingGrid = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaintingGrid"));
	PaintingGrid->SetupAttachment(GetRootComponent());

	ActionBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("ActionBar"));
	ActionBar->SetupAttachment(GetRootComponent());
}

void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();

	UActionBar* ActionBarWidget = Cast<UActionBar>(ActionBar->GetUserWidgetObject());
	if (ActionBarWidget)
	{
		ActionBarWidget->SetParentPicker(this);
	}

	Refresh();
}

void APaintingPicker::AddPainting()
{
	UPainterSaveGame::Create();
	Refresh();
}

void APaintingPicker::ToggleDeleteMode()
{
	UPaintingGrid* PaintingGridWidget = GetPaintingGrid();
	if (!PaintingGridWidget) { return; }

	PaintingGridWidget->ClearPaintings();
}

void APaintingPicker::UpdateCurrentPage(int32 Offset)
{
	CurrentPage = FMath::Clamp(CurrentPage + Offset, 0, GetNumberOfPages() - 1);
	Refresh();
}

int32 APaintingPicker::GetNumberOfPages() const
{
	UPaintingGrid* PaintingGridWidget = GetPaintingGrid();
	if (!PaintingGridWidget) { return 1; }

	int32 TotalNumberOfSlots = UPainterSaveGameIndex::Load()->GetSlotNames().Num();
	int32 SlotsPerPage = PaintingGridWidget->GetNumberOfSlots();

	return FMath::Max(1, FMath::CeilToInt((float)TotalNumberOfSlots / SlotsPerPage));
}

void APaintingPicker::RefreshDots()
{
	UPaintingGrid* PaintingGridWidget = GetPaintingGrid();
	if (!PaintingGridWidget) { return; }

	PaintingGridWidget->ClearPaginationDots();

	for (int32 i = 0; i < GetNumberOfPages(); ++i)
	{
		PaintingGridWidget->AddPaginationDot(i == CurrentPage);
	}
}

void APaintingPicker::RefreshSlots()
{
	UPaintingGrid* PaintingGridWidget = GetPaintingGrid();
	if (!PaintingGridWidget) { return; }

	PaintingGridWidget->ClearPaintings();

	int32 StartOffset = CurrentPage * GetPaintingGrid()->GetNumberOfSlots();
	TArray<FString> SlotNames = UPainterSaveGameIndex::Load()->GetSlotNames();

	for (int32 i = 0; i < PaintingGridWidget->GetNumberOfSlots() && StartOffset + i < SlotNames.Num(); ++i)
	{
		PaintingGridWidget->AddPainting(i, SlotNames[StartOffset + i]);
	}
}