// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSTest_Building.h"

// Sets default values
ARTSTest_Building::ARTSTest_Building()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void ARTSTest_Building::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARTSTest_Building::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

