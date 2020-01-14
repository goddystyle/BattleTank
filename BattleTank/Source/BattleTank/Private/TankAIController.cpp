// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledAITank = GetControlledTank();

	if (!ControlledAITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController nao possui um tanque."));
	}

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank %s nao encontrou player."),
			*ControlledAITank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank %s encontrou player %s."),
			*ControlledAITank->GetName(),
			*PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	if (GetPlayerTank())
	{
		// TODO mover-se em direcao ao player

		// Mirar no player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// ATank::AimAt(GetPlayerTank()->GetTargetLocation()); // isso deve estar errado, fui eu que fiz

		// TODO Atirar se estiver pronto
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}