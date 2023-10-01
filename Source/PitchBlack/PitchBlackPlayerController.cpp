// Fill out your copyright notice in the Description page of Project Settings.


#include "PitchBlackPlayerController.h"

#include "GameFramework/Character.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Runtime/CoreUObject/Public/UObject/Class.h"

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
	// Define variables for the raycast parameters
	FVector StartLocation = PbPlayer->GetActorLocation(); // Set the start location to the current actor's location
	FVector EndLocation = StartLocation - FVector(0, 0, 150.0f);
	// Set the start location to the current actor's location
	FHitResult HitResult; // This will store information about the hit, if any

	// Set up the collision channel and query params
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this); // Ignore this actor in the raycast, if needed
	CollisionParams.bReturnPhysicalMaterial = true;


	// Perform the raycast
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility, // Specify the collision channel (change as needed)
		CollisionParams
	);

	// Check if the ray hit something
	if (bHit && HitResult.GetActor() && HitResult.PhysMaterial.Get())
	{
		AActor* HitActor = HitResult.GetActor();
		FVector ActorLocation = HitActor->GetActorLocation();
		TEnumAsByte<EPhysicalSurface> SurfaceType = HitResult.PhysMaterial.Get()->SurfaceType;


		switch (SurfaceType)
		{
		case EPhysicalSurface::SurfaceType1:
			UE_LOG(LogTemp, Warning, TEXT("This is a warning message: %f"), 0.1);
			break;
		case EPhysicalSurface::SurfaceType2:
			UE_LOG(LogTemp, Warning, TEXT("This is a warning message: %f"), 0.2);
			break;
		case EPhysicalSurface::SurfaceType3:
			UE_LOG(LogTemp, Warning, TEXT("This is a warning message: %f"), 0.3);
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("This is a warning message: %f"), 0.24);
			break;
		}
		// UE_LOG(LogTemp, Warning, TEXT("Actor Name: %s"), *ActorName);
	}
	else
	{
		// Handle the case when the ray doesn't hit anything
	}
}
