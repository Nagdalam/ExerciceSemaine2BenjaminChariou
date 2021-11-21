// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExerciceSemaine2GameMode.h"
#include "ExerciceSemaine2Character.h"
#include "UObject/ConstructorHelpers.h"

AExerciceSemaine2GameMode::AExerciceSemaine2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
