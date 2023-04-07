// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "MyAIBlueprintHelperLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MYTEST_API UMyAIBlueprintHelperLibrary : public UAIBlueprintHelperLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "My|AI|Navigation")
		static void MySimpleMoveToLocation1(AController* Controller, const FVector& Goal);

	UFUNCTION(BlueprintCallable, Category = "My|AI|Navigation")
		static void MySimpleMoveToLocation2(AController* Controller, const FVector& Goal);

	UFUNCTION(BlueprintCallable, Category = "My|AI|Navigation")
		static void MySimpleMoveToLocation3(AController* Controller, const FVector& Goal, const FVector& Goal1);
};
