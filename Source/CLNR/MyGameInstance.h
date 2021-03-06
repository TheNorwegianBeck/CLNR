// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "CLNRSaveGame.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CLNR_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
		
public:
	UMyGameInstance();
	float GameScore[5]{ 0,0,0,0,0 }; //Keeps the score per level.
	float HighScore[5]{ 0,0,0,0,0 }; //Keeps the Highscore (if the player cleans everything this is the power the player had left).
		
	UFUNCTION(BlueprintCallable) //Makes the function callable in blueprint
		void SaveGame();

	UFUNCTION(BlueprintCallable)
		int GetGameScore(int Slot);

	UFUNCTION(BlueprintCallable)
		float GetHighScore(int Slot);

	CLNRSaveGame* SaveGameInstance = nullptr;

	//Make this visible in blueprint so the HUD widget knows if it should be visible or not
	UPROPERTY(BlueprintReadWrite, Category = "Should show hud...")
	bool ShouldShowHud = true;
	
};
