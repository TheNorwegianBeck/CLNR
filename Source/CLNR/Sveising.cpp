// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "Sveising.h"
#include "Cleaner.h"



ASveising::ASveising()
{
	OurAnimatedComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("OurAnimatedComponent"));
	OurAnimatedComponent->SetupAttachment(RootComponent);
}

void ASveising::PlayerInteracting(float DeltaTime)
{
	//Kj�r animasjon eller partikler
	if (!Done)
	{
		TimeLeft -= DeltaTime;
		OurVisibleComponent->SetWorldScale3D(FVector(TimeLeft / TotalTime, TimeLeft / TotalTime, TimeLeft / TotalTime));
	}


}

void ASveising::PlayerDone()
{
	if (TargetActor == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found no target actor on Sveising %i"), 0);
		if (!Done)
		{
			GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->CurrentPoints += 1;
			Done = true;
		}
	} //Can be removed?

	else if (TargetActor->IsA(APoweredItem::StaticClass()))
	{
		TargetActor->GettingPower = true;
		if (!Done)
		{
			GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->CurrentPoints += 1;
			Done = true;
			int32 NumberOfCables = CableArray.Num();
			for (int i = 0; i < NumberOfCables; i++)
			{
				CableArray[i]->CanBePowered = true;
			}
		}
	}

}

void ASveising::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (ConnectedSwitch == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found no target actor on Sveising, for Switch!%i"), 0);
	}
	else if (OtherActor->IsA(ACleaner::StaticClass()) && !ConnectedSwitch->SwitchedOn)
	{
		OverlapPlayer = true;
		OurAnimatedComponent->PlayAnimation(AnimOpen, 0);
		OurAnimatedComponent->SetPosition(0, true);
	}
}

void ASveising::EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	if (OtherActor->IsA(ACleaner::StaticClass()) && !ConnectedSwitch->SwitchedOn)
	{
		OverlapPlayer = false;
		OurAnimatedComponent->PlayAnimation(AnimClosed, 0);
		OurAnimatedComponent->SetPosition(1, true);
	}

	else if (ConnectedSwitch == nullptr || TargetActor == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing ConnectedSwitch or TargetActor%i"), 0);
	}



}