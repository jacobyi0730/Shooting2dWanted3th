// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

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
