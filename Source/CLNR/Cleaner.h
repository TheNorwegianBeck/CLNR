// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CLNRGameModeBase.h"
#include "KitTest1.h"
#include "PowerSwitch.h"
#include "Cleaner.generated.h"


UCLASS()
class CLNR_API ACleaner : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACleaner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move_X(float AxisValue);
	void Move_Y(float AxisValue);
	void InteractPressed();
	void InteractReleased();
	void Kit1();
	void Kit2();
	void Kit3();
	void SwitchKit();

	UPROPERTY(BlueprintReadOnly)
		int KitNumber;

	float DrainMultiplier = 1;

	UPROPERTY(BlueprintReadOnly)
		bool Interacting = false;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
		void EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	float ExtraRotation = 0; //Used for the controller to change while the player is moving.

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		float Kit1MaxValue = 100; //Value er for vann/s�pe til mopp.

	UPROPERTY(EditAnywhere)
		float Movementspeed = 600;


	AGameModeBase *GameModePointer;
	int PlaceInArray{ 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanMove = true;

	bool EndingLevel = false;

	UPROPERTY(EditAnywhere)
		float TimeAfterEnd = 3;
	

protected:
	class ACLNRGameModeBase* CurrentGameMode;

private: 

	bool MovingX = false;
	bool MovingY = false;
	bool OnKitSwitch = false;
	bool OnPowerSwitch = false;
	
	AKitTest1* KitActor;
	APowerSwitch* PowerSwitch;
	
	
};
