// Fill out your copyright notice in the Description page of Project Settings.


#include "PitchBlackPlayerController.h"

#include "GameFramework/Character.h"


// Sets default values
APitchBlackPlayerController::APitchBlackPlayerController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APitchBlackPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	AssignPlayerCharacter();
}

// Called every frame
void APitchBlackPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Function to assign the player character reference
void APitchBlackPlayerController::AssignPlayerCharacter()
{
	// Get the player character
	ACharacter* PlayerCharacter = Cast<ACharacter>(GetPawn());

	if (PlayerCharacter)
	{
		// Assign the player character to the property
		PbPlayer = PlayerCharacter;
	}
	else
	{
		// Handle the case where there is no player character
		// You can choose to leave MyPlayerCharacter as nullptr or handle it differently.
	}
}

void APitchBlackPlayerController::PrintSomething()
{
	UE_LOG(LogTemp, Warning, TEXT("This is a warning message: %f"), 0.12);
	// Define variables for the raycast parameters
	FVector StartLocation = PbPlayer->GetActorLocation(); // Set the start location to the current actor's location
	FVector EndLocation = StartLocation + FVector(0, 0, -800.0f); // Set the start location to the current actor's location
	FHitResult HitResult;                       // This will store information about the hit, if any

	// Set up the collision channel and query params
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this); // Ignore this actor in the raycast, if needed

	// Perform the raycast
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility, // Specify the collision channel (change as needed)
		CollisionParams
	);

	// Check if the ray hit something
	if (bHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("MyBooleanValue is %s"), bHit ? TEXT("true") : TEXT("false"));
		// Handle the hit result, e.g., access HitResult.Actor or HitResult.Location
	}
	else
	{
		// Handle the case when the ray doesn't hit anything
	}
}

