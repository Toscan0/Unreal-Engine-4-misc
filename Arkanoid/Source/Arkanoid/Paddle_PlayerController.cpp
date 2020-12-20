// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_PlayerController.h"

APaddle_PlayerController::APaddle_PlayerController() {}

void APaddle_PlayerController::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams params;
	SetViewTarget(CameraActors[0], params);

	SpawnNewBall();
}

void APaddle_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &APaddle_PlayerController::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddle_PlayerController::Launch);
}

void APaddle_PlayerController::MoveHorizontal(float axisValue)
{
	auto myPawn = Cast<APaddle>(GetPawn());

	if (myPawn) {
		myPawn->MoveHorizontal(axisValue);
	}
}

void APaddle_PlayerController::Launch()
{
	myBall->Launch();
}

void APaddle_PlayerController::SpawnNewBall()
{
	if (!myBall) {
		myBall = nullptr;
	}
	if (ballObj) {
		myBall = GetWorld()->SpawnActor<ABall>(ballObj, spawnLocation, spawnRotation, spawnInfo);
	}
}
