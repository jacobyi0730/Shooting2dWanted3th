// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShootingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTING2DWANTED3TH_API AShootingGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	// 태어날 때 WBP_Score를 생성하고 Viewport에 붙이고싶다.
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> ScoreUIFactory; 
	UPROPERTY()
	class UScoreUI* ScoreUI; 
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Score;

	void AddScore(int value);
};
