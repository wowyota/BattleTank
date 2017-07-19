// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LaunchProjectile(const float Speed) const;



	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere,Category = "Tank")
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Tank")
	UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Tank")
	UParticleSystemComponent* ImpactBlast = nullptr;
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& HitResult);

	void OnTimerExpire();

	UPROPERTY(VisibleAnywhere, Category = "Tank")
	URadialForceComponent* ExplosionForce = nullptr;

	UPROPERTY(EditAnywhere, Category = "Tank")
	float DestroyDelay = 10.f;

	UPROPERTY(EditAnywhere, Category = "Tank")
	float ProjectileDamage = 20.f;


	UFUNCTION(BlueprintImplementableEvent, Category = "Tank")
	void PlayBlastSound();

	UFUNCTION(BlueprintImplementableEvent, Category = "Tank")
	void PlayLaunchSound();
};
