// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
	if (bPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
		bShowMouseCursor = true;
	}
	else
	{
		GetPawn()->DisableInput(this);
		bShowMouseCursor = false;
	}
}
