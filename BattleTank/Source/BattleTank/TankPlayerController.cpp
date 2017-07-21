// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "AimComponent.h"
#include "CampComponent.h"
#include "TankPlayerController.h"
#include "Tank.h" // used in Delegate ATank.onDeath

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	CampComponent = GetPawn()->FindComponentByClass<UCampComponent>();

	AimComponent = GetPawn()->FindComponentByClass<UAimComponent>();


	SetPlayerUI();

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardsCrosshair();

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!AimComponent) return;

	// If player or AI die
	if (!GetPawn()) return;

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		AimComponent->AimAt(HitLocation);
	}


}

// Get world location of linetrace through crosshair, true if hits landscape or tank or something else.
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	FVector LookDirection;
	if (GetLookDirection(LookDirection))
	{
		if (GetLookHitLocation(LookDirection, HitLocation))
		{
			return true;
		}
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector &LookDirection) const
{
	/// Find the crosshair postion in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY*CrosshairYLocation);


	/// "De-project" the screen positon of the crosshair to a world direction
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection
	);
}

// According LookDirection, apply line trace, if hits then return true and modify HitLocation 
bool ATankPlayerController::GetLookHitLocation(const FVector &LookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start + LookDirection.GetSafeNormal() * LineTraceDistance;
	bool IsHitAnything;
	IsHitAnything = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECollisionChannel::ECC_Camera
	);
	HitLocation = HitResult.Location;
	return IsHitAnything;
}

void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!PossessedTank)return;

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossedTankDeath);
	}

}

void ATankPlayerController::OnPossedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("%s die."), *GetName());

	// Player cannot control tank anymore
	StartSpectatingOnly();


}
