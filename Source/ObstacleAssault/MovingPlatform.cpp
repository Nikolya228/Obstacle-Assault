// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();

	CurrentLocation += PlatformVeclocity * DeltaTime;

	SetActorLocation(CurrentLocation);

	float CurrentDistance = FVector::Dist(StartLocation, CurrentLocation);

	if (CurrentDistance > DistanceTravel) {
		FVector MoveDirection = PlatformVeclocity.GetSafeNormal();
		StartLocation += MoveDirection * DistanceTravel;
		SetActorLocation(StartLocation);
		PlatformVeclocity *= -1;
	}

}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();

	CurrentRotation += PlatformRotation * DeltaTime;

	SetActorRotation(CurrentRotation);
}

