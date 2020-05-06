// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float DeltaYaw)
{
	float RotationChange = 0;
	if (DeltaYaw > 0)
	{
		RotationChange = MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
		RotationChange = FMath::Clamp(RotationChange, -DeltaYaw, DeltaYaw);
	}
	else if (DeltaYaw < 0)
	{
		RotationChange = -MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
		RotationChange = FMath::Clamp(RotationChange, DeltaYaw, -DeltaYaw);
	}
	
	float RelativeRotation = GetRelativeRotation().Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, RelativeRotation, 0));




	//UE_LOG(LogTemp, Warning, TEXT("%f"), GetWorld()->GetTimeSeconds());
	//UE_LOG(LogTemp, Warning, TEXT("Elevation: %f"), GetComponentRotation().Pitch);
	//UE_LOG(LogTemp, Warning, TEXT("RawRelativeElevation: %f"), RawRelativeElevation);
	//UE_LOG(LogTemp, Warning, TEXT("GetRelativeRotation().Pitch: %f"), GetRelativeRotation().Pitch);
	//UE_LOG(LogTemp, Warning, TEXT("ElevationChange: %f"), ElevationChange);
	//UE_LOG(LogTemp, Warning, TEXT("RelativeElevation: %f"), RelativeElevation);
}