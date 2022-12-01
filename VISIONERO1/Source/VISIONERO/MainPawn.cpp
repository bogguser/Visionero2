// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPawn.h"

#include "FriendUnit.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMainPawn::AMainPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->TargetArmLength = 3350.f;
	SpringArmComponent->bDoCollisionTest = false;
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->bInheritPitch = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

}

// Called when the game starts or when spawned
void AMainPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMainPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("CameraRotation", IE_Pressed,this, &AMainPawn::CameraRotationOn);
	PlayerInputComponent->BindAction("CameraRotation", IE_Released,this, &AMainPawn::CameraRotationOff);
	PlayerInputComponent->BindAction("LClick", IE_Pressed,this, &AMainPawn::LClickButton);

	PlayerInputComponent->BindAxis("Turn", this, &AMainPawn::TurnCamera);

}

void AMainPawn::CameraRotationOn()
{
	PressedCameraRotation = true;
}

void AMainPawn::CameraRotationOff()
{
	PressedCameraRotation = false;
}

void AMainPawn::TurnCamera(float Value)
{
	if(PressedCameraRotation)
	{
		AMainPawn::AddControllerYawInput(Value);
	}
}

void AMainPawn::LClickButton()
{
	FHitResult HitResult;

	if(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility),true, HitResult) && !SelectedUnit)
	{
		if(HitResult.GetActor()->IsA(AFriendUnit::StaticClass()))
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("This interface ACTOR C++"));
			Unit = Cast<AFriendUnit>(HitResult.GetActor());
			SelectedUnit = true;
			Unit->SelectedWidget->SetHiddenInGame(false);
		}
	}
	else if(SelectedUnit)
	{
		SetUnitLocation();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("SelectedUnitGO!"));
		SelectedUnit = false;
		Unit->SelectedWidget->SetHiddenInGame(true);
		Unit = nullptr;
	}


}


