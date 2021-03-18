// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoneBreakDemoGameMode.h"
#include "BoneBreakDemoHUD.h"
#include "BoneBreakDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABoneBreakDemoGameMode::ABoneBreakDemoGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ABoneBreakDemoHUD::StaticClass();
}
