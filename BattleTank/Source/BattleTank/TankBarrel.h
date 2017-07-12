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
	float MaxDegreesPerSecond = 20.f;	
	UPROPERTY(EditAnywhere, Category = Tank)
	float MaxElevationDegrees = 40.f;	
	UPROPERTY(EditAnywhere, Category = Tank)
	float MinElevationDegrees = 0.f;

public:
	void Elevate(float DegreesPerSecond);
	
};
