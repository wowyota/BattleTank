// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "AimComponent.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = GetPawn(); 
	PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	AimComponent = GetPawn()->FindComponentByClass<UAimComponent>();

	if (!PlayerTank || !ControlledTank || !AimComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("ATankAIController cannot find AimComponent, PlayerTank or ControlledTank."), *PlayerTank->GetName());
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerTank || !ControlledTank || !AimComponent)
		return;

	
	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius);

	// Aim at player
	AimComponent->AimAt(PlayerTank->GetActorLocation());

	// Fire
	if(AimComponent->GetFiringState() == EFiringState::Locked)
		AimComponent->Fire();

}
