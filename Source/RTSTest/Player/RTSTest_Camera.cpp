// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSTest_Camera.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h" 
#include <RTSTest/Interfaces/ISelectable.h>
#include <Kismet/KismetSystemLibrary.h>

// Sets default values
ARTSTest_Camera::ARTSTest_Camera()
{
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
	// Bind fire event
	PlayerInputComponent->BindAction("LeftMouseButton", IE_Pressed, this, &ARTSTest_Camera::OnLeftMouseClick);
}

void ARTSTest_Camera::OnLeftMouseClick()
{
	/*FVector StartLocation;
	FVector EndLocation;
	GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(StartLocation, EndLocation);

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, Params);

	AActor* HitActor = HitResult.GetActor();
	if (HitActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *HitActor->GetName());
		UKismetSystemLibrary::DrawDebugSphere(GetWorld(), HitResult.Location, 5, 5, FLinearColor::Red, 5.f, 1.f);
	}*/

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
