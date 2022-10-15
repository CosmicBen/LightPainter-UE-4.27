// Fill out your copyright notice in the Description page of Project Settings.

#include "PaginationDot.h"

void UPaginationDot::SetActive(bool bActive)
{
	DotImage->SetOpacity(bActive ? 1.0f : DisabledOpacity);
}