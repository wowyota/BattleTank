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

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	AimComponent = FindComponentByClass<UAimComponent>();
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
