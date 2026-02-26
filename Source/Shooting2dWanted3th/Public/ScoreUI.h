// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreUI.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTING2DWANTED3TH_API UScoreUI : public UUserWidget
{
	GENERATED_BODY()

public:
	// WBP_Score 에서 만들어진 위젯을 연결할 변수를 선언하고 싶다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* TextScore;

	void SetScore(int newScore);
};
