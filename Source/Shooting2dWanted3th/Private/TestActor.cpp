// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

int kk();
// Sets default values
ATestActor::ATestActor()
{
	kk();
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
int kk()
{
	return 0;
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

