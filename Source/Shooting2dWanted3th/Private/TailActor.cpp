// Fill out your copyright notice in the Description page of Project Settings.


#include "TailActor.h"


// Sets default values
ATailActor::ATailActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATailActor::BeginPlay()
{
	Super::BeginPlay();
	// 태어날 때 목적지가 이미 정해져 있지 않다면 주인공을 [목적지]로 하고싶다.
	if (nullptr == Target)
	{
		Target = GetWorld()->GetFirstPlayerController()->GetPawn();
	}
}

void ATailActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// 살아가면서 목적지를 향해 [이동]하고싶다.
	FVector dir = Target->GetActorLocation() - this->GetActorLocation();
	dir.Normalize();
	SetActorLocation(GetActorLocation() + dir * Speed * DeltaTime);
}

