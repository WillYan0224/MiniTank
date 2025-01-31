// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
class ATank;
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;
	void HandleDestruction();
protected:
	virtual void BeginPlay() override;

private:
	ATank* Tank;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float FireRate = 2.0f;
	UPROPERTY(EditAnywhere, Category = "Combat")
	float FireRange = 350.0f;
	
	FTimerHandle FireRateTimerHandle;
	void CheckFireCondition();

	bool InRange() const;
};
