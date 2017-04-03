// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
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
		FVector HitLocation = FVector(0.0f);
		if (GetSightRayHitLocation(HitLocation))
		{
			GetControlledTank()->AimAt(HitLocation);
		}
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	FVector CrossHairWorldLocation, CrosshairWorldDirection;
	if (GetWorldDirection(CrossHairWorldLocation, CrosshairWorldDirection))
	{
		GetLookVectorHitLocation(CrossHairWorldLocation, CrosshairWorldDirection, HitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector CrossHairWorldLocation, FVector CrosshairWorldDirection, FVector& HitLocation) const
{
	//Could use as location and direction the:
	//PlayerCameraManager->GetCameraLocation();
	//PlayerCameraManager->GetCameraRotation();

	FHitResult HitResult;
	bool Hit = GetWorld()->LineTraceSingleByChannel(HitResult, CrossHairWorldLocation, CrosshairWorldDirection * LineTraceRange,ECC_Visibility);
	if (Hit)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	else
	{
		return false;
	}
}

bool ATankPlayerController::GetWorldDirection(FVector& CrossHairWorldLocation, FVector& CrosshairWorldDirection) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	return DeprojectScreenPositionToWorld(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation, CrossHairWorldLocation, CrosshairWorldDirection);
}
