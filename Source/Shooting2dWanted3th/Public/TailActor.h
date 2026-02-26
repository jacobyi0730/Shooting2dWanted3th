// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TailActor.generated.h"

UCLASS()
class SHOOTING2DWANTED3TH_API ATailActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATailActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 태어날 때 목적지가 이미 정해져 있지 않다면 주인공을 [목적지]로 하고싶다.
	// 살아가면서 목적지를 향해 [이동]하고싶다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AActor* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 450.f;
};
