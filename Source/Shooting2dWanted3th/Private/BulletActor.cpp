// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"

#include "EnemyActor.h"
#include "ShootingGameMode.h"
#include "Components/BoxComponent.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//루트를 만들어서 루트 컴포넌트로 하고싶다.
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent(BoxComp);
	BoxComp->SetBoxExtent(FVector(50));
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

	ConstructorHelpers::FObjectFinder<UMaterial> tempMat(TEXT("/Script/Engine.Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'"));
	if (tempMat.Succeeded())
	{
		MeshComp->SetMaterial(0, tempMat.Object);
	}

	// BoxComp를 충돌설정을 하고싶다.
	BoxComp->SetGenerateOverlapEvents(true);
	BoxComp->SetCollisionProfileName(TEXT("Bullet"));

	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();

	// BoxComp에게 충돌하면 알려달라고 하고싶다.
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ABulletActor::OnMyCompBeginOverlab);
	
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// 앞으로 이동하고 싶다.
	// P = P0 + vt
	FVector P0 = GetActorLocation();
	FVector vt = GetActorForwardVector() * Speed * DeltaTime;
	SetActorLocation(P0 + vt);

}

void ABulletActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	// // 너죽고 나죽자.
	// OtherActor->Destroy();
	// this->Destroy();
}

void ABulletActor::OnMyCompBeginOverlab(
	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	// 만약 OtherActor가 Enemy라면
	if (Cast<AEnemyActor>(OtherActor)) //if (OtherActor->IsA<AEnemyActor>())
	{
		// 너죽고
		OtherActor->Destroy();
		// 게임모드를 가져와서
		auto* gm = Cast<AShootingGameMode>(GetWorld()->GetAuthGameMode());
		// 게임모드에게 점수를 1점 증가시켜달라고 요청하고싶다.
		gm->AddScore(1);
	}
	// if (OtherActor->Tags.Contains(TEXT("Enemy")))
	// {
	// 	
	// }
	// if (OtherActor->GetActorNameOrLabel().Contains(TEXT("Enemy")))
	// {
	// 	
	// }
	
	
	// 나죽자.
	this->Destroy();
}