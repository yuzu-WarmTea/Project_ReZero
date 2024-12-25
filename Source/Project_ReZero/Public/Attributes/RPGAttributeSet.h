// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"


#include "RPGAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


/**
 * 
 */
UCLASS()
class PROJECT_REZERO_API URPGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	
	URPGAttributeSet();

	// Called after attribute changes to clamp values
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	// Base attributes (not class defined)
	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Mana)

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet,MaxMana)

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackPower)

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData DefencePower;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DefencePower)

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Damage)
};
