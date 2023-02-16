// Copyright Epic Games, Inc. All Rights Reserved.


#include "RTSTestGameModeBase.h"
#include "Widgets/RTSTest_UserWidget.h"

void ARTSTestGameModeBase::BeginPlay()
{
	if (BuildingWidgetClass)
	{
		BuildingWidget = Cast<URTSTest_UserWidget>(CreateWidget(GetWorld(), BuildingWidgetClass));

		if (BuildingWidget)
		{
			AssignActor(nullptr);
		}
	}
}

void ARTSTestGameModeBase::UpdateAssignedActor(AActor* AssignedActor)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Selected!"));
	BuildingWidget->ChangeAssignedActor(AssignedActor);
	
	
	if (AssignedActor != nullptr && !BuildingWidget->IsInViewport())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Assigning TRUE!"));
		BuildingWidget->AddToViewport();
	}
	else if (BuildingWidget->IsInViewport())
	{
		
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Assigning FALSE!"));
		BuildingWidget->RemoveFromViewport();
	}
}


void ARTSTestGameModeBase::AssignActor(AActor* AssignedActor)
{
	UpdateAssignedActor(AssignedActor);
}
