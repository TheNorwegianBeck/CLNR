// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "Stoev.h"
#include "Cleaner.h"



void AStoev::BeginPlay()
{
	Super::BeginPlay();
}

void AStoev::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ACleaner* Player = nullptr;
	if (Player == nullptr)
		Player = Cast<ACleaner>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (Player->Interacting && Player->KitNumber == 2)
	{
		FVector Location = this->GetActorLocation();
		FVector PlayerLocation = Player->GetActorLocation();
		FVector DistanceThisToPlayer = Location - PlayerLocation;
		FVector DistancePlayerToThis = PlayerLocation - Location;
		float DistanceFromPlayerFloat = DistanceThisToPlayer.Size();

		if (DistanceFromPlayerFloat <= DistanceNeeded)
		{
			FVector Velocity = (DistancePlayerToThis * Speed * DeltaTime);
			SetActorLocation(GetActorLocation() + Velocity);
		}			
	}	
}

void AStoev::PlayerInteracting(float DeltaTime)
{
	GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->CurrentPoints += 1;
	Destroy();
}

