// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdPerson_CPPGameMode.h"
#include "ThirdPerson_CPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThirdPerson_CPPGameMode::AThirdPerson_CPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
