// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ATank;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Tank")
	void SetThrottle(float Throttle);
	
	ATank* Tank;
	UPrimitiveComponent* TankRootComponent;

	// Max accelatation
	UPROPERTY(EditAnywhere, Category = "Tank")
	float MaxForce = 40000000.f; 
	
	UPROPERTY(EditAnywhere, Category = "Tank")
	float MaxSpeed = 10000.f; 

};
