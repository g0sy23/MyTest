// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIBlueprintHelperLibrary.h"

#include "TimerManager.h"

void UMyAIBlueprintHelperLibrary::MySimpleMoveToLocation1(AController* Controller, const FVector& Goal)
{
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Goal);
}

void UMyAIBlueprintHelperLibrary::MySimpleMoveToLocation2(AController* Controller, const FVector& Goal)
{
	FTimerManager& timerManager = Controller->GetWorld()->GetTimerManager();

	FTimerHandle timerHandle;
	timerManager.SetTimer(timerHandle, [=]() { UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Goal); }, 1.5f, true);

	FTimerHandle timerHandle1;
	timerManager.SetTimer(timerHandle1, [=]() { Controller->StopMovement(); }, 1.5f, true, 1.0f);
}

void UMyAIBlueprintHelperLibrary::MySimpleMoveToLocation3(AController* Controller, const FVector& Goal, const FVector& Goal1)
{
	FTimerManager& timerManager = Controller->GetWorld()->GetTimerManager();

	FTimerHandle timerHandle;
	timerManager.SetTimer(timerHandle, [=]() { UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Goal); }, 1.5f, true);

	FTimerHandle timerHandle1;
	timerManager.SetTimer(timerHandle1, [=]() { UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Goal1); }, 1.5f, true, 1.0f);
}
