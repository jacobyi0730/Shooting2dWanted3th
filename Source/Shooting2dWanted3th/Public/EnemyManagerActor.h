// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManagerActor.generated.h"

UCLASS()
class SHOOTING2DWANTED3TH_API AEnemyManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManagerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 시간이 흐르다가
	// [현재시간]이 [생성시간]이되면
	// [적공장]에서 적을 생성해서
	// [발사 위치]에 배치하고싶다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MakeTime = 2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AEnemyActor> EnemyFactory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* RootComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* FirePointComp;

	void MakeEnemy();
	FTimerHandle handle;

};
