// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GunPartComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MergeGun/MergeGunWeaponComponent.h"
#include "GameFramework/Actor.h"
#include "GunActor.generated.h"

UCLASS(Blueprintable)
class UGunStats : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Damage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Ammo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Accuracy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HandleSpeed;

	virtual void InitializeStats(float InDamage, int32 InAmmo, float InFireRate, float InAccuracy, float InHandleSpeed)
	{
		Damage = InDamage;
		Ammo = InAmmo;
		FireRate = InFireRate;
		Accuracy = InAccuracy;
		HandleSpeed = InHandleSpeed;
	}
};



UCLASS(Abstract, meta = (PrioritizeCategories = "Parts"))
class MERGEGUN_API AGunActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGunActor();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default", meta = (DisplayPriority = "1"))
	UMergeGunWeaponComponent* Core;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Parts")
	TSubclassOf<AGunPartComponent> Barrel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Parts")
	TSubclassOf<AGunPartComponent> Sight;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Parts")
	TSubclassOf<AGunPartComponent> Grip;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Parts")
	TSubclassOf<AGunPartComponent> Stock;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
