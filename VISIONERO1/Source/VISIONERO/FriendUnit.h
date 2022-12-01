// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Unit.h"
#include "FriendUnit.generated.h"

/**
 * 
 */
UCLASS()
class VISIONERO_API AFriendUnit : public AUnit
{
	GENERATED_BODY()

public:
	AFriendUnit();

	virtual void BeginPlay() override;
	
	
};
