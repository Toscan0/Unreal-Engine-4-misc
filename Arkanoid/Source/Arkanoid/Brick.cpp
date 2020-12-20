// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sm_brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	sm_brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
	box_collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	box_collision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = box_collision;
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
	box_collision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrick::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor,
	UPrimitiveComponent * OtherComp, int32 OtherBodyIndexType, bool bFromSweep,
	const FHitResult & SweepResult) 
{
	if (OtherActor->ActorHasTag("Ball")) {
		ABall *myBall = Cast<ABall>(OtherActor);
		FVector ballVel = myBall->GetVelocity();
		ballVel *= (speedModifierOnBounce - 1.0f);

		myBall->GetBall()->SetPhysicsLinearVelocity(ballVel, true);

		FTimerHandle unusedHandle;
		GetWorldTimerManager().SetTimer(unusedHandle, this, &ABrick::DestroyBrick, 0.1f, false);
	}
}


void ABrick::DestroyBrick()
{
	this->Destroy();
}


