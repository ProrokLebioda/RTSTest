// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Widgets/RTSTest_Widget.h"
#include "RTSTestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class RTSTEST_API ARTSTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<class UUserWidget> BuildingWidgetClass;

	UPROPERTY()
	URTSTest_Widget* BuildingWidget;

	void UpdateAssignedActor(AActor& AssignedActor);

public:
	void AssignActor(AActor& AssignedActor);
};
