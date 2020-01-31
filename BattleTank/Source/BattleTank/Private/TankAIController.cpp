// Fill out your copyright notice in the Description page of Project Settings.


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
		// TODO mover-se em direcao ao player

		// Mirar no player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// atirar se pronto
		ControlledTank->Fire();
	}
}