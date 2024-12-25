// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/RPGAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"
#include "Net/UnrealNetwork.h"


URPGAttributeSet::URPGAttributeSet()
{
	// Initializing Base values
	MaxHealth = 100.0f;
	Health = MaxHealth.GetBaseValue();

	MaxMana = 100.0f;
	Mana = MaxMana.GetBaseValue();

	AttackPower = 10.0f;
	DefencePower = 5.0f;
	
}


void URPGAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// Getting target actor
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		// Cache tags
		FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();

		// Get the attribute that was modified
		const FGameplayAttribute& Attribute = Data.EvaluatedData.Attribute;

		// get the amount it was modified by
		const float DeltaValue = Data.EvaluatedData.Magnitude;

		// handling damage
		if (Attribute == GetDamageAttribute())
		{
			// store a local copy of the amount of dmg done and clear dmg attribute
			const float LocalDamageDone = GetDamage();
			SetDamage(0.f);

			if (LocalDamageDone > 0.0f)
			{
				// apply dmg to health
				const float NewHealth = GetHealth() - LocalDamageDone;
				SetHealth(FMath::Clamp(NewHealth, 0.0f, GetMaxHealth()));
			}
		}

		else if (Attribute == GetHealthAttribute())
		{
			SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
		}

		else if (Attribute == GetManaAttribute())
		{
			SetMana(FMath::Clamp(GetMana(), 0.0f, GetMaxMana()));
		}
	}
}

