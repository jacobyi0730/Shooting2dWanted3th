// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHPUI.h"

#include "Components/ProgressBar.h"

void UPlayerHPUI::SetHP(int32 hp, int32 max)
{
	float percent = static_cast<float>(hp) / max;
	HPBar->SetPercent(percent);
}
