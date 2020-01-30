// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	// auto Time = GetWorld()->GetTimeSeconds();
	auto Nome = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: Intend Move Forward: %f"), *Nome, Throw)
}