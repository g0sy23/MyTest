// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	/*if (EndpointLocation == nullptr)
		return;

	StartLocation = AActor::GetActorLocation();
	Direction = EndpointLocation - StartLocation;
	TotalDistance = Direction.Size();
	Direction = Direction.GetSafeNormal();
	CurrentDistance = .0f;*/
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*if (EndpointLocation == nullptr)
		return;

	if (CurrentDistance >= TotalDistance)
		return;

	FVector location = AActor::GetActorLocation();
	location += Direction * Speed * DeltaTime;
	AActor::SetActorLocation(location);
	CurrentDistance = (location - StartLocation).Size();*/
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
