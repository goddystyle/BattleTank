// Copyright Rafael Suvetailo @ 2020.


#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (PlayerTank)
	{
		// mover-se em direcao ao player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Mirar no player
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		// atirar se pronto
		AimingComponent->Fire();
	}
}