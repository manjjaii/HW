// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Math/UnrealMathUtility.h" // FMath::RandRange

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = false; // �� ������ Tick ���ʿ�
	CurrentPosition = FVector2D(0, 0); // ���� ��ġ (0,0)
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	Move(); // ���� ���� �� �̵� ����
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int AMyActor::Step()
{
	// 0 �Ǵ� 1�� ���� ��ȯ
	return FMath::RandRange(0, 1);
}

void AMyActor::Move()
{
	UE_LOG(LogTemp, Warning, TEXT("Start Position: (%.0f, %.0f)"), CurrentPosition.X, CurrentPosition.Y);

	for (int i = 0; i < 10; ++i)
	{
		int dx = Step();
		int dy = Step();

		// ��ǥ �̵�
		CurrentPosition.X += dx;
		CurrentPosition.Y += dy;

		UE_LOG(LogTemp, Warning, TEXT("Step %d: Position (%.0f, %.0f)"), i + 1, CurrentPosition.X, CurrentPosition.Y);
	}
}