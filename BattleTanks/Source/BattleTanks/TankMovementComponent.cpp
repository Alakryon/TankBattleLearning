// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (LeftTrackToSet && RightTrackToSet)
	{
		LeftTrack = LeftTrackToSet;
		RightTrack = RightTrackToSet;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Tracks not found!"));
	}
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	IntendForward = (Throw != 0.0f);
	MoveLogic();
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	IntendBackward = (Throw != 0.0f);
	MoveLogic();
}

void UTankMovementComponent::IntendRotateLeftward(float Throw)
{
	IntendLeftward = (Throw != 0.0f);
	MoveLogic();
}

void UTankMovementComponent::IntendRotateRightward(float Throw)
{
	IntendRightward = (Throw != 0.0f);
	MoveLogic();
}

void UTankMovementComponent::MoveLogic()
{
	if ((LeftTrack) && (RightTrack))
	{
		if ((!IntendLeftward) && (!IntendRightward))
		{
			if (IntendForward)
			{
				LeftTrack->SetTrackAnalogAxis(1.0f);
				RightTrack->SetTrackAnalogAxis(1.0f);
			}
			if (IntendBackward)
			{
				LeftTrack->SetTrackAnalogAxis(-1.0f);
				RightTrack->SetTrackAnalogAxis(-1.0f);
			}
		}
		else
		{
			if ((IntendForward) || (IntendBackward))
			{
				if (IntendForward)
				{
					if (IntendLeftward)
					{
						LeftTrack->SetTrackAnalogAxis(0.0f);
						RightTrack->SetTrackAnalogAxis(1.0f);
					}
					if (IntendRightward)
					{
						LeftTrack->SetTrackAnalogAxis(1.0f);
						RightTrack->SetTrackAnalogAxis(0.0f);
					}
				}
				if (IntendBackward)
				{
					if (IntendLeftward)
					{
						LeftTrack->SetTrackAnalogAxis(-0.0f);
						RightTrack->SetTrackAnalogAxis(-1.0f);
					}
					if (IntendRightward)
					{
						LeftTrack->SetTrackAnalogAxis(-1.0f);
						RightTrack->SetTrackAnalogAxis(-0.0f);
					}
				}
			}
			else
			{
				if (IntendLeftward)
				{
					LeftTrack->SetTrackAnalogAxis(-1.0f);
					RightTrack->SetTrackAnalogAxis(1.0f);
				}
				if (IntendRightward)
				{
					LeftTrack->SetTrackAnalogAxis(1.0f);
					RightTrack->SetTrackAnalogAxis(-1.0f);
				}
			}
		}
	}
}
