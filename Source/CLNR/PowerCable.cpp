// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "PowerCable.h"


// Sets default values
APowerCable::APowerCable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APowerCable::BeginPlay()
{
	Super::BeginPlay();

	
	
}

void APowerCable::SwitchPower(bool GettingPowered)
{
	if (CanBePowered && GettingPowered) //If it is getting power, change the material to the one to show when "on".
	{
		OurVisibleComponent->SetMaterial(MaterialToChange, On);
	}
	else
	{
		OurVisibleComponent->SetMaterial(MaterialToChange, Off);
	}
}

