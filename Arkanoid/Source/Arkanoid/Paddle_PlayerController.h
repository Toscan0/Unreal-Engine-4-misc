// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"
#include "Ball.h"
#include "Paddle_PlayerController.generated.h"


class ABall;

UCLASS()
class ARKANOID_API APaddle_PlayerController : public APlayerController
{
	GENERATED_BODY()

		APaddle_PlayerController();

	UFUNCTION()
		virtual void SetupInputComponent() override;

protected: 
	virtual void BeginPlay() override;
	void MoveHorizontal(float axisValue);
	
	//ball references
	void Launch();
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> ballObj;

	ABall *myBall;
	FVector spawnLocation = FVector(10.0f, 0.0f, 40.0f);
	FRotator spawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters spawnInfo;

public:
	void SpawnNewBall();
};
