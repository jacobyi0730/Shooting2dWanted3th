// Fill out your copyright notice in the Description page of Project Settings.


#include "CodingActor.h"

// Sets default values
ACodingActor::ACodingActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACodingActor::BeginPlay()
{
	Super::BeginPlay();

	FString log =  TEXT("Hello World 영훈!");

	UE_LOG(LogTemp, Warning, TEXT("%s"), *log);
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Cyan, log);

}

// Called every frame
void ACodingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 ACodingActor::MyAdd(int32 a, int32 b)
{
	return a + b;
}

int32 ACodingActor::MyAddNativeEvent_Implementation(int32 a, int32 b)
{
	return a + b;
}
