// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/P_CharacterBase.h"

// Sets default values
AP_CharacterBase::AP_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AP_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AP_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AP_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

