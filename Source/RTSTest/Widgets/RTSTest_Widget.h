// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetBlueprint.h"
#include "RTSTest_Widget.generated.h"

/**
 * 
 */
UCLASS()
class RTSTEST_API URTSTest_Widget : public UUserWidgetBlueprint
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
	void AssignUnit(AActor* AssignedActor);
};
