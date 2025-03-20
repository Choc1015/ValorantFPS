// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	MaxHealth = 100.f; // �ִ� ü��
	CurrentHealth = MaxHealth; // ���� ü��

}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CurrentHealth = MaxHealth; // ���� ü��
	
}

void UHealthComponent::TakeDamage(float DamageAmount)
{
	if (DamageAmount <= 0.f)
	{
		return;
	}

	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.f, MaxHealth);

	UE_LOG(LogTemp, Log, TEXT("Damage taken: %f, Current Health: %f"), DamageAmount, CurrentHealth);

	if (CurrentHealth <= 0.f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor %s died."), *GetOwner()->GetName());
		// ��������Ʈ ��ε�ĳ��Ʈ
		OnDeath.Broadcast();
	}
}

