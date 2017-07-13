// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "AimComponent.h"
#include "Tank.h"


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
	GetWorld()->SpawnActor<AProjectile>	(
		Projectile, 
		Barrel->GetSocketLocation(FName("Projectile")),
		FRotator::ZeroRotator
		);

	UE_LOG(LogTemp, Warning, TEXT("%f: Fire."), GetWorld()->GetTimeSeconds());

}
