// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere, Category= "Components")
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category= "Components")
	UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere, Category= "Movement")
	float Speed = 400.0f;
	UPROPERTY(EditAnywhere, Category= "Movement")
	float RotationRate = 45.f;

	UPROPERTY()
	APlayerController* PlayerControllerRef;
	
	void Move(float value);
	void Turn(float value);
};

