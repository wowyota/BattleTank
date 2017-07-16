// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankTrack.h"

void UTankTrack::BeginPlay()
{
	Tank = Cast<ATank>(GetOwner());
	TankRootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
}

void UTankTrack::SetThrottle(float Throttle)
{
	if (!Tank || !TankRootComponent) return;

	if (Tank->GetVelocity().Size()>MaxSpeed) return;
	auto ForceApplied = GetForwardVector() * Throttle * Tank->MaxForce;
	auto ForceLocation = GetComponentLocation();
	TankRootComponent->AddForceAtLocation(ForceApplied, ForceLocation);

	
}

