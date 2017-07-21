// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "AimComponent.h"
#include "CampComponent.h"
#include "TankAIController.h"
#include "Tank.h" // used in Delegate ATank.onDeath

void ATankAIController::Initialize()
{
	ControlledTank = GetPawn();
	if (ControlledTank)
	{
		AimComponent = ControlledTank->FindComponentByClass<UAimComponent>(); // Find means you add a component in BP, and then find it
	}
	PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	CampComponent = FindComponentByClass<UCampComponent>();

}

bool ATankAIController::Ensure()
{
	if (!PlayerTank || !ControlledTank || !AimComponent || !CampComponent)
	{
		if (!PlayerTank)
		{
			UE_LOG(LogTemp, Error, TEXT("%s cannot find PlayerTank."), *GetName());
		}
		if (!ControlledTank)
		{
			UE_LOG(LogTemp, Error, TEXT("%s cannot find ControlledTank."), *GetName());
		}
		if (!AimComponent)
		{
			UE_LOG(LogTemp, Error, TEXT("%s cannot find AimComponent."), *GetName());
		}
		if (!CampComponent)
		{
			UE_LOG(LogTemp, Error, TEXT("%s cannot find CampComponent."), *GetName());
		}
		return false;

	}
	else
		return true;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	Initialize();


	if (!Ensure())
	{
		return;
	}


}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Ensure())
	{
		Initialize();

		if (!Ensure())
		{
			return;
		}

	}


	// Find Enemy
	auto EnemyTank = CampComponent->FindEnemyTank();

	if (!EnemyTank)
	{
		UE_LOG(LogTemp, Error, TEXT("%s cannot find EnemyTank."), *GetName());
		return;
	}

	// Move towards Enemy
	MoveToActor(EnemyTank, AcceptanceRadius);	

	if (!EnemyTank) return;
	// Aim at EnemyTank
	AimComponent->AimAt(EnemyTank->GetActorLocation());

	// Fire
	if(AimComponent->GetFiringState() == EFiringState::Locked)
		AimComponent->Fire();

	//UE_LOG(LogTemp, Warning, TEXT("GetFiringState."), *GetName(), *ControlledTank->GetName());


}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!PossessedTank)return;

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
	}

}

void ATankAIController::OnPossedTankDeath()
{

	if (!Ensure())
	{
		Initialize();

		if (!Ensure())
		{
			return;
		}
	}

	ControlledTank->DetachFromControllerPendingDestroy();
	UE_LOG(LogTemp, Warning, TEXT("%s die."), *GetName());

}

