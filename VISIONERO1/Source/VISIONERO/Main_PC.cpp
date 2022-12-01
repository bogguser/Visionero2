// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_PC.h"

AMain_PC::AMain_PC()
{

}

void AMain_PC::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}
