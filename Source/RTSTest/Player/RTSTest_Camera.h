// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RTSTest_Camera.generated.h"

UCLASS()
class RTSTEST_API ARTSTest_Camera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARTSTest_Camera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

};
