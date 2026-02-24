// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"

#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AEnemyActor::AEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//루트를 만들어서 루트 컴포넌트로 하고싶다.
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent(BoxComp);
	// 외형을 만들어서 루트컴포넌트에 붙이고싶다.
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
	
	// 외형파일을 로드해서 MeshComp에 반영하고싶다.
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(
		TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (tempMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(tempMesh.Object);
	}

	ConstructorHelpers::FObjectFinder<UMaterial> tempMat(
		TEXT(
			"/Script/Engine.Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'"));
	if (tempMat.Succeeded())
	{
		MeshComp->SetMaterial(0, tempMat.Object);
	}
	
	// BoxComp를 충돌설정을 하고싶다.
	BoxComp->SetGenerateOverlapEvents(true);
	BoxComp->SetCollisionProfileName(TEXT("Enemy"));

}

// 태어날 때 방향을 정하고
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	// auto* target = UGameplayStatics::GetActorOfClass(
	// 	GetWorld(),
	// 	APlayerPawn::StaticClass()
	// );
	// 6. 나머지 확률로는 그냥 앞으로 하고싶다.
	Direction = GetActorForwardVector();
	
	int randValue = FMath::RandRange(0, 9);
	// 1. 30% 확률을 만들고싶다. 만약 30%라면
	if (randValue < 3)
	{
		// 3. 주인공을 찾고
		APawn* target = GetWorld()->GetFirstPlayerController()->GetPawn();
		// 4. 주인공을 향하는 방향 구해서
		// 5. Direction에 대입하고싶다.
		Direction = target->GetActorLocation() - this->GetActorLocation();
		Direction.Normalize();
		// Direction 방향으로 회전하고싶다.
		FRotator rot = UKismetMathLibrary::MakeRotFromXZ(Direction, GetActorUpVector());

		SetActorRotation(rot);
	}

	
}
// 살아가면서 그 방향으로 이동하고싶다.
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// P = P0 + vt
	SetActorLocation(GetActorLocation() + Direction.GetSafeNormal() * Speed * DeltaTime);
}

