// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)			\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)	\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)				\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)				\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

// Default attributes used by all characters, enemies, and objects
UCLASS()
class ASHENSUN_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	// The character's current health.
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Default")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Health)

	// The character's maximum health.
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Default")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MaxHealth)

	// The character's maximum walk speed.
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Movement")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MovementSpeed)

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};

inline void UCharacterAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// No attribute should be a negative value
	NewValue = FMath::Max<float>(NewValue, 0.0f);
	
	if (Attribute == GetHealthAttribute())
	{
		// Health cannot be higher than MaxHealth
		NewValue = FMath::Min<float>(NewValue, GetMaxHealth());
	}
}
