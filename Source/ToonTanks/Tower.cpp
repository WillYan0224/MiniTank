// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!Tank) return;
	float Distance = FVector::Dist(Tank->GetActorLocation(), GetActorLocation());
	// Range check
	if (Distance <= FireRange)
	{
		RotateTurret(Tank->GetActorLocation());
	}
	
}
