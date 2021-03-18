// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExplodingActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class UE4TESTINGGROUND_API AExplodingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplodingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USphereComponent* ExplosionSphere;

	UPROPERTY(EditDefaultsOnly, Category = "ExplodingActor")
	UStaticMeshComponent* MeshComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
