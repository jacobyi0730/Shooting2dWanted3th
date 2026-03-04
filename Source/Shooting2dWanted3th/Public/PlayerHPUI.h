// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHPUI.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTING2DWANTED3TH_API UPlayerHPUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<class UProgressBar> HPBar;
	
	void SetHP(int32 hp, int32 max);
};
