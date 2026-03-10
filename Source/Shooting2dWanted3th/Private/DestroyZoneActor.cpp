// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyZoneActor.h"

#include "BulletActor.h"
#include "EnemyActor.h"
#include "PlayerPawn.h"
#include "Components/BoxComponent.h"

// Sets default values
ADestroyZoneActor::ADestroyZoneActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//BoxComp를 생성해서 루트로 하고싶다.
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent(BoxComp);
	BoxComp->SetBoxExtent(FVector(50));
	// 충돌설정하고싶다.
	BoxComp->SetGenerateOverlapEvents(true);
	BoxComp->SetCollisionProfileName(TEXT("DestroyZone"));

}

// Called when the game starts or when spawned
void ADestroyZoneActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestroyZoneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestroyZoneActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	// 만약 적이라면 파괴하고싶다.
	if (OtherActor->IsA<AEnemyActor>())
	{
		OtherActor->Destroy();
	}
	else if (auto* bullet = Cast<ABulletActor>(OtherActor))
	{
		auto* player = Cast<APlayerPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
		// 만약 탄창에 없으면
		if (false == player->Magazine.Contains(bullet))
		{
			// 탄창에 총알을 넣고싶다.
			bullet->SetActive(false);
			player->Magazine.Add(bullet);
		}
	}
}

