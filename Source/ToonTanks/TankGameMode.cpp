// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameMode.h"

#include "Tank.h"
#include "Tower.h"
#include "Kismet/GameplayStatics.h"


void ATankGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		Tank->DisableInput(Tank->GetPlayerController());
		Tank->GetPlayerController()->bShowMouseCursor = false;
	}
	else if (ATower* DestoryedTower = Cast<ATower>(DeadActor))
	{
		DestoryedTower->HandleDestruction();
	}
}

void ATankGameMode::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
