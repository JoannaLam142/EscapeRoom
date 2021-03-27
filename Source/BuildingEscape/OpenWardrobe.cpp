// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenWardrobe.h"
#include "Components/AudioComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UOpenWardrobe::UOpenWardrobe()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenWardrobe::BeginPlay()
{
	Super::BeginPlay();

	InitialYaw = GetOwner() ->GetActorRotation().Yaw;
	CurrentYaw= InitialYaw;
	OpeningAngle += InitialYaw;

	FindAudioComponent();
}


// Called every frame
void UOpenWardrobe::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	OpenDoor();
}

void UOpenWardrobe::FindAudioComponent()
{
	AudioComponent = GetOwner()->FindComponentByClass<UAudioComponent>();
	if(!AudioComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("No Audo Component found on: %s!"), *GetOwner()->GetName());
	}
}

void UOpenWardrobe::OpenDoor()
{
	CurrentYaw = FMath::Lerp(InitialYaw, OpeningAngle, DoorOpeningSpeed);
	FRotator WardrobeOpen = GetOwner()->GetActorRotation();
	WardrobeOpen.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(WardrobeOpen);

	if(!OpenDoorSound)
	{
	AudioComponent->Play();
	OpenDoorSound = true;
	}
}
