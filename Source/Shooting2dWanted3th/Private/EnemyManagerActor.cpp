// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManagerActor.h"

#include "EnemyActor.h"
#include "Components/ArrowComponent.h"

// Sets default values
AEnemyManagerActor::AEnemyManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);
	FirePointComp = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePointComp"));
	FirePointComp->SetupAttachment(RootComponent);
	FirePointComp->SetWorldRotation(FRotator(-90, 180, 0));
}

// Called when the game starts or when spawned
void AEnemyManagerActor::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(handle, this, &AEnemyManagerActor::MakeEnemy, 2, true);
	
}

void AEnemyManagerActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(handle);
}

// Called every frame
void AEnemyManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// // 시간이 흐르다가
	// CurTime += DeltaTime;
	// // 만약 [현재시간]이 [생성시간]을 초과하면
	// if (CurTime > MakeTime)
	// {
	// 	MakeEnemy();
	// 	// 현재시간을 0으로 초기화.
	// 	CurTime = 0;
	// }
}
void AEnemyManagerActor::MakeEnemy()
{
	// [적공장]에서 적을 생성해서 [발사 위치]에 배치하고싶다.
	FTransform t = FirePointComp->GetComponentTransform();
	GetWorld()->SpawnActor<AEnemyActor>(EnemyFactory, t);
}

