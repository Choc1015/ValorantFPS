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

	//�⺻ ź�� 
	MaxAmmo = 30;
	CurrentAmmo = MaxAmmo;
}

void AWeapon::Fire()
{
	// �⺻ ����
	if (CurrentAmmo > 0)
	{
		// ��Ÿ �߰� ����
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
	// ������ ����
	CurrentAmmo = MaxAmmo;
	UE_LOG(LogTemp, Warning, TEXT("Reload! Current Ammo : %d"), CurrentAmmo);
}


