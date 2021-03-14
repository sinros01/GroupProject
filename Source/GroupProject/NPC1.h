// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPC1.generated.h"

UCLASS()
class GROUPPROJECT_API ANPC1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANPC1();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Settings")
		class UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere, Category = "Settings")
		class UCapsuleComponent* CollisionComp;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Chat Settings")
		int ChatBubbleIndex = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Chat Settings")
		bool IsTextVisible = false;

	class UWidgetComponent* ChatWidget = nullptr;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	

};
