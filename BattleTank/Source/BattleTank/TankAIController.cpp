// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

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

	auto PlayerTank = FindPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController cannot find player's tank."), *PlayerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController found player's tank: %s"), *PlayerTank->GetName());
	}
}


ATank* ATankAIController::FindPlayerTank() const
{
	if (GetWorld())
		if(GetWorld()->GetFirstPlayerController())
			return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	return nullptr;
}
