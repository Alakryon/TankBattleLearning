// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
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

ATank * ATankAIController::GetPlayerTank() const
{
	if (GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	}
	else
	{
		return nullptr;
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController (%s) controlls tank: %s"), *(GetName()),*(GetControlledTank()->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI (%s) does not controlling a tank!"), *(GetName()));
	}
	if (GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController (%s) pursues player controlled tank: %s"), *(GetName()), *(GetPlayerTank()->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI (%s) does not pursuing a tank!"), *(GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetControlledTank())
	{
		if (GetPlayerTank())
		{
			GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		}
	}
}


