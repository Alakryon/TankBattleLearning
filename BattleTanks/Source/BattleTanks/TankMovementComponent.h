// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Move)
		void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Move)
		void IntendMoveBackward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Move)
		void IntendRotateLeftward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Move)
		void IntendRotateRightward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
	bool IntendForward = false;
	bool IntendBackward = false;
	bool IntendLeftward = false;
	bool IntendRightward = false;

	void MoveLogic();
};
