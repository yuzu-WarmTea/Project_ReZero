// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/RPGGameplayAbility.h"


#include "FireballAbility.generated.h"

/**
 * 
 */

UCLASS()
class PROJECT_REZERO_API UFireballAbility : public URPGGameplayAbility
{
	GENERATED_BODY()

public:
	UFireballAbility();

	// called when the ability is activated
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

protected:
	// the project class/actor to spawn
	UPROPERTY(EditDefaultsOnly, Category= "Ability")
	TSubclassOf<AActor> ProjectileClass;

	// base damage of fireball
	UPROPERTY(EditDefaultsOnly, Category= "Ability")
	float BaseDamage = 50.0f;

	// projectile speed
	UPROPERTY(EditDefaultsOnly, Category= "Ability")
	float ProjectileSpeed = 2000.0f;

	// gameplay effect that applies the damage
	UPROPERTY(EditDefaultsOnly, Category= "Ability")
	TSubclassOf<UGameplayEffect> DamageEffectClass;
};
