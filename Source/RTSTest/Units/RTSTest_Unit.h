// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RTSTest_Unit.generated.h"

UCLASS()
class RTSTEST_API ARTSTest_Unit : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARTSTest_Unit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

	UFUNCTION()
	void UnitClicked();
};
