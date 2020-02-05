// Copyright Rafael Suvetailo @ 2020.


#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// mover-se em direcao ao player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Mirar no player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// atirar se pronto
		ControlledTank->Fire();
	}
}