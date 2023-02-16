// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSTest_Selectable.h"

// Sets default values for this component's properties
URTSTest_Selectable::URTSTest_Selectable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void URTSTest_Selectable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


//// Called every frame
//void URTSTest_Selectable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

