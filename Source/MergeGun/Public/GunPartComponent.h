// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunPartComponent.generated.h"


UENUM(BlueprintType)
enum class EGunPartType : uint8
{
	Barrel	UMETA(DisplayName = "Barrel"),
	Sight	UMETA(DisplayName = "Sight"),
	Grip	UMETA(DisplayName = "Grip"),
	Stock	UMETA(DisplayName = "Stock")
};

UCLASS()
class MERGEGUN_API AGunPartComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunPartComponent();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UStaticMeshComponent* PartMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	EGunPartType PartType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	class UGunStats* PartStats;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
