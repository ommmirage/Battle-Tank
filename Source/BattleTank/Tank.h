// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category="Firing")
		float LaunchSpeed = 10000.f; // TODO find sensible default

public:
	UTankAimingComponent* TankAimingComponent = nullptr;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetHitLocationIndicatorReference(UStaticMeshComponent* HitLocationIndicatorReference);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

};
