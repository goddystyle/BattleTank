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

private:
	virtual void BeginPlay() override;

	virtual void Tick(float deltatime) override;

	// distancia minima que o tanque inimigo pode chegar do player
	float AcceptanceRadius = 300.f;
};
