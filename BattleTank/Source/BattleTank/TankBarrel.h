// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"
 
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category = Tank)
	float MaxDegreesPerSecond = 5.f;	
	UPROPERTY(EditAnywhere, Category = Tank)
	float MaxElevationDegrees = 40.f;	
	UPROPERTY(EditAnywhere, Category = Tank)
	float MinElevationDegrees = 0.f;

public:

	// -1 is max downward speed, +1 is max upward
	// And it makes the speed slow down(which provides good animation effect) when RelativeSpeed come close to 0
	void Elevate(float RelativeSpeed);
	
};
