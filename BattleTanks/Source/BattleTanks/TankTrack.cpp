// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankTrack.h"

void UTankTrack::InputUpdate()
{
	if (ThrottleUpPressed)
	{
		if (TrackAnalogAxis < 1.0f)
		{
			TrackAnalogAxis += TrackChangeSpeed;
		}
	}
	else
	{
		if (TrackAnalogAxis > 0)
		{
			TrackAnalogAxis -= TrackChangeSpeed * 5.0f;
		}
	}

	if (ThrottleDownPressed)
	{
		if (TrackAnalogAxis > -1.0f)
		{
			TrackAnalogAxis -= TrackChangeSpeed;
		}
	}
	else
	{
		if (TrackAnalogAxis < 0)
		{
			TrackAnalogAxis += TrackChangeSpeed * 5.0f;
		}
	}

	if (TrackAnalogAxis > 1.0f)
	{
		TrackAnalogAxis = 1.0f;
	}
	if (TrackAnalogAxis < -1.0f)
	{
		TrackAnalogAxis = -1.0f;
	}

	auto ForceApplied = GetForwardVector() * TrackAnalogAxis * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UTankTrack::ThrottleUp(bool Pressed)
{
	ThrottleUpPressed = Pressed;
}

void UTankTrack::ThrottleDown(bool Pressed)
{
	ThrottleDownPressed = Pressed;
}

void UTankTrack::SetTrackAnalogAxis(float NewThrottle)
{
	TrackAnalogAxis = NewThrottle;
	UE_LOG(LogTemp, Warning, TEXT("TrackAnalogAxis: %f"), TrackAnalogAxis);
	// TODO Remove Log
}
