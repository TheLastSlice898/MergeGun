// Fill out your copyright notice in the Description page of Project Settings.


#include "GunActor.h"

// Sets default values
AGunActor::AGunActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BarrelMesh"));
	SightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SightMesh"));
	GripMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GripMesh"));
	ForgripMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ForgripMesh"));
	StockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StockMesh"));

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));

	BarrelMesh->SetupAttachment(GunMesh, TEXT("Barrel"));
	SightMesh->SetupAttachment(GunMesh,TEXT("Sight"));
	GripMesh->SetupAttachment(GunMesh,TEXT("Grip"));
	// ForgripMesh->SetupAttachment(GunMesh,TEXT("ForeGrip"));
	StockMesh->SetupAttachment(GunMesh, TEXT("Stock"));

}

// Called when the game starts or when spawned
void AGunActor::BeginPlay()
{
	
	
}

// Called every frame
void AGunActor::Tick(float DeltaTime)
{
	

}

