// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
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

	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("BarrelEnd"));

	UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());

	HitLocationIndicator->SetWorldLocation(HitLocation);

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if(bHaveAimSolution)
	{
		//UE_LOG(LogTemp, Warning, TEXT("OutLaunchVelocity: %s"), *OutLaunchVelocity.ToString());
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}	
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Work-out difference between current barrel rotation and AimDirection
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimDirectionRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimDirectionRotator - BarrelRotator;

	//UE_LOG(LogTemp, Warning, TEXT("Aim Direction: %s"), *AimDirectionRotator.ToString());
	
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
		//FRotator BarrelRotation = 
		//Barrel->Rotation
}


