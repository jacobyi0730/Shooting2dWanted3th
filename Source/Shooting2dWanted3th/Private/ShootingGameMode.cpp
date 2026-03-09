// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameMode.h"
#include "MainUI.h"
#include "SaveGameShooing.h"
#include "ScoreUI.h"
#include "Kismet/GameplayStatics.h"

void AShootingGameMode::BeginPlay()
{
	Super::BeginPlay();
	// 태어날 때 UI를 만들어서
	MainUI = CreateWidget<UMainUI>(GetWorld(), MainUIFactory);
	// 뷰포트에 붙이고싶다.
	MainUI->AddToViewport();
	// 태어날 때 최고점수를 읽어오고싶다.
	MyLoadGame();
}

int32 AShootingGameMode::GetScore()
{
	return Score;
}

void AShootingGameMode::SetScore(int32 value)
{
	Score = value;
	MainUI->WBP_Score->SetScore(Score);
}


void AShootingGameMode::AddScore(int32 value)
{
	// 점수를 획득하면 UI에도 반영하고싶다.
	SCORE += value;
	//SetScore(GetScore() + value);
	// Score += value;
	// MainUI->WBP_Score->SetScore(Score);

	// 만약 현재점수가 최고점수보다 크다면
	if (Score > HighScore)
	{
		// 최고점수를 현재점수로 대입하고싶다.
		HighScore = Score;
		// UI도 갱신하고싶다.
		MainUI->WBP_Score->SetHighScore(HighScore);

		// HighScore 저장하기
		MySaveGame();
	}
}

void AShootingGameMode::MyLoadGame()
{
	if (false == UGameplayStatics::DoesSaveGameExist(SlotName, 0))
	{
		// 파일이 없으니 최초다. 초기화 처리
		HighScore = 0;
		return;
	}
	// 파일이 존재한다.
	USaveGame* sg = UGameplayStatics::LoadGameFromSlot(SlotName, 0);
	USaveGameShooing* sgInstance = Cast<USaveGameShooing>(sg);
	HighScore = sgInstance->Save_HighScore;
	MainUI->WBP_Score->SetHighScore(HighScore);
}

void AShootingGameMode::MySaveGame()
{
	// SaveGame 객체를 만들고싶다.
	USaveGame* sg = UGameplayStatics::CreateSaveGameObject(USaveGameShooing::StaticClass());
	USaveGameShooing* sgInstance = Cast<USaveGameShooing>(sg);
	
	sgInstance->Save_HighScore = HighScore;
	// SaveGame객체를 파일로 저장하고싶다.
	UGameplayStatics::SaveGameToSlot(sgInstance, SlotName, 0);
}
