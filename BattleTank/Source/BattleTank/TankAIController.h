// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

// UENUM()
// enum class ECamp :uint8
// {
// 	A,
// 	B
// };


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

	APawn* ControlledTank;
	APawn* PlayerTank;
	UAimComponent* AimComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Tank")
	bool bAIOpenTick = true;


	// TODO make it flexible, every AI keep different value
	UPROPERTY(EditAnywhere, Category = "Tank")
	float AcceptanceRadius = 30.f;

	// It's called when the Pawn gets possessed.
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossedTankDeath();


	// TODO divide camp
	//UPROPERTY(EditAnywhere, Category = "Tank")
	//ECamp Camp = ECamp::A;

	// TODO make it work, so that AI can attack AI
	//UFUNCTION(BlueprintCallable,Category = "Tank")
	//APawn* FindEnemyTank(ECamp EnemyCamp);

};
