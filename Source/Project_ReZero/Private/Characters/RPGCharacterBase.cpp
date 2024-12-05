// Fill out your copyright notice in the Description page of Project Settings.


#include "Project_ReZero/Public/Characters/RPGCharacterBase.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"

/*
 * Constructor,
 * Begin Play,
 * Tick,
 * Player Input Component.
 */

ARPGCharacterBase::ARPGCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	// Create ability system component and set it to be explicitly replicated
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// Create the attribute set
	AttributeSet = CreateDefaultSubobject<UAttributeSet>(TEXT("AttributeSet"));
}

void ARPGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	InitializeAbilities();
}

void ARPGCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARPGCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


/*
 * GAS Functions 
 */


UAbilitySystemComponent* ARPGCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ARPGCharacterBase::InitializeAbilities()
{
	// Initialize for server
	if (GetLocalRole() != ROLE_Authority) return;

	if (AbilitySystemComponent)
	{
		for (TSubclassOf<UGameplayAbility>& DefaultAbility : DefaultAbilities)
		{
			AbilitySystemComponent->GiveAbility(
				FGameplayAbilitySpec(DefaultAbility, 1, INDEX_NONE, this));
		}
	}
}

