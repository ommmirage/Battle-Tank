// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

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

	// Get world location if linetrace
}
