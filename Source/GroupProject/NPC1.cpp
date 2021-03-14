// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC1.h"
#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"

// Sets default values
ANPC1::ANPC1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision comp"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static mesh comp"));


	RootComponent = CollisionComp;
	StaticMesh->SetupAttachment(CollisionComp);



	
}

// Called when the game starts or when spawned
void ANPC1::BeginPlay()
{
	Super::BeginPlay();



	ChatWidget = FindComponentByClass<UWidgetComponent>();

	if (ChatWidget)
	{
		ChatWidget->SetVisibility(false);
	}

	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ANPC1::OnOverlapBegin);
	CollisionComp->OnComponentEndOverlap.AddDynamic(this, &ANPC1::OnOverlapEnd);
	
}

// Called every frame
void ANPC1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//Shows text bubbles and resets them on overlap
void ANPC1::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{


	if (OtherActor && (OtherActor != this))
	{
		UE_LOG(LogTemp, Warning, TEXT("lost 5 health"));
		if (OtherActor->IsA(APlayerCharacter::StaticClass()))
		{
			ChatBubbleIndex = 0;
			IsTextVisible = true;
			if (ChatWidget)
			{
				ChatWidget->SetVisibility(true);
			}

			UE_LOG(LogTemp, Warning, TEXT("lost 5000 health"));
		}


	}
}

//Hides text bubbles on overlap end
void ANPC1::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	
	if (OtherActor && (OtherActor != this))
	{
		UE_LOG(LogTemp, Warning, TEXT("no overlap"));
		if (OtherActor->IsA(APlayerCharacter::StaticClass()))
		{

			IsTextVisible = false;
			if (ChatWidget)
			{
				ChatWidget->SetVisibility(false);

			}

			UE_LOG(LogTemp, Warning, TEXT("hide widget"));
		}


	}

	
}
