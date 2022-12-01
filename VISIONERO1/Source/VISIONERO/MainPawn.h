// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FriendUnit.h"
#include "Unit.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "MainPawn.generated.h"

UCLASS()
class VISIONERO_API AMainPawn : public APawn
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* CameraComponent;

public:
	// Sets default values for this pawn's properties
	AMainPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APlayerController* PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AFriendUnit* Unit;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	bool PressedCameraRotation = false;
	bool SelectedUnit = false;

private:
	void CameraRotationOn();
	void CameraRotationOff();
	void TurnCamera(float Value);
	void LClickButton();

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetUnitLocation();
};
