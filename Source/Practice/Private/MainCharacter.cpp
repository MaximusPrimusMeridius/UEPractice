// Fill out your copyright notice in the Description page of Project Settings.

#include "Practice/Public/MainCharacter.h"

#include "GroomComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	HairGroomComp = CreateDefaultSubobject<UGroomComponent>(TEXT("Hair Groom"));
	HairGroomComp->SetupAttachment(GetMesh());
	HairGroomComp->AttachmentName = FString("head");

	EyebrowGroomComp = CreateDefaultSubobject<UGroomComponent>(TEXT("Eyebrow Groom"));
	EyebrowGroomComp->SetupAttachment(GetMesh());
	EyebrowGroomComp->AttachmentName = FString("head");
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	FString name = HairGroomComp->GetAttachSocketName().ToString();
	
	UE_LOG(LogTemp, Warning, TEXT("%s"), *name);
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMainCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMainCharacter::Turn);
}

void AMainCharacter::MoveForward(float value)
{
	const FRotator YawRotation = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
	AddMovementInput(ForwardDir, value);
}

void AMainCharacter::MoveRight(float value)
{
	const FRotator YawRotation = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDir, value);
}

void AMainCharacter::LookUp(float value)
{
	AddControllerPitchInput(value);
}

void AMainCharacter::Turn(float value)
{
	AddControllerYawInput(value);
}
