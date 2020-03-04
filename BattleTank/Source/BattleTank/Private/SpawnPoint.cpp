// Copyright Rafael Suvetailo @ 2020.


#include "SpawnPoint.h"
#include "Engine/World.h" // TODO pro VS nao reclamar
#include "GameFramework/Actor.h" // TODO pro VS nao reclamar
#include "Kismet/GameplayStatics.h" // TODO coloquei pra ter os beneficios do intellisense, apagar

// Sets default values for this component's properties
USpawnPoint::USpawnPoint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	SpawnedActor = GetWorld()->SpawnActorDeferred<AActor>(SpawnClass, GetComponentTransform(), GetAttachmentRootActor());

	if (!SpawnedActor) { return; }
	
	SpawnedActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);

	UGameplayStatics::FinishSpawningActor(SpawnedActor, GetComponentTransform());
}


// Called every frame
void USpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
