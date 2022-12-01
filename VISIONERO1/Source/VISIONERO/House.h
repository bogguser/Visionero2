// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageTaker.h"
#include "HealthComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Actor.h"
#include "House.generated.h"

UCLASS()
class VISIONERO_API AHouse : public AActor, public IDamageTaker
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* PointForEnemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetComponent* HealthWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UHealthComponent* HealthComponent;
	
public:	
	// Sets default values for this actor's properties
	AHouse();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void TakeDamageUnit(float DamageUnit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:


};


