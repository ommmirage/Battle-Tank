// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

private:
	float ShotingDistance = 50000.f;
	float LineTraceRange = 1000000.f;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.5f;

	ATank* GetControlledTank() const;

	virtual void Tick(float DeltaTime) override;

	// Moves a barrel to a crosshair (прицел)
	void AimTowardsCrosshair();

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector& OutHitLocation, FVector LookDirection) const;
	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
};
