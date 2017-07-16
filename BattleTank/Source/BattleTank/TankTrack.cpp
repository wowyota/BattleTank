// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankTrack.h"

void UTankTrack::BeginPlay()
{
	TankRootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
}

void UTankTrack::SetThrottle(float Throttle)
{
	// Keep it here! or Crash! I think it's because SetThrottle gets call before 'this' construction(we I say 'this', it means "this object TankTrack")
	if (!this) return;

	if (!TankRootComponent) return;

	auto ForceApplied = GetForwardVector() * Throttle * MaxForce;
	auto ForceLocation = GetComponentLocation();
	TankRootComponent->AddForceAtLocation(ForceApplied, ForceLocation);

}

