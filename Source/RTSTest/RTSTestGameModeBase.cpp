// Copyright Epic Games, Inc. All Rights Reserved.


#include "RTSTestGameModeBase.h"

void ARTSTestGameModeBase::UpdateAssignedActor(AActor& AssignedActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Selected!"));
}

void ARTSTestGameModeBase::AssignActor(AActor& AssignedActor)
{
	UpdateAssignedActor(AssignedActor);
}
