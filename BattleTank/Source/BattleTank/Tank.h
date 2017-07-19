// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Keep this line at last include


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called by engine when actor damage is dealt
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(EditAnywhere,Category = "Tank")
	int32 StartHealth = 100.f;

	UPROPERTY(EditAnywhere, Category = "Tank")
	int32 CurrentHealth; // Initialized in BeignPlay

	UFUNCTION(BlueprintPure, Category = "Tank")
	float GetHealthPercent() const;



	FTankDelegate OnDeath;






};
