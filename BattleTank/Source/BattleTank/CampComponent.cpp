// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "CampComponent.h"
#include "Tank.h"


// Sets default values for this component's properties
UCampComponent::UCampComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCampComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCampComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

APawn* UCampComponent::FindEnemyTank()
{
	// Indexed Container Iterator
	// conversion to "bool" returning true if the iterator has not reached the last element.
	auto PawnIterator = GetWorld()->GetPawnIterator();
	
	ATank* UnknownTank = nullptr;
	AController* UnKnownController = nullptr;
	UCampComponent* UnknownCampComponent = nullptr;

	for (; PawnIterator; PawnIterator++)
	{

		if (PawnIterator) 
		{
			UnKnownController = (*PawnIterator)->GetController();

			if (UnKnownController)
			{
				UnknownCampComponent = UnKnownController->FindComponentByClass<UCampComponent>();

				if (UnknownCampComponent)
				{

					if (UnknownCampComponent->SelfCamp == EnemyCamp)
					{
						UE_LOG(LogTemp, Warning, TEXT("%s is my enemy"), *(*PawnIterator)->GetName());
						UnknownTank = Cast<ATank>(*PawnIterator);
						if (UnknownTank && UnknownTank->CurrentHealth > 0)
						{
							UE_LOG(LogTemp, Warning, TEXT("I am %s, my enemy %s"), *GetOwner()->GetName(), *(*PawnIterator)->GetName());
							return UnknownTank;
						}
						else
						{
							UE_LOG(LogTemp, Warning, TEXT("my enemy %s is dead"), *(*PawnIterator)->GetName());
						}
					}
					else if (UnknownCampComponent && !(UnknownCampComponent->SelfCamp == EnemyCamp))
					{
						UE_LOG(LogTemp, Warning, TEXT("%s is my friend"), *(*PawnIterator)->GetName());
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("%s don't have a CampComponent"), *(*PawnIterator)->GetName());
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("%s don't have a Controller"), *(*PawnIterator)->GetName());
			}

		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%s fail to get into PawnIterator"), *(*PawnIterator)->GetName());
		}
	}
	
	return nullptr;
}


