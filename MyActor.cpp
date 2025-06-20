// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Math/UnrealMathUtility.h" // FMath::RandRange

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = false; // 매 프레임 Tick 불필요
	CurrentPosition = FVector2D(0, 0); // 시작 위치 (0,0)
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	Move(); // 액터 생성 시 이동 시작
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int AMyActor::Step()
{
	// 0 또는 1을 랜덤 반환
	return FMath::RandRange(0, 1);
}

void AMyActor::Move()
{
	UE_LOG(LogTemp, Warning, TEXT("Start Position: (%.0f, %.0f)"), CurrentPosition.X, CurrentPosition.Y);

	for (int i = 0; i < 10; ++i)
	{
		int dx = Step();
		int dy = Step();

		// 좌표 이동
		CurrentPosition.X += dx;
		CurrentPosition.Y += dy;

		UE_LOG(LogTemp, Warning, TEXT("Step %d: Position (%.0f, %.0f)"), i + 1, CurrentPosition.X, CurrentPosition.Y);
	}
}