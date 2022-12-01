// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit.h"

#include "House.h"
#include "MainPawn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AUnit::AUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthWidget"));
	HealthWidget->SetupAttachment(GetRootComponent());
	
	SelectedWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("SelectedWidget"));
	SelectedWidget->SetupAttachment(GetRootComponent());

	SphereCollison = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollison"));
	SphereCollison->SetupAttachment(GetRootComponent());

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	

}

void AUnit::TakeDamageUnit_Implementation(float DamageUnit)
{
	HealthComponent->ChangeCurrentHealth(DamageUnit);
}



float AUnit::GetCurrentHealth()
{
	return HealthComponent->CurrentHealth;
}

void AUnit::Attack_Implementation()
{
	if(GoalActor)
	{
		AUnit* GoalUnit = Cast<AUnit>(GoalActor);
		if(GoalUnit)
		{
			GoalUnit->TakeDamageUnit(Damage);
		}
		else
		{
			AHouse* GoalHouse = Cast<AHouse>(GoalActor);
			if(GoalHouse)
			{
				GoalHouse->TakeDamageUnit(Damage);
			}
		}
	}
}



// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

