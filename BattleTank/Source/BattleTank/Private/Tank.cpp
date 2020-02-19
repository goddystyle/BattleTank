// Copyright Rafael Suvetailo @ 2020.


#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	auto DamageToApply = FMath::Clamp<int32>(DamageAmount, 0.f, CurrentHealth);
	
	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DamageToApply: %i / CurrentHealth: %i"), DamageToApply, CurrentHealth)
	}
	return DamageToApply;
}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}
