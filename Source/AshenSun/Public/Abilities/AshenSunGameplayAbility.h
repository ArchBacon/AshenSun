// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenSunGameplayAbility.generated.h"

UCLASS()
class ASHENSUN_API UAshenSunGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category=Cooldown)
	FScalableFloat CooldownDuration = 0.0f;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category=Cooldown)
	FGameplayTagContainer CooldownTags = {};

	UPROPERTY(Transient)
	FGameplayTagContainer TempCooldownTags = {};

	virtual const FGameplayTagContainer* GetCooldownTags() const override;

	virtual void ApplyCooldown(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) const override;
};
