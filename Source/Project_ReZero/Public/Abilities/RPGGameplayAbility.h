// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"


#include "RPGGameplayAbility.generated.h"

/**
 * 
 */

UCLASS()
class PROJECT_REZERO_API URPGGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	URPGGameplayAbility();

	// The level of the ability used for scaling effects
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Ability")
	int32 AbilityLevel = 1;

	// Gameplay tags required to use this ability
	UPROPERTY(EditDefaultsOnly, Category= "Ability")
	FGameplayTagContainer AbilityRequiredTags;

	// Gameplay tags that block this ability
	UPROPERTY(EditDefaultsOnly, Category= "Ability")
	FGameplayTagContainer AbilityBlockTags;

	// The cooldown GameplayEffect class for this ability
	UPROPERTY(EditDefaultsOnly, Category= "Ability")
	TSubclassOf<UGameplayEffect> CooldownEffectClass;

	// The cost GameplayEffect class for this ability ex mana/stamina/rage idk
	UPROPERTY(EditDefaultsOnly, Category= "Ability")
	TSubclassOf<UGameplayEffect> CostEffectClass;
};
