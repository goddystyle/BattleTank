// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsavel por tracionar as lagartas
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float Throw);

private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;

	// TODO observar que minha resposta ao desafio da licao 242 funcionou
	// mesmo sendo diferende da resposta do Ben
	// e mais simples também, sem novos includes e FW declaration
	// Deixar assim e soh modificar se der problema pra frente
};
