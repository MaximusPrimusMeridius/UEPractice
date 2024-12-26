// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class UGroomComponent;
class USpringArmComponent;
class UCameraComponent;


UCLASS()
class PRACTICE_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AMainCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UGroomComponent> HairGroomComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UGroomComponent> EyebrowGroomComp;
	
	void MoveForward(float value);
	
	void MoveRight(float value);
	
	void LookUp(float value);
	
	void Turn(float value);
};
