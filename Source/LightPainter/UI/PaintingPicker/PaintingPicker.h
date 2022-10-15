// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Actor.h>
#include <Components/WidgetComponent.h>
#include "PaintingGrid.h"
#include "PaintingPicker.generated.h"

UCLASS()
class LIGHTPAINTER_API APaintingPicker : public AActor
{
	GENERATED_BODY()
	
public:	
	APaintingPicker();

protected:
	virtual void BeginPlay() override;

public:
	void AddPainting();
	void ToggleDeleteMode();
	void UpdateCurrentPage(int32 Offset);

private:
	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* PaintingGrid;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* ActionBar;

	// State
	int32 CurrentPage = 0;

	int32 GetNumberOfPages() const;
	UPaintingGrid* GetPaintingGrid() const { return Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject()); }

	void Refresh() { RefreshSlots(); RefreshDots(); }
	void RefreshDots();
	void RefreshSlots();
};