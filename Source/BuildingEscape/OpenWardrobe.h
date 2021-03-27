// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Engine/TriggerCapsule.h"
#include "OpenWardrobe.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenWardrobe : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenWardrobe();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void FindPhysicsHandle();
	void FindAudioComponent();
	void SetInputComponent();
	void OpenDoor();
	
	bool OpenDoorSound = false;

private:

	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
	float OpeningAngle = 90.f; 	

	UPROPERTY(EditAnywhere)
	float DoorOpeningSpeed = 0.9f;

	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;
};
