// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TankGameMode.generated.h"

/**
 * 
 */
class ATank;
UCLASS()
class TOONTANKS_API ATankGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;
	
private:
	ATank* Tank;	
};
