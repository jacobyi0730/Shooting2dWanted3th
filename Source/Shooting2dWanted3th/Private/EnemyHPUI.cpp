// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHPUI.h"
#include "Components/ProgressBar.h"

void UEnemyHPUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	float A = HPBarBack->GetPercent();
	float B = HPBarFront->GetPercent();
	
	A = FMath::Lerp(A, B, InDeltaTime * 20);
	HPBarBack->SetPercent(A);
}

void UEnemyHPUI::SetHP(int32 cur, int32 max)
{
	HPBarFront->SetPercent(static_cast<float>(cur) / max);
}
