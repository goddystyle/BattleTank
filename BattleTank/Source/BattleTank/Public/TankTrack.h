// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack eh usado para definir velocidade maxima de direcao, e para aplicar forcas ao tanque.
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	// forca maxima por lagarta, em Newtons/100 pois a unidade padrao da Unreal eh cm
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float TrackMaxDrivingForce = 61300000.f; // presume-se tanque de 61,3t e acelera a 1g
};
