// Copyright Rafael Suvetailo @ 2020.


#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// TODO continuar o desafio da aula 265

	//// Calcular a velocidade de derrapagem
	//auto SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());
	//// UE_LOG(LogTemp, Warning, TEXT("Slippage: %f"), SlippageSpeed)

	//// Calcular a aceleracao requerida nesse frame para corrigir
	//auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	//// Calcular e aplicar forca lateral (F = m*a)
	//auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	//auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // two tracks
	//TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Lagarta colide"))
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation); 
}

