// Copyright Epic Games, Inc. All Rights Reserved.


#include "RTSTestGameModeBase.h"
#include "RTSTest/Buildings/RTSTest_Building.h"
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
	
	
	if (AssignedActor != nullptr )
	{
		if (Cast<ARTSTest_Building>(AssignedActor))
		{
			if (!BuildingWidget->IsInViewport())
				BuildingWidget->AddToViewport();
		}
		else 
		{
			if (BuildingWidget->IsInViewport())
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Building TRUE!"));
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Assigning TRUE!"));
				BuildingWidget->RemoveFromViewport();
			}
		}
	}
	else if (BuildingWidget->IsInViewport())
	{
		
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Assigning FALSE!"));
		if (BuildingWidget->IsInViewport())
			BuildingWidget->RemoveFromViewport();
	}
}


void ARTSTestGameModeBase::SetSelectedActor(AActor* SelectedActor)
{
	Selected = SelectedActor;
	AssignActor(SelectedActor);
}

void ARTSTestGameModeBase::AssignActor(AActor* AssignedActor)
{
	UpdateAssignedActor(AssignedActor);
}
