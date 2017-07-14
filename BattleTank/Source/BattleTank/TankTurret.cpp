// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	FMath::Clamp<float>(RelativeSpeed, -1, +1);

	float Angle = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds + this->RelativeRotation.Yaw;
	
	SetRelativeRotation(FRotator( 0.f, Angle, 0.f));
}
