// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreUI.h"

#include "Components/TextBlock.h"

void UScoreUI::SetScore(int32 newScore)
{
	TextScore->SetText(FText::AsNumber(newScore));

	//FString s = FString(TEXT("%d"), newScore);
	//TextScore->SetText(FText::FromString(s));
}

void UScoreUI::SetHighScore(int32 newHighScore)
{
	TextHighScore->SetText(FText::AsNumber(newHighScore));
}
