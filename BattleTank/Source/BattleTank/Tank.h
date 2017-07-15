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

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly,Category = "Tank")
	UAimComponent* AimComponent; 

	UTankBarrel* Barrel;

	// Treat this like a class 
	UPROPERTY(EditAnywhere, Category = Tank)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnywhere, Category = Tank)
	float LaunchSpeed = 10000.f;

	UPROPERTY(EditAnywhere, Category = Tank)
	float ReloadTime = 3.f;
	UPROPERTY(EditAnywhere, Category = Tank)
	float bCanFire = true;

	double LastFireTime = 0;

	UPROPERTY(EditAnywhere, Category = "Tank")
	float MaxForce = 40000000.f;


	UPROPERTY(EditAnywhere, Category = Tank)
	bool bDrawDebugLineProjectileTrace = false;

	UPROPERTY(EditDefaultsOnly, Category = Tank)
	bool bAIOpenTick = true;

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void Fire();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void AimAt(const FVector &AimLocation);


};
