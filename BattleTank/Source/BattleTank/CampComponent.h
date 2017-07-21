// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CampComponent.generated.h"

UENUM(BlueprintType)
enum class ECamp :uint8
{
	A UMETA(DisplayName = "A"),
	B UMETA(DisplayName = "B"),
	C UMETA(DisplayName = "C")
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UCampComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCampComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = "Tank")
	ECamp SelfCamp = ECamp::A;

	UFUNCTION(BlueprintCallable, Category = "Tank")
	ECamp GetSelfCamp() const { return SelfCamp; }

	UFUNCTION(BlueprintCallable, Category = "Tank")
	void SetSelfCamp(ECamp CampToSet) { SelfCamp = CampToSet; }

	UPROPERTY(EditAnywhere, Category = "Tank")
	ECamp EnemyCamp = ECamp::B; // TODO make it array to find multi camp enemy	

	UFUNCTION(BlueprintCallable, Category = "Tank")
	ECamp GetEnemyCamp() const { return EnemyCamp; }

	UFUNCTION(BlueprintCallable, Category = "Tank")
	void SetEnemyCamp(ECamp CampToSet) { EnemyCamp = CampToSet; }

	UFUNCTION(BlueprintCallable, Category = "Tank")
	APawn* FindEnemyTank(); 
	
};
