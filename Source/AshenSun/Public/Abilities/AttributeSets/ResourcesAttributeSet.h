// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "ResourcesAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)			\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)	\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)				\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)				\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class ASHENSUN_API UResourcesAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	// Common crafting Material.
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Resource")
	FGameplayAttributeData Ores;
	ATTRIBUTE_ACCESSORS(UResourcesAttributeSet, Ores)

	// Rare crafting material.
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Resource")
	FGameplayAttributeData Gems;
	ATTRIBUTE_ACCESSORS(UResourcesAttributeSet, Gems)

	// Currency.
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Currency")
	FGameplayAttributeData Souls;
	ATTRIBUTE_ACCESSORS(UResourcesAttributeSet, Souls)

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};

inline void UResourcesAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// No attribute should be a negative value
	NewValue = FMath::Max<float>(NewValue, 0.0f);
}
