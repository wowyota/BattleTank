// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
	LaunchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
	ImpactBlast->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
	ImpactBlast->bAutoActivate = false;

	ExplosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("Explosion Force"));
	ExplosionForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	ProjectileMovement->bAutoActivate = false; // Set to false then it won't move when spawning, until we set it to true in Fire()
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	PlayLaunchSound();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & HitResult)
{
	ImpactBlast->Activate();
	PlayBlastSound();
	LaunchBlast->Deactivate();

	// OutComponents[1] is the outlook of projectile
	TArray<UStaticMeshComponent*> OutComponents;
	GetComponents(OutComponents);	
	if(OutComponents[1])
		OutComponents[1]->SetVisibility(false);
	


	// Explosion causes movement
	ExplosionForce->FireImpulse();

	// Prepare to destroy self
	SetRootComponent(ImpactBlast);
	CollisionMesh->DestroyComponent();

	// Apply damage
	UGameplayStatics::ApplyRadialDamage(
		this,
		ProjectileDamage,
		GetActorLocation(),
		ExplosionForce->Radius, // for consistancy
		UDamageType::StaticClass(),
		TArray<AActor *>() // damage all actors	 
	);

	
	// Destory self after DestroyDelay second.
	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &AProjectile::OnTimerExpire, DestroyDelay, false);
}

void AProjectile::OnTimerExpire()
{
	Destroy();
}
void AProjectile::LaunchProjectile(const float Speed) const 
{
	//GetWorld()->GetTimeSeconds(); // this line crash???
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();

}

