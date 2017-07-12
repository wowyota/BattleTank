// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();

	UFUNCTION(BlueprintCallable, Category = Tank)
	bool GetSightRayHitLocation(FVector &HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;
	
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 1.0f / 3.0f;

	UPROPERTY(EditAnywhere)
	float LineTraceDistance = 1000000.0f;

	bool GetLookDirection(FVector &LookDirection) const;

	bool GetLookHitLocation(const FVector &LookDirection, FVector &HitLocation) const;

};
