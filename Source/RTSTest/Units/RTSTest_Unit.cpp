// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSTest_Unit.h"
#include <RTSTest/RTSTestGameModeBase.h>
#include "RTSTest/Buildings/RTSTest_Building.h"

// Sets default values
ARTSTest_Unit::ARTSTest_Unit()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	AssignedBuilding = nullptr;
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


void ARTSTest_Unit::AssignBuilding(AActor* Building)
{
	ARTSTest_Building* building = Cast<ARTSTest_Building>(Building);
	if (AssignedBuilding != building)
	{
		AssignedBuilding = building;
	}
}

void ARTSTest_Unit::UnitClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("UnitClicked!"));
}

void ARTSTest_Unit::Select_Implementation()
{
	UnitClicked();

	ARTSTestGameModeBase* GameMode = Cast<ARTSTestGameModeBase>(GetWorld()->GetAuthGameMode());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Unit Clicked!"));
	if (GameMode)
	{
		GameMode->SetSelectedActor(this);
	}
}

void ARTSTest_Unit::Assign_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Unit Assigned!"));
	ARTSTestGameModeBase* GameMode = Cast<ARTSTestGameModeBase>(GetWorld()->GetAuthGameMode());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Unit Clicked!"));
	if (GameMode)
	{
		GameMode->AssignUnitToBuilding(this);
	}
}


