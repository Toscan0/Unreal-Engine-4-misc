// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sm_ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM ball"));
	RootComponent = sm_ball;

	sm_ball->SetSimulatePhysics(true);
	sm_ball->SetEnableGravity(false);
	sm_ball->SetConstraintMode(EDOFMode::XZPlane);
	sm_ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	sm_ball->SetCollisionProfileName(TEXT("PhysicsActor"));

	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	projectileMovement->bShouldBounce = true;
	projectileMovement->Bounciness = 1.1f;
	projectileMovement->Friction = 0.0f;
	projectileMovement->Velocity.X = 0.0f;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::Launch()
{
	if (!ballLaunched) {
		sm_ball->AddImpulse(FVector(140.0f, 0.0f, 130.0f), FName(), true);

		ballLaunched = true;
	}
}

UStaticMeshComponent * ABall::GetBall()
{
	return sm_ball;
}


