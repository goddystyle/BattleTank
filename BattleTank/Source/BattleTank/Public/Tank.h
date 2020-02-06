// Copyright Rafael Suvetailo @ 2020.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; // Forward declaration
// TODO remover apos refatorar
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// TODO remover (eh soh um backup de seguranca)
	void AimAt(FVector HitLocation);

	// TODO remover (eh soh um backup de seguranca)
	UFUNCTION(BlueprintCallable)
	void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// TODO remover apos refatorar
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	
	// TODO remover quando Firing for movido pro Aiming Component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 9000.f;

	// TODO remover apos refatorar
	/* "EditDefaultsOnly" edita o valor de todos os tanques, em vez de permitir um valor
	diferente para cada tanque (colocar em LaunchSpeed tambem?) */
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.f;

	// TODO remover
	UTankBarrel* Barrel = nullptr;

	// TODO remover apos refatorar
	double LastFireTime = 0;
};
