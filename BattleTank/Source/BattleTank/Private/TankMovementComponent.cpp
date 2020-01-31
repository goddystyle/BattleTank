// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack *LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet)
	{
		UE_LOG(LogTemp, Warning, TEXT("Uma das tracks nao esta presente"))
	}
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	// TODO impedir velocidade dobrada por usar fly-by-wire e "analogico" ao mesmo tempo

	// TODO observar que minha resposta ao desafio da licao 242 funcionou
	// mesmo sendo diferende da resposta do Ben
	// e mais simples também, sem novos includes e FW declaration
	// Deixar assim e soh modificar se der problema pra frente
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}
