// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController (%s) BeginPlay"), *(GetName()));
	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController (%s) controlls tank: %s"), *(GetName()),*(GetControlledTank()->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI (%s) does not controlling a tank!"), *(GetName()));
	}
}


