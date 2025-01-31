// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
	float Distance = FVector::Dist(Tank->GetActorLocation(), GetActorLocation());
	// Range check
	if (InRange())
	{
		Fire();
	}
}

bool ATower::InRange() const
{
	if (!Tank) return false;
	float Distance = FVector::Dist(Tank->GetActorLocation(), GetActorLocation());
	return Distance <= FireRange;
}

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (InRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
	
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}
