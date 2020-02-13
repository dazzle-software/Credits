// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "FCreditsProperties.generated.h"

USTRUCT(BlueprintType)
struct CREDITS_API FCreditsProperties
{
	GENERATED_BODY()

	/**
	 * Called right after the module DLL has been loaded and the module object has been created
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Credits|Properties")
	int32 MatchNumber;
};