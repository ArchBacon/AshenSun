// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#include "AshenSunGameMode.h"
#include "AshenSunPlayerController.h"
#include "AshenSunPlayerState.h"
#include "Characters/AshenSunCharacter.h"

AAshenSunGameMode::AAshenSunGameMode()
{
	DefaultPawnClass = AAshenSunCharacter::StaticClass();
	PlayerControllerClass = AAshenSunPlayerController::StaticClass();
	PlayerStateClass = AAshenSunPlayerState::StaticClass();
}
