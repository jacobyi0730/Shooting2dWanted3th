// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

enum class EFireType
{
	Tick,
	Timer,
};

// 전방선언
class UStaticMeshComponent;
struct FInputActionValue;

UCLASS()
class SHOOTING2DWANTED3TH_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere)
	class UInputMappingContext* IMC_Player;

	UPROPERTY(EditAnywhere)
	class UInputAction* IA_Move;

	UPROPERTY(EditAnywhere)
	class UInputAction* IA_Fire;

	void OnMyMove(const FInputActionValue& value);
	void OnMyFirePressed(const FInputActionValue& value);
	void OnMyFireReleased(const FInputActionValue& value);

	// 자동으로 총을 쏘는 기능을 만들고 싶다.
	// 마우스 왼쪽 버튼을 누르고 있으면 [0.5초]마다 총알이 발사되게 하고싶다.
	// 마우스 왼쪽 버튼을 떼면 총알이 그만 나가게 하고싶다.
	// [온오프버튼], [주기]
	bool bAutoFire;
	float CurTime;
	float FireTime = 0.5f;
	// 총알생성기능
	void MakeBullet();

	EFireType FireType = EFireType::Tick;
	FTimerHandle FireHandle;

	
	

	
	FVector Direction;
	float Speed = 500.f;
	
public:
	// 루트컴포넌트를 만들고 싶다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* BoxComp;
	
	// 외형을 만들고 싶다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* MeshComp;

	// 총구 위치를 만들고 싶다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* FirePoint;

	// 총알 공장을 만들고 싶다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ABulletActor> BulletFactory;
};
