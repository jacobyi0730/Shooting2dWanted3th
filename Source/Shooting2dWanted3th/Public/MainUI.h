// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUI.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTING2DWANTED3TH_API UMainUI : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta=(BindWidget))
	class UScoreUI* WBP_Score;

	UPROPERTY(meta=(BindWidget))
	class UPlayerHPUI* WBP_Player_HP;

	UPROPERTY(meta=(BindWidget))
	class UGameOverUI* WBP_Game_Over;

};
