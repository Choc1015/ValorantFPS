// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;

	//기본 탄약 
	MaxAmmo = 30;
	CurrentAmmo = MaxAmmo;
}

void AWeapon::Fire()
{
	// 기본 로직
	if (CurrentAmmo > 0)
	{
		// 기타 추가 로직
		//=======================================================
		CurrentAmmo--;
		UE_LOG(LogTemp, Warning, TEXT("Fire! Current Ammo : %d"), CurrentAmmo);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Out of Ammo!"));
	}

}

void AWeapon::Reload()
{
	// 재장전 로직
	CurrentAmmo = MaxAmmo;
	UE_LOG(LogTemp, Warning, TEXT("Reload! Current Ammo : %d"), CurrentAmmo);
}


