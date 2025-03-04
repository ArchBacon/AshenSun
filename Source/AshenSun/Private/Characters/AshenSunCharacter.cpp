// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#include "Characters/AshenSunCharacter.h"

// Sets default values
AAshenSunCharacter::AAshenSunCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAshenSunCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAshenSunCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAshenSunCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

