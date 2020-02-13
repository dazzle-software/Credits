// Copyright (c) 2020 - 2021 Dazzle Software, LLC. All Rights Reserved.

#include "CreditsModule.h"
#include "Modules/ModuleManager.h"
#include "CreditsManager.h"

/**
 * Closing Credits Module
 */
class FCreditsModule : public ICreditsModule
{
public:

	/**
	 * Called right after the module DLL has been loaded and the module object has been created
	 */
	virtual void StartupModule() override
	{
		UE_LOG(ClosingCreditsLog, Warning, TEXT("FCreditsModule::StartupModule"));
	}

	/**
	 * Called before the module is unloaded, right before the module object is destroyed.
	 */
	virtual void ShutdownModule() override
	{
		UE_LOG(ClosingCreditsLog, Warning, TEXT("FCreditsModule::ShutdownModule"));
	}
};

//IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, Credits, "Credits" );
IMPLEMENT_MODULE( FCreditsModule, Credits );
DEFINE_LOG_CATEGORY(ClosingCreditsLog);