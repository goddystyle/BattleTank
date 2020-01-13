// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	/// se PlayerController nao possuiu um tanque
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController nao possui um tanque"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possui: %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

/// verifica o tanque que foi possuido pelo PlayerController
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

/// movimenta a torre e o canhao rumo ao ponto sobreposto pelo crosshair 
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HIT: %s"), *HitLocation.ToString());
		// TODO dizer ao tanque controlado para mirar nesse ponto
	}
}

/// obtem o ponto sobreposto pelo crosshair, TRUE se atingir landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return false; // soh vai imprimir as coordenadas na tela se retornar TRUE
}
