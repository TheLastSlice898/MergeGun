// Fill out your copyright notice in the Description page of Project Settings.


#include "GunPartComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGunPartComponent::AGunPartComponent()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create and assign the mesh component so PartMesh is valid at runtime
	PartMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PartMesh"));
	RootComponent = PartMesh;

	// Optional: configure defaults
	PartMesh->SetCollisionProfileName(TEXT("BlockAll"));
	PartMesh->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void AGunPartComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGunPartComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

