// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class UE_VALORANTFPS_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	UPROPERTY(VIsibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	class USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 MaxAmmo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	int32 CurrentAmmo;



public:	

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void Fire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void Reload();

};
