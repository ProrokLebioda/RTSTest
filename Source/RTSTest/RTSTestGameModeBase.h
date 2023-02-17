// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

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
	class URTSTest_UserWidget* BuildingWidget;

	void UpdateAssignedActor(AActor* AssignedActor);

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	AActor* Selected;
	void AssignActor(AActor* AssignedActor);
public:
	void SetSelectedActor(AActor* SelectedActor);
	void AssignUnitToBuilding(AActor* Unit);
};
