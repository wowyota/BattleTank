// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController possessing: %s."), *ControlledTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();
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

	if (GetPlayerTank())
	{
		// TODO Move towards player

		// Aim at player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire
	}
}


ATank* ATankAIController::GetPlayerTank() const
{
	if (GetWorld())
		if(GetWorld()->GetFirstPlayerController())
			return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	return nullptr;
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}