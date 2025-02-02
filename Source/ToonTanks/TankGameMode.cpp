// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameMode.h"

#include "Tank.h"
#include "Tower.h"
#include "TankPlayerController.h"
#include "Kismet/GameplayStatics.h"


void ATankGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		TankPlayerController->SetPlayerEnabledState(false);
		GameOver(false);
	}
	else if (ATower* DestoryedTower = Cast<ATower>(DeadActor))
	{
		DestoryedTower->HandleDestruction();
		TowerNum--;
		if (TowerNum == 0)
		{
			GameOver(true);
		}
	}
}

void ATankGameMode::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
}

void ATankGameMode::HandleGameStart()
{
	TowerNum = GetTowerCount();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	TankPlayerController = Cast<ATankPlayerController>(UGameplayStatics::GetPlayerController(this, 0));Tank->EnableInput(TankPlayerController);
	
	StartGame();	
	if (TankPlayerController)
	{
		TankPlayerController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableHandle;
		// Time delegate
		FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(TankPlayerController, &ATankPlayerController::SetPlayerEnabledState, true);
		GetWorldTimerManager().SetTimer(PlayerEnableHandle, PlayerEnableDelegate, StartDelay, false);
		
	}
}

int32 ATankGameMode::GetTowerCount()
{
	TArray<AActor*> Towers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATower::StaticClass(), Towers);
	return Towers.Num();
}
