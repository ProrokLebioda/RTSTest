// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSTest_Building.h"
#include <RTSTest/RTSTestGameModeBase.h>
#include "RTSTest/Units/RTSTest_Unit.h"

// Sets default values
ARTSTest_Building::ARTSTest_Building()
{
	PrimaryActorTick.bCanEverTick = false;
	AssignedUnit = nullptr;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

void ARTSTest_Building::BeginPlay()
{
	Super::BeginPlay();

	
}

void ARTSTest_Building::AssignUnit(AActor* Unit)
{
	ARTSTest_Unit* unit = Cast<ARTSTest_Unit>(Unit);
	if (AssignedUnit != unit)
	{
		AssignedUnit = unit;
	}
}

void ARTSTest_Building::Select_Implementation()
{
	ARTSTestGameModeBase* GameMode = Cast<ARTSTestGameModeBase>(GetWorld()->GetAuthGameMode());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Building Clicked!"));
	if (GameMode)
	{
		GameMode->SetSelectedActor(this);
	}
}

