// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	if (GetPawn())
	{
		return Cast<ATank>(GetPawn());
	}
	else
	{
		return nullptr;
	}
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled tank: %s"), *(GetControlledTank()->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Not controlling a tank!"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (GetControlledTank())
	{
		FVector HitLocation;
		if (GetSightRayHitLocation(HitLocation))
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *(HitLocation.ToString()));
		}
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0f);
	return true;
}
