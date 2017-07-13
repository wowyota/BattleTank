// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = Tank)
	float MaxDegreesPerSecond = 2.f;
	
public:

	// -1 is max downward speed, +1 is max upward
	// And it makes the speed slow down(which provides good animation effect) when RelativeSpeed come close to 0
	void Rotate(float RelativeSpeed);
	
};
