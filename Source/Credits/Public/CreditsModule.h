// Copyright (c) 2020 - 2021 Dazzle Software, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "CreditsManager.h"

//MEDIEVAL_API DECLARE_LOG_CATEGORY_EXTERN(Medieval, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(ClosingCreditsLog, Log, All);

extern const FName CreditsAppIdentifier;

class ULevel;

/**
 * Foliage Edit mode module interface
 */
class ICreditsModule : public IModuleInterface
{
public:

#if WITH_EDITOR
	/** Move the selected foliage to the specified level */
	// virtual void MoveSelectedFoliageToLevel(ULevel* InTargetLevel) = 0;
	// virtual bool CanMoveSelectedFoliageToLevel(ULevel* InTargetLevel) const = 0;
#endif
};