// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageTaker.h"
#include "HealthComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Character.h"
#include "Unit.generated.h"

UCLASS()
class VISIONERO_API AUnit : public ACharacter, public IDamageTaker
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetComponent* HealthWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetComponent* SelectedWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* SphereCollison;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* GoalActor;

	
	
public:	
	// Sets default values for this actor's properties
	AUnit();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TakeDamageUnit(float DamageUnit);
	
	UFUNCTION(BlueprintCallable)
	float GetCurrentHealth();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Attack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
