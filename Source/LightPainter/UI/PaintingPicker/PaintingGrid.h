// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <Blueprint/UserWidget.h>
#include <Components/UniformGridPanel.h>
#include <Components/HorizontalBox.h>
#include "PaintingGridCard.h"
#include "PaginationDot.h"
#include "PaintingGrid.generated.h"

UCLASS()
class LIGHTPAINTER_API UPaintingGrid : public UUserWidget
{
	GENERATED_BODY()

public:
	void AddPaginationDot(bool bActive);

	UFUNCTION(BlueprintCallable)
	void AddPainting(int32 PaintingIndex, FString PaintingName);

	UFUNCTION(BlueprintCallable)
	void ClearPaginationDots();

	UFUNCTION(BlueprintCallable)
	void ClearPaintings();

	int32 GetNumberOfSlots() const;

protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	UUniformGridPanel* PaintingGrid;
	
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	UHorizontalBox* PaginationDots;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPaintingGridCard> GridCardClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPaginationDot> PaginationDotClass;

	UPROPERTY(EditDefaultsOnly)
	float PaginationDotPadding = 8;
};