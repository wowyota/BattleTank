// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AimComponent.generated.h"

class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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

	UPROPERTY(EditAnywhere, Category = Tank)
	float LaunchSpeed = 10000.f;

	UPROPERTY(EditAnywhere, Category = Tank)
	bool bDrawDebugLineProjectileTrace = false;


	UTankBarrel* Barrel;
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void MoveBarrelTowards(const FVector &AimDirection);
	void AimAt(const FVector &AimLocation);
};
