// Copyright Rafael Suvetailo @ 2020.


#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// TODO continuar o desafio da aula 265

	// Calcular a velocidade de derrapagem
	auto Owner = GetOwner();
	auto SlippageSpeed = Owner->GetActorRightVector().GetSafeNormal();
	// Calcular a aceleracao requerida nesse frame para corrigir
	// Calcular e aplicar forca lateral (F = m*a)
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation); 
}

