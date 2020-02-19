// Copyright Rafael Suvetailo @ 2020.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// chamado pela engine quando dano eh causado no ator
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// retorna saude como porcentagem de saude inicial, entre 0 e 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	FTankDelegate OnDeath;
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	// UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;
};
