// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodingActor.generated.h"

UCLASS()
class SHOOTING2DWANTED3TH_API ACodingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACodingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AAAA)
	int32 Number = 10;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 MyAdd(int32 a, int32 b);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	int32 MyAddForBlueprint(int32 a, int32 b);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 MyAddNativeEvent(int32 a, int32 b);
};
