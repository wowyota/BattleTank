// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	FMath::Clamp<float>(RelativeSpeed, -1, +1);

	float Angle = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds + this->RelativeRotation.Pitch;
	
	Angle = FMath::Clamp<float>(Angle, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(Angle, 0.f, 0.f));
}


