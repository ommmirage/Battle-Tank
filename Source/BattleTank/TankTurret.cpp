// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float DeltaYaw)
{
	float RelativeSpeed = FMath::Clamp<float>(DeltaYaw, -1, 1);
	float RelativeRotation = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();




	//UE_LOG(LogTemp, Warning, TEXT("%f"), GetWorld()->GetTimeSeconds());
	//UE_LOG(LogTemp, Warning, TEXT("Elevation: %f"), GetComponentRotation().Pitch);
	//UE_LOG(LogTemp, Warning, TEXT("RawRelativeElevation: %f"), RawRelativeElevation);
	//UE_LOG(LogTemp, Warning, TEXT("GetRelativeRotation().Pitch: %f"), GetRelativeRotation().Pitch);
	//UE_LOG(LogTemp, Warning, TEXT("ElevationChange: %f"), ElevationChange);
	//UE_LOG(LogTemp, Warning, TEXT("RelativeElevation: %f"), RelativeElevation);
}