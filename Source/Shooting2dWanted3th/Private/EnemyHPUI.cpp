// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHPUI.h"
#include "Components/ProgressBar.h"

void UEnemyHPUI::SetHP(int32 cur, int32 max)
{
	HPBar->SetPercent(static_cast<float>(cur) / max);
}
