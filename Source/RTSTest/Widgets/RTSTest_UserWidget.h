// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RTSTest_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class RTSTEST_API URTSTest_UserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void ChangeAssignedActor(AActor* AssignedActor);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActor* AssignedUnit;
};
