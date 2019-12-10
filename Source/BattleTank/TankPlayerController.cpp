// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetControlledTank()) 
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is not possedding a tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("Player is possessing %s"), *GetControlledTank()->GetName())
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}
	

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation;

	if (GetSightRayHitLocation(OutHitLocation)) // Has "side-effect", is going to set OutHitLocation
	{
		GetControlledTank()->AimAt(OutHitLocation);
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation)
{
	FCollisionQueryParams CollisionParams;
	FHitResult HitResult;

	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		GetSightRayStart(),
		GetSightRayEnd(),
		ECollisionChannel::ECC_Visibility,
		CollisionParams)
		)
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}

FVector ATankPlayerController::GetSightRayStart()
{
	TArray<UStaticMeshComponent*> StaticMeshComponents;

	GetControlledTank()->GetComponents<UStaticMeshComponent>(OUT StaticMeshComponents);

	UStaticMeshComponent* Barrel = StaticMeshComponents[2];
	FVector BarrelEndRalativeLocation = Barrel->GetSocketByName("BarrelEnd")->RelativeLocation;
	return (Barrel->GetComponentLocation()+ BarrelEndRalativeLocation);
}

FVector ATankPlayerController::GetSightRayEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * ShotingDistance;
}