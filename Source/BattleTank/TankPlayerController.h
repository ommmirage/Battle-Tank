// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

private:
	float ShotingDistance = 50000.f;
	ATank* GetControlledTank() const;

	virtual void Tick(float DeltaTime) override;

	// Moves a barrel to a crosshair (прицел)
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation);

	FVector GetSightRayStart();
	
	FVector GetSightRayEnd();
};
