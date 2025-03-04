// Copyright (c) 2025, Christian Delicaat. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AshenSunCharacter.generated.h"

class UResourcesAttributeSet;
class USpringArmComponent;
class UGameplayEffect;
class UCameraComponent;
class UCharacterAttributeSet;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;
struct FOnAttributeChangeData;

UCLASS()
class ASHENSUN_API AAshenSunCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	/** Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	UCameraComponent* Camera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	USpringArmComponent* SpringArm;

	/** Abilities */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Ability, meta=(AllowPrivateAccess="true"))
	UAbilitySystemComponent* AbilitySystem = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Ability, meta=(AllowPrivateAccess="true"))
	TSubclassOf<UGameplayEffect> DefaultAttributesEffect;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Ability, meta=(AllowPrivateAccess="true"))
	UCharacterAttributeSet* CharacterAttributes;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Ability, meta=(AllowPrivateAccess="true"))
	UResourcesAttributeSet* ResourcesAttributes;
	
	/** Input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess="true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess="true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess="true"))
	UInputAction* LookAction;

public:
	AAshenSunCharacter();

protected:
	/** Overrides */
	virtual void NotifyControllerChanged() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;

protected:
	/** Event responses */
	void OnMovementSpeedChanged(const FOnAttributeChangeData& Data) const;

protected:
	/** Input responses */
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

public:
	/** Component getters */
	FORCEINLINE virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystem; }
	FORCEINLINE UCameraComponent* GetCameraComponent() const { return Camera; }
	FORCEINLINE USpringArmComponent* GetSpringArmComponent() const { return SpringArm; }
};
