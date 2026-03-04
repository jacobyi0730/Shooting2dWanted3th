// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameMode.h"
#include "MainUI.h"
#include "ScoreUI.h"

void AShootingGameMode::BeginPlay()
{
	Super::BeginPlay();
	// 태어날 때 UI를 만들어서
	MainUI = CreateWidget<UMainUI>(GetWorld(), MainUIFactory);
	// 뷰포트에 붙이고싶다.
	MainUI->AddToViewport();
}

void AShootingGameMode::AddScore(int32 value)
{
	// 점수를 획득하면 UI에도 반영하고싶다.
	Score += value;
	MainUI->WBP_Score->SetScore(Score);
}
