// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Mage/FireballAbility.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"


// Constructor
UFireballAbility::UFireballAbility()
{
	// Set ability name and description
	AbilityTags.AddTag(FGameplayTag::RequestGameplayTag("Ability.Mage.Fireball"));
}


void UFireballAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const
	FGameplayAbilityActivationInfo ActivationInfo, const
	FGameplayEventData* TriggerEventData)
{
	// Call parent implementation first
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	// get the character using this ability
	ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	if (!Character)
	{
		EndAbility(Handle,ActorInfo, ActivationInfo, true, true);
		return;
	}

	// get spawn location (in front of character)
	FVector SpawnLocation = Character->GetActorLocation() + (Character->GetActorForwardVector() * 100.0f);

	// get spawn roation (direction facing)
	FRotator SpawnRotation = Character->GetActorRotation();

	// spawn parameters
	FActorSpawnParameters SpawnParams;
	SpawnParams.Instigator = Character;
	SpawnParams.Owner = Character;

	// spawn the projectile
	if (ProjectileClass)
	{
		AActor* Projectile = GetWorld()->SpawnActor<AActor>(
			ProjectileClass,
			SpawnLocation,
			SpawnRotation,
			SpawnParams);

		// apply initial velocity if it has a movement component
		if (UPrimitiveComponent* PrimComp = Cast<UPrimitiveComponent>(
			Projectile->GetComponentByClass(UPrimitiveComponent::StaticClass())))
		{
			PrimComp->AddImpulse(Character->GetActorForwardVector() * ProjectileSpeed);
		}
	}

	// end ability
	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
	
}


