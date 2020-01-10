// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/Actor.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledAITank = GetControlledTank();

	auto FoundPlayerTank = GetPlayerTank();

	UE_LOG(LogTemp, Warning, TEXT("Tank %s encontrou player %s."), *ControlledAITank->GetName(), *FoundPlayerTank->GetName());

	if (!ControlledAITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController nao possui um tanque."));
	}
	else
	{
		
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetPawn());
	//TODO isso esta errado pois assim esta pegando a si proprio
	//TODO arrumar para pegar o player
}