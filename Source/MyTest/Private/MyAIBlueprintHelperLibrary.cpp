// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIBlueprintHelperLibrary.h"

#include "AIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "TimerManager.h"

namespace
{
	UPathFollowingComponent* InitNavigationControl(AController& Controller)
	{
		AAIController* AsAIController = Cast<AAIController>(&Controller);
		UPathFollowingComponent* PathFollowingComp = nullptr;

		if (AsAIController)
		{
			PathFollowingComp = AsAIController->GetPathFollowingComponent();
		}
		else
		{
			PathFollowingComp = Controller.FindComponentByClass<UPathFollowingComponent>();
			if (PathFollowingComp == nullptr)
			{
				PathFollowingComp = NewObject<UPathFollowingComponent>(&Controller);
				PathFollowingComp->RegisterComponentWithWorld(Controller.GetWorld());
				PathFollowingComp->Initialize();
			}
		}

		return PathFollowingComp;
	}
}

void UMyAIBlueprintHelperLibrary::MySimpleMoveToLocation1(AController* Controller, const FVector& Goal)
{
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Goal);
}

void UMyAIBlueprintHelperLibrary::MySimpleMoveToLocation2(AController* Controller, const FVector& Goal)
{
	FTimerManager& timerManager = Controller->GetWorld()->GetTimerManager();

	FTimerHandle timerHandle;
	timerManager.SetTimer(timerHandle, [=]() { UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Goal); }, 1.5f, true, 0.0f);

	FTimerHandle timerHandle1;
	timerManager.SetTimer(timerHandle1, [=]() { Controller->StopMovement(); }, 1.5f, true, 1.0f);

	FTimerHandle timerHandle2;
	timerManager.SetTimer
	(
		timerHandle2,
		[=]() mutable
		{
			if (Controller == nullptr)
			{
				return;
			}

			if (!Controller->GetWorld()->GetTimerManager().TimerExists(timerHandle) && !Controller->GetWorld()->GetTimerManager().TimerExists(timerHandle))
			{
				return;
			}

			UPathFollowingComponent* PFollowComp = InitNavigationControl(*Controller);
			const bool bAlreadyAtGoal = PFollowComp->HasReached(Goal, EPathFollowingReachMode::OverlapAgent);
			if (bAlreadyAtGoal || Controller->GetPawn() == nullptr)
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Goal);
				Controller->GetWorld()->GetTimerManager().ClearTimer(timerHandle);
				Controller->GetWorld()->GetTimerManager().ClearTimer(timerHandle1);
			}
		},
		0.5f,
		true,
		0.0f
	);
}

void UMyAIBlueprintHelperLibrary::MySimpleMoveToLocation3(AController* Controller, const FVector& Goal, const FVector& Goal1)
{
	FTimerManager& timerManager = Controller->GetWorld()->GetTimerManager();

	FTimerHandle timerHandle;
	timerManager.SetTimer(timerHandle, [=]() { UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Goal); }, 1.5f, true, 0.0f);

	FTimerHandle timerHandle1;
	timerManager.SetTimer(timerHandle1, [=]() { UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Goal1); }, 1.5f, true, 1.0f);

	FTimerHandle timerHandle2;
	timerManager.SetTimer
	(
		timerHandle2,
		[=]() mutable
		{
			if (Controller == nullptr)
			{
				return;
			}

			if (!Controller->GetWorld()->GetTimerManager().TimerExists(timerHandle) && !Controller->GetWorld()->GetTimerManager().TimerExists(timerHandle))
			{
				return;
			}

			UPathFollowingComponent* PFollowComp = InitNavigationControl(*Controller);
			const bool bAlreadyAtGoal = PFollowComp->HasReached(Goal, EPathFollowingReachMode::OverlapAgent);
			if (bAlreadyAtGoal || Controller->GetPawn() == nullptr)
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Goal);
				Controller->GetWorld()->GetTimerManager().ClearTimer(timerHandle);
				Controller->GetWorld()->GetTimerManager().ClearTimer(timerHandle1);
			}
		},
		0.5f,
		true,
		0.0f
	);
}
