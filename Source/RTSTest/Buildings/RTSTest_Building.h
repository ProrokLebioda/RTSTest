// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <RTSTest/Interfaces/ISelectable.h>
#include "RTSTest_Building.generated.h"

UCLASS()
class RTSTEST_API ARTSTest_Building : public AActor, public ISelectable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARTSTest_Building();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class ARTSTest_Unit* AssignedUnit;

	UFUNCTION()
	void AssignUnit(AActor* Unit);

	void Select_Implementation();
};
