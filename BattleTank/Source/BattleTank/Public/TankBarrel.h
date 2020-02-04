// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 eh vel maxima pra baixo e +1 eh vel maxima pra cima
	void Elevate(float RelativeSpeed);

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegressPerSecond = 10; // sensible default

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees = 30; // sensible default

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = 0; // sensible default
};
