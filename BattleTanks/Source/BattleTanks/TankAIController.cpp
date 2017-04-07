// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!ControlledTank) { if (GetPawn()) { ControlledTank = Cast<ATank>(GetPawn()); } }
	if (GetWorld()->GetFirstPlayerController()->GetPawn()) { PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()); }

	if (ControlledTank)
	{
		if (PlayerTank)
		{
			ControlledTank->AimAt(PlayerTank->GetActorLocation());
			ControlledTank->Fire(); // TODO do not fire every frame
		}
	}
}


