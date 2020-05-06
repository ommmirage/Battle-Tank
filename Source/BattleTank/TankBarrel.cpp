// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "GameFramework/Actor.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float DeltaPitch)
{
	float ElevationChange = 0;
	float DegreesPerSecond = MaxDegreesPerSecond;
	if (DeltaPitch > 0)
	{	
		// Lower barrel speed when elevating the last degree
		if (DeltaPitch < 1)
		{
			DegreesPerSecond = MaxDegreesPerSecond / 2;
		}
		ElevationChange = DegreesPerSecond * GetWorld()->DeltaTimeSeconds;
		if (ElevationChange > DeltaPitch)
		{
			ElevationChange = DeltaPitch;
		}
	}
	else if (DeltaPitch < 0)
	{
		if (DeltaPitch > -1)
		{
			DegreesPerSecond = MaxDegreesPerSecond / 2;
		}
		ElevationChange = -DegreesPerSecond * GetWorld()->DeltaTimeSeconds;
		if (ElevationChange < DeltaPitch)
		{
			ElevationChange = DeltaPitch;
		}
	}
	
	float RawRelativeElevation = GetRelativeRotation().Pitch + ElevationChange;
	float RelativeElevation = FMath::Clamp(RawRelativeElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(RelativeElevation,0,0));
}
