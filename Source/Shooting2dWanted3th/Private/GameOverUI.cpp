// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverUI.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UGameOverUI::NativeConstruct()
{
	Super::NativeConstruct();
	ButtonRestart->OnClicked.AddDynamic(this, &UGameOverUI::OnMyRestart);
	ButtonQuit->OnClicked.AddDynamic(this, &UGameOverUI::OnMyQuit);
}

void UGameOverUI::OnMyRestart()
{
	FString levelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
	UGameplayStatics::OpenLevel(GetWorld(), FName(*levelName));
}

void UGameOverUI::OnMyQuit()
{
	auto* pc = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), pc, EQuitPreference::Quit, false);
}
