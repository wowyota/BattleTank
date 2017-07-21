// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UAimComponent;
class UCampComponent;
class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;



	void AimTowardsCrosshair();

	UFUNCTION(BlueprintCallable, Category = Tank)
	bool GetSightRayHitLocation(FVector &HitLocation) const;

	UPROPERTY(EditDefaultsOnly, Category = Tank)
	float CrosshairXLocation = 0.5;
	
	UPROPERTY(EditDefaultsOnly, Category = Tank)
	float CrosshairYLocation = 1.0f / 3.0f;

	UPROPERTY(EditAnywhere, Category = Tank)
	float LineTraceDistance = 1000000.0f;

	bool GetLookDirection(FVector &LookDirection) const;

	bool GetLookHitLocation(const FVector &LookDirection, FVector &HitLocation) const;



	UAimComponent* AimComponent;
	UCampComponent* CampComponent;

	// If we found AimComponent, then we will set UI (of course in blueprint) 
	UFUNCTION(BlueprintImplementableEvent, Category = "Tank")
	void SetPlayerUI();


	// It's called when the Pawn gets possessed.
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossedTankDeath();
};
