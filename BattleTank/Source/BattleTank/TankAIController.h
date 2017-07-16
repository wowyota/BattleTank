// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
class UAimComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	// Controller ticks because it needs to find the player location
	virtual void Tick(float DeltaTime) override;

	ATank* ControlledTank;
	ATank* PlayerTank;

	UPROPERTY(EditDefaultsOnly, Category = Tank)
	bool bAIOpenTick = true;
};
