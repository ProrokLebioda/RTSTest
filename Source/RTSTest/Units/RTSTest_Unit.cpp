// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSTest_Unit.h"

// Sets default values
ARTSTest_Unit::ARTSTest_Unit()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void ARTSTest_Unit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARTSTest_Unit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARTSTest_Unit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

