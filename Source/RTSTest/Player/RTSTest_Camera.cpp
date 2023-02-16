// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSTest_Camera.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h" 
#include <RTSTest/Interfaces/ISelectable.h>
#include <Kismet/KismetSystemLibrary.h>
#include <RTSTest/RTSTestGameModeBase.h>

// Sets default values
ARTSTest_Camera::ARTSTest_Camera()
{
	SelectedActor = nullptr;

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("StaticCamera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ARTSTest_Camera::BeginPlay()
{
	Super::BeginPlay();
	SpringArm->SetRelativeRotation(FRotator(-55.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 1000;

}

void ARTSTest_Camera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction("LeftMouseButton", IE_Pressed, this, &ARTSTest_Camera::OnLeftMouseClick);
	PlayerInputComponent->BindAction("RightMouseButton", IE_Pressed, this, &ARTSTest_Camera::OnRightMouseClick);
}

void ARTSTest_Camera::OnLeftMouseClick()
{
	FVector StartLocation;
	FVector WorldDirection;
	FVector EndLocation;
	FRotator PlayerRotation;
	FHitResult HitResult;
	FCollisionQueryParams Params;

	// Get the camera location and direction
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->GetPlayerViewPoint(StartLocation, PlayerRotation);

	// Get the end location based on the mouse position in the world
	PlayerController->DeprojectMousePositionToWorld(EndLocation, WorldDirection);

	// Calculate the trace vector and perform the trace
	FVector TraceVector = EndLocation - StartLocation;
	Params.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, StartLocation + TraceVector * 10000.0f, ECC_Visibility, Params);

	// If an actor was hit, log its name
	AActor* HitActor = HitResult.GetActor();
	if (HitActor)
	{
		if (HitActor->Implements<USelectable>())
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *HitActor->GetName());
			UKismetSystemLibrary::DrawDebugSphere(GetWorld(), HitResult.Location, 5, 5, FLinearColor::Red, 5.f, 1.f);
			ISelectable::Execute_Select(HitActor);
		}
	}

}

void ARTSTest_Camera::OnRightMouseClick()
{
	ARTSTestGameModeBase* GameMode = Cast<ARTSTestGameModeBase>(GetWorld()->GetAuthGameMode());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Clicked!"));
	if (GameMode)
	{
		GameMode->AssignActor(nullptr);
	}
}
