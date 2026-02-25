// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "BulletActor.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Components/BoxComponent.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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

	ConstructorHelpers::FObjectFinder<UMaterial> tempMat(
		TEXT(
			"/Script/Engine.Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'"));
	if (tempMat.Succeeded())
	{
		MeshComp->SetMaterial(0, tempMat.Object);
	}

	// 총구위치 컴포넌트를 생성해서 루트에 붙이고싶다.
	FirePoint = CreateDefaultSubobject<USceneComponent>(TEXT("FirePoint"));
	FirePoint->SetupAttachment(RootComponent);


	// BoxComp를 충돌설정을 하고싶다.
	BoxComp->SetGenerateOverlapEvents(true);
	BoxComp->SetCollisionProfileName(TEXT("Player"));
	// BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	// BoxComp->SetCollisionObjectType(ECC_GameTraceChannel1);
	// BoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	// BoxComp->SetCollisionResponseToChannel(
	// 	ECC_GameTraceChannel2,
	// 	ECR_Overlap
	// );
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	// PlayerController를 가져오고싶다.
	auto* pc = GetWorld()->GetFirstPlayerController();
	// IMC_Player를 반영하고 싶다.
	UEnhancedInputLocalPlayerSubsystem* subsys = ULocalPlayer::GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());

	if (subsys)
	{
		subsys->AddMappingContext(IMC_Player, 0);
	}
}

float k = 0;// 전역변수. 

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// P = P0 + velocity(direction * speed) * t
	FVector P0 = GetActorLocation();
	FVector velocity = Direction * Speed;
	SetActorLocation(P0 + velocity * DeltaTime);

	Direction = FVector::Zero();
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(
	UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(
		PlayerInputComponent);

	if (input)
	{
		input->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APlayerPawn::OnMyMove);
		
		input->BindAction(IA_Fire, ETriggerEvent::Started, this, &APlayerPawn::OnMyFirePressed);
		input->BindAction(IA_Fire, ETriggerEvent::Completed, this, &APlayerPawn::OnMyFireReleased);
	}
}

void APlayerPawn::OnMyMove(const FInputActionValue& value)
{
	FVector2d v = value.Get<FVector2d>();
	Direction.Z = v.X;
	Direction.Y = v.Y;
}

void APlayerPawn::OnMyFirePressed(const FInputActionValue& value)
{
	UE_LOG(LogTemp, Warning, TEXT("%hs"), __FUNCTION__)

	// 총알공장에서 총알을 생성해서 FirePoint에 배치하고싶다.
	FTransform t = FirePoint->GetComponentTransform();
	GetWorld()->SpawnActor<ABulletActor>(BulletFactory, t);
}

void APlayerPawn::OnMyFireReleased(const FInputActionValue& value)
{
}
