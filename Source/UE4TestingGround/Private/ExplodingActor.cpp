// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplodingActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AExplodingActor::AExplodingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	// This is going to be our overlap sphere, to know who we are destroying!
	ExplosionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionSphere"));
	ExplosionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ExplosionSphere->SetGenerateOverlapEvents(true);

	// We can use the overlap channel for now, but might want to think about something else?
	ExplosionSphere->SetCollisionResponseToAllChannels(ECR_Overlap);

	// this would be a param
	ExplosionSphere->SetSphereRadius(1000.00f);
	ExplosionSphere->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AExplodingActor::BeginPlay()
{
	Super::BeginPlay();

	// stores the output from COmponentOVerlapMulti
	TArray<FOverlapResult> TheOverlap;

	FVector Position = GetActorLocation();
	FQuat Rotation;
	MeshComp->GetRelativeRotationFromWorld(Rotation);

	// Get all componenets that overlap with our sphere. We'll use the PhysicsBody collision channel for now, but there's a nicer one
	ExplosionSphere->ComponentOverlapMulti(TheOverlap, GetWorld(), Position, Rotation, ECollisionChannel::ECC_Visibility);

	// Look at each componenet and apply a radial impulse, originating from our actor's location
	// We can do differnt if we'd like
	// Also set the force and strength to be params
	for (FOverlapResult thisActor : TheOverlap)
	{
		thisActor.GetComponent()->AddRadialImpulse(Position, 5000.0f, 5000.0f, ERadialImpulseFalloff::RIF_Linear, true);
	}
}

// Called every frame
void AExplodingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

