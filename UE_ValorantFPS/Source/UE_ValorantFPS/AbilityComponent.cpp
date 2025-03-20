// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponent.h"

// Sets default values for this component's properties
UAbilityComponent::UAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAbilityComponent::ActivateAbility(int32 AbilityIndex)
{
	UE_LOG(LogTemp, Log, TEXT("Ability %d activated for actor %s"), AbilityIndex, *GetOwner()->GetName());

	switch (AbilityIndex)
	{
	case 0:
		UE_LOG(LogTemp, Log, TEXT("Q"));
		break;
	case 1:
		UE_LOG(LogTemp, Log, TEXT("E"));
		break;
	case 2:
		UE_LOG(LogTemp, Log, TEXT("C"));
		break;
	case 3:
		UE_LOG(LogTemp, Log, TEXT("X"));
		break;


	default:
		break;
	}
}



