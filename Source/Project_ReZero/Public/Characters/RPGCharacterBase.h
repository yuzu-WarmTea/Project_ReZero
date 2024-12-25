// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"


#include "RPGCharacterBase.generated.h"


// Forward Declaration
class UGameplayEffect;
class UGameplayAbility;
class UAbilitySystemComponent;
class UAttributeSet;
class URPGAttributeSet;


UCLASS()
class PROJECT_REZERO_API ARPGCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ARPGCharacterBase();

	// AbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Getter for my AttributeSet
	URPGAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	virtual void BeginPlay() override;

	// The core ActorComponent for the GAS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;

	// My AttributeSet containing main attributes such as health, mana etc.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	URPGAttributeSet* AttributeSet;

	// Called when character spawns to give abilities if need
	virtual void InitializeAbilities();

	// Default abilities to give to this character
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	// Default effects to apply to this character such as base stats
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayEffect>> DefaultEffects;

	
public:	
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
