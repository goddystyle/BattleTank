// Copyright Rafael Suvetailo @ 2020.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// distancia minima que o tanque inimigo pode chegar do player
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 30000.f;

private:
	UFUNCTION() // tem que ser UFUNCTION pra ser chamada
	void OnPossessedTankDeath();

	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float deltatime) override;
};
