// Copyright Epic Games, Inc. All Rights Reserved.

#include "MergeGunPickUpComponent.h"

UMergeGunPickUpComponent::UMergeGunPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UMergeGunPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UMergeGunPickUpComponent::OnSphereBeginOverlap);
}

void UMergeGunPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AMergeGunCharacter* Character = Cast<AMergeGunCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
