// Copyright Rafael Suvetailo @ 2020.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h" // TODO tentar tirar dps, soh coloquei pro VS sossegar
#include "PhysicsEngine/RadialForceComponent.h" // TODO tentar tirar dps, soh coloquei pro VS sossegar
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void LaunchProjectile(float Speed);

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerExpire();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DestroyDelay = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ProjectileDamage = 30.f;

	UProjectileMovementComponent* ProjectileMovement = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Collision")
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Particle System")
	URadialForceComponent* ExplosionForce = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Particle System")
	UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Particle System")
	UParticleSystemComponent* ImpactBlast = nullptr;
};
