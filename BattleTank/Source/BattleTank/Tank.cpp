// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "AimComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	AimComponent = CreateDefaultSubobject<UAimComponent>(FName("AimComponent"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(const FVector &AimLocation)
{
	AimComponent->AimAt(AimLocation);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
	AimComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	AimComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	if (!Barrel || !AimComponent) return;

	double NowTime = FPlatformTime::Seconds();
	bCanFire = (NowTime - LastFireTime) > ReloadTime;
	if (!bCanFire) return;

	auto Projectile = GetWorld()->SpawnActor<AProjectile>	(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		);

	Projectile->LaunchProjectile(LaunchSpeed);

	LastFireTime = NowTime;
}
