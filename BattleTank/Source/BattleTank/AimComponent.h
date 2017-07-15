// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
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
class ATank;

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

	ATank* Tank;

	void AimAt(const FVector &AimLocation);


	/// about Barrel
	UTankBarrel* Barrel;
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void MoveBarrelTowards(const FVector &AimDirection);

	/// about Turret
	UTankTurret* Turret;
	void SetTurretReference(UTankTurret* TurretToSet);
	void MoveTurretTowards(const FVector &AimDirection);

	UPROPERTY(BlueprintReadOnly, Category = "Tank")
	EFiringState FiringState = EFiringState::Aiming;
};
