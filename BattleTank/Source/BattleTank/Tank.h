// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Keep this line at last include

class UTankBarrel;
class UAimComponent;
class AProjectile;


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

	UPROPERTY(EditAnywhere, Category = Tank)
	TSubclassOf<AProjectile> Projectile;

	UTankBarrel* Barrel;

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void Fire();




public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void AimAt(const FVector &AimLocation);

};
