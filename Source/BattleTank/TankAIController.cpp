// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetControlledTank())
		UE_LOG(LogTemp, Warning, TEXT("AIController is not possedding a tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AI is possessing %s"), *GetControlledTank()->GetName())
}

ATank* ATankAIController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}