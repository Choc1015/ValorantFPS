// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h" 
#include "Weapon.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 카메라 컴포넌트 생성 및 초기설정
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCameraComponent"));

	// 카메라를 캡슐컴포넌트에 붙이기
	FPSCameraComponent->SetupAttachment(GetCapsuleComponent());

	// 카메라가 플레이어 컨트롤러?회전을 따르도록 설정
	FPSCameraComponent->bUsePawnControlRotation = true;

	GetCharacterMovement()->AirControl = 1.0f;
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (StartWeaponClass)
	{
		CurrentWeapon = GetWorld()->SpawnActor<AWeapon>(StartWeaponClass);
		if (CurrentWeapon)
		{
			CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
		}
	
	}
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::OnFire);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AFPSCharacter::OnReload);
}

void AFPSCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);


		// 앞 방향 계산
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);

	}
}

void AFPSCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0.f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// 오른쪽 방향 계산
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AFPSCharacter::OnFire()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Fire();
	}
}

void AFPSCharacter::OnReload()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Reload();
	}
}

