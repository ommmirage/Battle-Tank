// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(FRotator DeltaRotator)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time

	//if ((Barrel->RelativeRotation.Pitch + DeltaRotator.Pitch) > maxPitch)
	//	Barrel->SetRelativeRotation(FRotator(maxPitch, 0, 0));
	//else if ((Barrel->RelativeRotation.Pitch + DeltaRotator.Pitch) < minPitch)
	//	Barrel->SetRelativeRotation(FRotator(minPitch, 0, 0));
	//else
	AddRelativeRotation(DeltaRotator);

	//UE_LOG(LogTemp, Warning, TEXT("Barrel Relative Rotator: %s"), *GetRelativeRotation().ToString());
}
