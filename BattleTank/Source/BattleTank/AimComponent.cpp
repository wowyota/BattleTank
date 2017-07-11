// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
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

void UAimComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UAimComponent::AimAt(const FVector &AimLocation)
{
	if (!Barrel)
		return;

	FVector TossVelocity; // Out parameter
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FVector EndLocation = AimLocation;
	float TossSpeed = LaunchSpeed;
	bool bDrawDebug = true;
	// For more detail, see https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Kismet/UGameplayStatics/SuggestProjectileVelocity/index.html and https://docs.unrealengine.com/latest/INT/BlueprintAPI/Game/Components/ProjectileMovement/SuggestProjectileVelocity/index.html
	UGameplayStatics::SuggestProjectileVelocity(
		this,
		TossVelocity,
		StartLocation,
		EndLocation,
		LaunchSpeed,
		false,
		0.0f, // Default parameter value
		0.0f, // Default parameter value
		ESuggestProjVelocityTraceOption::DoNotTrace, // Default parameter value
		FCollisionResponseParams::DefaultResponseParam, // Default parameter value
		TArray<AActor*>(), // Default parameter value
		DrawDebugLineProjectileTrace // Draw debug line
	);
	UE_LOG(LogTemp, Warning, TEXT("%s is aimming at location %s  from  %s."), *GetOwner()->GetName(), *AimLocation.ToString(), *Barrel->GetComponentLocation().ToString());
}
