// Fill out your copyright notice in the Description page of Project Settings.

#include "GunActor.h"
#include "GunPartComponent.h"

// Sets default values
AGunActor::AGunActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Core = CreateDefaultSubobject<UMergeGunWeaponComponent>(TEXT("GunCore"));
	if (Core)
	{
		RootComponent = Core;
	}
}

// Called when the game starts or when spawned
void AGunActor::BeginPlay()
{
	Super::BeginPlay();

	// Spawn the barrel once (make sure Barrel is set in the editor or elsewhere)
	if (Barrel != nullptr && GetWorld() && Core)
	{
		const FTransform SocketTransform = Core->GetSocketTransform(TEXT("Barrel_Socket"));
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();

		AGunPartComponent* SpawnedPart = GetWorld()->SpawnActor<AGunPartComponent>(Barrel, SocketTransform, SpawnParams);
		if (SpawnedPart)
		{
			// Attach spawned actor to the weapon component at the socket
			SpawnedPart->AttachToComponent(Core, FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("Barrel_Socket"));
		}
	}
}

// Called every frame
void AGunActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

