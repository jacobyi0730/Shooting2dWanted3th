// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnemyHPUI.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTING2DWANTED3TH_API UEnemyHPUI : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<class UProgressBar> HPBarBack;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<class UProgressBar> HPBarFront;

	void SetHP(int32 cur, int32 max);
};
