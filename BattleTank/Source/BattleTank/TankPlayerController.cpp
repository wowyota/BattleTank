// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController possessing: %s."), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

	UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController ticking."));

	FVector HitLocation;
	if(GetSightRayHitLocation(HitLocation))
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s."), *HitLocation.ToString());


}

void ATankPlayerController::AimTowardsCrosshair()
{

	if (!GetControlledTank()) return;
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	FVector LookDirection;
	if (GetLookDirection(LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("LookDirection: %s."), *LookDirection.ToString());
		/// linetrace along that look direction
	}

	HitLocation = FVector(1.0f);
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector &LookDirection) const
{
	/// Find the crosshair postion in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY*CrosshairYLocation);

	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s."), *ScreenLocation.ToString());

	/// "De-project" the screen positon of the crosshair to a world direction
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection
	);
}

bool ATankPlayerController::GetLookHitLocation(const FVector &LookDirection, FVector &HitLocation) const
{
	FHitResult Hit;
	FVector Start = 
	GetWorld()->LineTraceSingleByChannel(Hit,)
	// TODO
}