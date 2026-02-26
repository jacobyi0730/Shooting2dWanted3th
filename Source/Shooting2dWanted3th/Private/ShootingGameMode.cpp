// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameMode.h"

#include "ScoreUI.h"
#include "Blueprint/UserWidget.h"

void AShootingGameMode::BeginPlay()
{
	Super::BeginPlay();
	// 태어날 때 UI를 만들어서
	ScoreUI = CreateWidget<UScoreUI>(GetWorld(), ScoreUIFactory);
	// 뷰포트에 붙이고싶다.
	ScoreUI->AddToViewport();
}

void AShootingGameMode::AddScore(int value)
{
	// 점수를 획득하면 UI에도 반영하고싶다.
	Score += value;
	ScoreUI->SetScore(Score);
}
