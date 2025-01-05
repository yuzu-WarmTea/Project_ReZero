// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/RPGGameplayAbility.h"

URPGGameplayAbility::URPGGameplayAbility()
{

	// Set common defaults for our abilities
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	// By default, abilities are not replicated unless specified
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;

	// Default tags that all abilities will have
	FAbilityTriggerData TriggerData;
	TriggerData.TriggerTag = FGameplayTag::RequestGameplayTag(FName("Ability.Trigger"));
	AbilityTriggers.Add(TriggerData);
}
