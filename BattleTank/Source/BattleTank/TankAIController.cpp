// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = Cast<ATank>(GetPawn()); 

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController possessing: %s."), *ControlledTank->GetName());
	}

	if (GetWorld())
		if (GetWorld()->GetFirstPlayerController())
			PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController cannot find player's tank."), *PlayerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController found player's tank: %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerTank || !ControlledTank || !ControlledTank->bAIOpenTick) return;

	float AcceptanceRadius = 30.f;
	// Move towards player
	
	MoveToActor(PlayerTank, AcceptanceRadius);


	// Aim at player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());

	// Fire
	ControlledTank->Fire();

}
