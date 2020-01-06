// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetHitLocationIndicatorReference(UStaticMeshComponent* HitLocationIndicatorReference)
{
	HitLocationIndicator = HitLocationIndicatorReference;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("BarrelEnd"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if(bHaveAimSolution)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Work-out difference between current barrel rotation and AimDirection
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimDirectionRotator = AimDirection.Rotation();
	FRotator DeltaRotator(0);
	DeltaRotator.Pitch = AimDirectionRotator.Pitch - BarrelRotator.Pitch;

	//UE_LOG(LogTemp, Warning, TEXT("Aim Direction Rotator: %s"), *AimDirectionRotator.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("Barrel Rotator: %s"), *BarrelRotator.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("DeltaRotator: %s"), *DeltaRotator.ToString());
	
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
		//FRotator BarrelRotation = 

	if ((Barrel->RelativeRotation.Pitch + DeltaRotator.Pitch) > maxPitch)
		Barrel->SetRelativeRotation(FRotator(maxPitch, 0, 0));
	else if ((Barrel->RelativeRotation.Pitch + DeltaRotator.Pitch) < minPitch)
		Barrel->SetRelativeRotation(FRotator(minPitch, 0, 0));
	else
		Barrel->AddRelativeRotation(DeltaRotator);

	UE_LOG(LogTemp, Warning, TEXT("Barrel Relative Rotator: %s"), *Barrel->GetRelativeRotation().ToString());

}


