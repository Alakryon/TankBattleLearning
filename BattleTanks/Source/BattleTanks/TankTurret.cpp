// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	auto  time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: %s's Rotation RelativeSpeed: %f"), time, *GetOwner()->GetName(), RelativeSpeed);

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	//auto Elevation = FMath::Clamp<float>(RawNewElevation, 0, 360);
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}


