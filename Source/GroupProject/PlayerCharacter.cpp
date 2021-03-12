// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraActor.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Camera setup
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm comp"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera comp"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void APlayerCharacter::WalkForward(float Value)
{
	FVector Direction = GetActorForwardVector();

	AddMovementInput(Direction, Value);
}

void APlayerCharacter::WalkRight(float Value)
{
	FVector Direction = GetActorRightVector();

	AddMovementInput(Direction, Value);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Walking bindings
	PlayerInputComponent->BindAxis("WalkForward", this, &APlayerCharacter::WalkForward);
	PlayerInputComponent->BindAxis("WalkRight", this, &APlayerCharacter::WalkRight);
	// Character function jump
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
}

