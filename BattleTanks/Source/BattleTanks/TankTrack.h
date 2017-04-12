// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void ThrottleUp(bool Pressed);
	UFUNCTION(BlueprintCallable, Category = Input)
		void ThrottleDown(bool Pressed);
	UFUNCTION(BlueprintCallable, Category = Input)
		void InputUpdate();

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float TrackChangeSpeed = 0.02f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float TrackMaxDrivingForce = 400000.0f;
	float TrackAnalogAxis = 0.0f;
	bool ThrottleUpPressed = false;
	bool ThrottleDownPressed = false;
};
