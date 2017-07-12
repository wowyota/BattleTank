// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Keep this line at last include

class UTankBarrel;
class UAimComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UAimComponent* AimComponent;

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetBarrelReference(UTankBarrel* BarrelToSet);


public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void AimAt(const FVector &AimLocation);

};
