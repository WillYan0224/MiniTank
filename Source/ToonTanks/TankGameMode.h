// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TankGameMode.generated.h"

class ATankPlayerController;
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

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWon);
	
private:
	ATank* Tank;
	ATankPlayerController* TankPlayerController;

	int32 TowerNum = 0;
	
	float StartDelay = 5.f;
	
	void HandleGameStart();
	int32 GetTowerCount();
};
