// Copyright Epic Games, Inc. All Rights Reserved.

#include "PitchBlackGameMode.h"
#include "PitchBlackHUD.h"
#include "PitchBlackCharacter.h"
#include "UObject/ConstructorHelpers.h"

APitchBlackGameMode::APitchBlackGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/PitchBlack/Core/BP_Character"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APitchBlackHUD::StaticClass();
}
