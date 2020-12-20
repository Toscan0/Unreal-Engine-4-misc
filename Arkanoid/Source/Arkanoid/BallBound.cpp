// Fill out your copyright notice in the Description page of Project Settings.


#include "BallBound.h"

// Sets default values
ABallBound::ABallBound()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	box_collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = box_collision;

}

// Called when the game starts or when spawned
void ABallBound::BeginPlay()
{
	Super::BeginPlay();

	box_collision->OnComponentBeginOverlap.AddDynamic(this, &ABallBound::OnOverlapBegin);

	playerController_REF = Cast<APaddle_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

// Called every frame
void ABallBound::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABallBound::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, 
	AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndexType, 
	bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Ball")) {
		OtherActor->Destroy();

		playerController_REF->SpawnNewBall();
	}
}



