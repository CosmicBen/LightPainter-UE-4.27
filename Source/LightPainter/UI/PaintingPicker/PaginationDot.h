// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <Blueprint/UserWidget.h>
#include <Components/Image.h>
#include "PaginationDot.generated.h"

UCLASS()
class LIGHTPAINTER_API UPaginationDot : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetActive(bool bActive);

protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	UImage* DotImage;

private:
	// Configuratin
	UPROPERTY(EditDefaultsOnly)
	float DisabledOpacity = 0.5f;
};