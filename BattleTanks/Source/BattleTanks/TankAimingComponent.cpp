// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (Barrel && Turret)
	{
		FVector BarrelLocation = Barrel->GetComponentLocation();
		FVector OutLaunchVelocity;
		FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

		if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
		{
			FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
			auto BarrelRotator = Barrel->GetForwardVector().Rotation();
			auto AimAsRotator = AimDirection.Rotation();
			auto DeltaRotator = AimAsRotator - BarrelRotator;

			if (FMath::Abs(DeltaRotator.Pitch) > 1.0f)
			{
				Barrel->Elevate(DeltaRotator.Pitch);
			}

			auto TurretRotator = Turret->GetForwardVector().Rotation();
			DeltaRotator = AimAsRotator - TurretRotator;

			if (FMath::Abs(DeltaRotator.Yaw) > 1.0f)
			{
				float Yaw = DeltaRotator.Yaw;
				if (Yaw > 0.0f)
				{
					if (Yaw > 180.0f)
					{
						Yaw = (Yaw - 180) * (-1);
					}
				}
				else
				{
					if (Yaw < 180.0f)
					{
						Yaw = (Yaw + 180) * (-1);
					}
				}

				Turret->Rotate(Yaw);
			}
		}
		else
		{
			auto  time = GetWorld()->GetTimeSeconds();
			//UE_LOG(LogTemp, Warning, TEXT("%f: %s has no solution to shot at target."), time, *GetOwner()->GetName());
			//Barrel->Elevate(-1);
		}
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	Turret = TurretToSet;
}
