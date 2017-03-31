// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Warning, TEXT("TankPlayerController BeginPlay"));
	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled tank: %s"), *(GetControlledTank()->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Not controlling a tank!"));
	}
}
