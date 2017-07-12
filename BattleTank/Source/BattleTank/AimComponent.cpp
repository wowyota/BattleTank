// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
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

	// ...
	
}


// Called every frame
void UAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UAimComponent::AimAt(const FVector &AimLocation)
{
	if (!Barrel)
		return;

<<<<<<< HEAD
=======
	// For more detail, see https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Kismet/UGameplayStatics/SuggestProjectileVelocity/index.html and https://docs.unrealengine.com/latest/INT/BlueprintAPI/Game/Components/ProjectileMovement/SuggestProjectileVelocity/index.html
>>>>>>> origin/master
	FVector TossVelocity; // Out parameter
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FVector EndLocation = AimLocation;
	float TossSpeed = LaunchSpeed;
	bool bDrawDebug = true;
<<<<<<< HEAD
	// For more detail, see https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Kismet/UGameplayStatics/SuggestProjectileVelocity/index.html and https://docs.unrealengine.com/latest/INT/BlueprintAPI/Game/Components/ProjectileMovement/SuggestProjectileVelocity/index.html
=======
>>>>>>> origin/master
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		TossVelocity,
		StartLocation,
		EndLocation,
		LaunchSpeed,
<<<<<<< HEAD
		false,  // Default parameter value
		0.0f, // Default parameter value
		0.0f, // Default parameter value
		ESuggestProjVelocityTraceOption::DoNotTrace, // Default parameter value
		FCollisionResponseParams::DefaultResponseParam, // Default parameter value
		TArray<AActor*>(), // Default parameter value
=======
		//false, // Default parameter value
		//0.0f, // Default parameter value
		//0.0f, // Default parameter value
		ESuggestProjVelocityTraceOption::DoNotTrace,
		//FCollisionResponseParams::DefaultResponseParam, // Default parameter value
		//TArray<AActor*>(), // Default parameter value
>>>>>>> origin/master
		bDrawDebugLineProjectileTrace // Draw debug line
	);

	if (bHaveAimSolution)
	{
<<<<<<< HEAD
		UE_LOG(LogTemp, Warning, TEXT("%f: Solution found."), GetWorld()->GetTimeSeconds());
		
		FVector AimDirection = TossVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%f: No solution."), GetWorld()->GetTimeSeconds());

	}


}

void UAimComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
=======
		UE_LOG(LogTemp, Warning, TEXT("%s is aimming at location %s  from  %s."), *GetOwner()->GetName(), *AimLocation.ToString(), *Barrel->GetComponentLocation().ToString());
	}
}

void UAimComponent::MoveBarrelTowards(const FVector &AimDirection)
>>>>>>> origin/master
{
	// cal difference between current barrel rotation and AimDirection
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;



	// move the barrel the right amount rotation at this frame

	// given a max elevation speed and the frame time
}

<<<<<<< HEAD
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

	// given a max elevation speed and the frame time
}

=======
>>>>>>> origin/master
