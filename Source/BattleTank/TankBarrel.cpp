// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "GameFramework/Actor.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	UE_LOG(LogTemp, Warning, TEXT("DeltaRotator.Pitch: %f"), RelativeSpeed);
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawRelativeElevation = RelativeRotation.Pitch + ElevationChange;
	float RelativeElevation = FMath::Clamp(RawRelativeElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(RelativeElevation,0,0));
}
