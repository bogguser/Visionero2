// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VISIONERO_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,meta = (ClapMin = "0.1", UIMin = "0.1"));
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	float CurrentHealth;

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	bool IsDeath() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:

	void ChangeCurrentHealth(float Damage);

		
};
