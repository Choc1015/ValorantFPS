// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_ValorantFPSGameMode.h"
#include "UE_ValorantFPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_ValorantFPSGameMode::AUE_ValorantFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
