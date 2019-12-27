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
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *OutHitLocation.ToString());
		GetControlledTank()->AimAt(OutHitLocation);
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation)
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewPortSeizeY;
	GetViewportSize(ViewportSizeX, ViewPortSeizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewPortSeizeY * CrosshairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *ScreenLocation.ToString());
	// "De-project" the screen position of the crosshair to a world direction
	// Line-trace along that look direction, and see what we hit (up to max range)



	FCollisionQueryParams CollisionParams;
	FHitResult HitResult;

	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		GetControlledTank()->TankAimingComponent->Barrel->GetSocketLocation("BarrelEnd"),
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