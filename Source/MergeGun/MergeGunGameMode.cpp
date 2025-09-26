// Copyright Epic Games, Inc. All Rights Reserved.

#include "MergeGunGameMode.h"
#include "MergeGunCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMergeGunGameMode::AMergeGunGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
