// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"

#include "Projectile.h"
#include "TankBarrel.h"

#include "AimComponent.generated.h"

UENUM()
enum class EFiringState :uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	void AimAt(const FVector &AimLocation);


	/// about Barrel
	UTankBarrel* Barrel;
	void MoveBarrelTowards(const FVector &AimDirection);

	/// about Turret
	UTankTurret* Turret;
	void MoveTurretTowards(const FVector &AimDirection);

	UPROPERTY(BlueprintReadOnly, Category = "Tank")
	EFiringState FiringState = EFiringState::Aiming;


	UFUNCTION(BlueprintCallable, Category = "Tank")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);


	UPROPERTY(EditAnywhere, Category = Tank)
	float LaunchSpeed = 10000.f;

	UPROPERTY(EditAnywhere, Category = Tank)
	bool bDrawDebugLineProjectileTrace = false;





	// Treat this like a class 
	UPROPERTY(EditAnywhere, Category = Tank)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnywhere, Category = Tank)
		float ReloadTime = 3.f;
	UPROPERTY(EditAnywhere, Category = Tank)
		float bCanFire = true;

	double LastFireTime = 0;

	UPROPERTY(EditAnywhere, Category = "Tank")
		float MaxForce = 40000000.f;





	UFUNCTION(BlueprintCallable, Category = Tank)
		void Fire();

};
