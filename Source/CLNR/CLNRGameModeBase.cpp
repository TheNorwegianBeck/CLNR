// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "CLNRGameModeBase.h"
#include "Cleaner.h"
#include "MyGameInstance.h"


void ACLNRGameModeBase::ChangePower(float Value)
{
	if ((CurrentPower - Value) <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Power left!"));
		UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenu"));
		Cast<UMyGameInstance>(GetGameInstance())->GameScore[LevelNumber] = ceil((CurrentPoints / MaxPoints) * 10);
		return;

	}
	CurrentPower -= Value;

	if (CurrentPoints == MaxPoints)
	{
		Cast<UMyGameInstance>(GetGameInstance())->GameScore[LevelNumber] = 10;

		if (CurrentPower > Cast<UMyGameInstance>(GetGameInstance())->HighScore[LevelNumber])
		{
			Cast<UMyGameInstance>(GetGameInstance())->HighScore[LevelNumber] = CurrentPower;
		}
			
		UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenu"));

	}

}

