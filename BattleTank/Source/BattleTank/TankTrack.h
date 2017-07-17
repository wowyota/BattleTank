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

	UFUNCTION(BlueprintCallable, Category = "Tank")
	void SetThrottle(float Throttle);

	float CurrentThrottle = 0;;
	void DriveTrack();


	UPrimitiveComponent* TankRootComponent;

	// Max accelatation
	UPROPERTY(EditAnywhere, Category = "Tank")
	float MaxForce = 40000000.f; 
	
	UPROPERTY(EditAnywhere, Category = "Tank")
	float MaxSpeed = 10000.f; 

private:
	UTankTrack();

	// If you override BeginPlay, if may stop tick woring.
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AntiSlippage();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& HitResult);
};
