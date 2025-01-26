// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &ATank::Move);
	PlayerInputComponent->BindAxis("Turn", this, &ATank::Turn);
}

void ATank::Move(float value)
{
	FVector Direction = FVector::ZeroVector;
	Direction.X = value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(Direction, true);
}

void ATank::Turn(float value)
{
	FRotator Rotation = FRotator::ZeroRotator;
	Rotation.Yaw = value * RotationRate * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(Rotation, true);
}
