// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IAssignable.generated.h"


UINTERFACE(MinimalAPI)
class UAssignable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RTSTEST_API IAssignable
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Control")
	void Assign();
};
