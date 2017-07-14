// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "AimComponent.h"


// Sets default values for this component's properties
UAimComponent::UAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAimComponent::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(GetOwner());
	// ...
	
}


// Called every frame
void UAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimComponent::AimAt(const FVector &AimLocation)
{
	if (!Tank || !Barrel || !Turret)
		return;

	FVector TossVelocity; // Out parameter, its VectorLength is gonna to be LaunchSpeed.
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FVector EndLocation = AimLocation;
	float TossSpeed = Tank->LaunchSpeed;
	bool bDrawDebug = true;

	// For more detail, see https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Kismet/UGameplayStatics/SuggestProjectileVelocity/index.html and https://docs.unrealengine.com/latest/INT/BlueprintAPI/Game/Components/ProjectileMovement/SuggestProjectileVelocity/index.html
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		TossVelocity,
		StartLocation,
		EndLocation,
		Tank->LaunchSpeed,
		false,  // Default parameter value
		0.0f, // Default parameter value
		0.0f, // Default parameter value
		ESuggestProjVelocityTraceOption::DoNotTrace, // Default parameter value
		FCollisionResponseParams::DefaultResponseParam, // Default parameter value
		TArray<AActor*>(), // Default parameter value
		Tank->bDrawDebugLineProjectileTrace // Draw debug line
	);

	FVector AimDirection = TossVelocity.GetSafeNormal();
	MoveBarrelTowards(AimDirection);
	MoveTurretTowards(AimDirection);

	if (bHaveAimSolution)
	{

		FVector AimDirection = TossVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		MoveTurretTowards(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("%f: Solution found."), GetWorld()->GetTimeSeconds());
	}
	else
	{
		// The code couldn't run into this else branch.
		UE_LOG(LogTemp, Warning, TEXT("%f: No solution."), GetWorld()->GetTimeSeconds());
	}

	UE_LOG(LogTemp, Warning, TEXT("hi."));
}


void UAimComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Calculate the difference between current barrel rotation and AimDirection
// If the difference is not 0, then Barrel's moving speed is not 0 either.
void UAimComponent::MoveBarrelTowards(const FVector &AimDirection)
{
	/// Calculate
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;
	
	// Move
	Barrel->Elevate(DeltaRotator.Pitch);
}


void UAimComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
}

// Calculate the difference between current Turret rotation and AimDirection
// If the difference is not 0, then Turret's moving speed is not 0 either.
void UAimComponent::MoveTurretTowards(const FVector &AimDirection)
{
	/// Calculate
	FRotator TurretRotator = Turret->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - TurretRotator;

	// Move
	Turret->Rotate(DeltaRotator.Yaw);
}

