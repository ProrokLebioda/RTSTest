// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <RTSTest/Interfaces/ISelectable.h>
#include <RTSTest/Interfaces/IAssignable.h>
#include "RTSTest_Unit.generated.h"


UCLASS()
class RTSTEST_API ARTSTest_Unit : public APawn, public ISelectable, public IAssignable
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARTSTest_Unit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class ARTSTest_Building* AssignedBuilding;

	UFUNCTION(BlueprintCallable)
	void AssignBuilding(AActor* Building);

	UFUNCTION()
	void UnitClicked();

	void Select_Implementation();
	void Assign_Implementation();
};
