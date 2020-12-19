// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryMan_GameMode.h"
#include "GameFramework/Actor.h"

ABatteryMan_GameMode::ABatteryMan_GameMode() {
	PrimaryActorTick.bCanEverTick = true;
}

void ABatteryMan_GameMode::BeginPlay() {
	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, 
		&ABatteryMan_GameMode::SpawnPlayerRecharge, FMath::RandRange(2,5), true);
}

void ABatteryMan_GameMode::Tick(float delaTime) {
	Super::Tick(delaTime);
}

void  ABatteryMan_GameMode::SpawnPlayerRecharge() {
	float randX = FMath::RandRange(spawn_X_min, spawn_X_max);
	float randY = FMath::RandRange(spawn_Y_min, spawn_Y_max);

	FVector spawnPosition = FVector(randX, randY, spawn_Z);
	FRotator spawnRotation = FRotator(0.0f, 0.0f, 0.0f);

	GetWorld()->SpawnActor(PlayerRecharge, &spawnPosition, &spawnRotation);
}