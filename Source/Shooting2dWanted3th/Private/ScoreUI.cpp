// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreUI.h"

#include "Components/TextBlock.h"

void UScoreUI::SetScore(int newScore)
{
	TextScore->SetText(FText::AsNumber(newScore));

	//FString s = FString(TEXT("%d"), newScore);
	//TextScore->SetText(FText::FromString(s));
}
