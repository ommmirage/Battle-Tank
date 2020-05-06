// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "GameFramework/Actor.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float DeltaPitch)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time

	float ElevationChange = 0;
	if (DeltaPitch > 0)
	{
		ElevationChange = MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	}
	else if (DeltaPitch < 0)
	{
		ElevationChange = -MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	}
	ElevationChange = FMath::Clamp(ElevationChange, -DeltaPitch, DeltaPitch);
	float RawRelativeElevation = GetRelativeRotation().Pitch + ElevationChange;
	float RelativeElevation = FMath::Clamp(RawRelativeElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(RelativeElevation,0,0));


	UE_LOG(LogTemp, Warning, TEXT("%f"), GetWorld()->GetTimeSeconds());
	UE_LOG(LogTemp, Warning, TEXT("RelativeElevation: %f"), RelativeElevation);
}
