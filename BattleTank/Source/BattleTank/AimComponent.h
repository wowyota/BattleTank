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
	Locked,
	OutOfAmmo
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





	UTankBarrel* Barrel;
	void MoveBarrelTowards(const FVector &AimDirection);

	UTankTurret* Turret;
	void MoveTurretTowards(const FVector &AimDirection);


	UFUNCTION(BlueprintCallable, Category = "Tank")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);





	void AimAt(const FVector &AimLocation);

	FVector AimDirection;

	// the length of vector of projectile launch velocity
	UPROPERTY(EditAnywhere, Category = "Tank")
	float LaunchSpeed = 10000.f;

	// if draw debug line when launch projectile
	UPROPERTY(EditAnywhere, Category = "Tank")
	bool bDrawDebugLineProjectileTrace = false;



	// Like a pointer, it points to what kind of projectile you want. Assign it in blueprint.
	UPROPERTY(EditAnywhere, Category = "Tank")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Time between two fire
	UPROPERTY(EditAnywhere, Category = "Tank")
	float ReloadTime = 3.f;
	UPROPERTY(EditAnywhere, Category = "Tank")
	float bCanFire = true;

	double LastFireTime = 0;

	UFUNCTION(BlueprintCallable, Category = "Tank")
	void Fire();




	UPROPERTY(EditAnywhere, Category = "Tank")
	EFiringState FiringState = EFiringState::Aiming;

	EFiringState GetFiringState() const;

	bool IsBarrelMoving();

	UPROPERTY(EditAnywhere, Category = "Tank")
	int TotalAmmo = 10;

	UPROPERTY(EditAnywhere, Category = "Tank")
	int NowAmmo; // Initialized in BeginPlay




};
