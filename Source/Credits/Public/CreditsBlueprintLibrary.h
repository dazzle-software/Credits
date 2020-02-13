// Copyright (c) 2020 - 2021 Dazzle Software, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptInterface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Templates/SubclassOf.h"
#include "Kismet/GameplayStatics.h"
#include "Classes/FCreditsProperties.h" // @todo still WIP while we refactor and get c++ properties using unreal macros.
#include "CreditsManager.h"
#include "CreditsBlueprintLibrary.generated.h"

/*
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/

class AActor;

UCLASS(meta = (ScriptName = "CreditsLibrary"))
class /*CREDITS_API*/ UCreditsBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/**
	 * Break Credits General Settings.
	 * @param	SpeedCurve
	 * @param	OpacityCurve
	 * @param	VolumeCurve
	 * @param	CreditsStartingPosition
	 * @param	TimeDilationEffectsCredits
	 * @param	AutoPlayMusic
	 * @param	RestartMusicAtEnd
	 * @param	EndCreditsOnEndReached
	 * @param	StopMusicOnCreditsEnded
	 * @param	StopQueueingMusicWhenCreditsEnded
	 * @return	FCreditsGeneralSettings
	 */
	// Checked
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsGeneralSettings(FCreditsGeneralSettings GeneralSettings, UCurveFloat*& SpeedCurve, UCurveFloat*& OpacityCurve, UCurveFloat*& VolumeCurve, ECreditsStartingPosition& CreditsStartingPosition, bool& TimeDilationEffectsCredits, bool& AutoPlayMusic, bool& RestartMusicAtEnd, bool& EndCreditsOnEndReached, bool& StopMusicOnCreditsEnded, bool& StopQueueingMusicWhenCreditsEnded);

	/**
	 * Make Credits General Settings.
	 * @param	SpeedCurve
	 * @param	OpacityCurve
	 * @param	VolumeCurve
	 * @param	CreditsStartingPosition
	 * @param	TimeDilationEffectsCredits
	 * @param	AutoPlayMusic
	 * @param	RestartMusicAtEnd
	 * @param	EndCreditsOnEndReached
	 * @param	StopMusicOnCreditsEnded
	 * @param	StopQueueingMusicWhenCreditsEnded
	 * @return	FCreditsGeneralSettings
	 */
	// Checked
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (SpeedCurve = "CreditsSpeedCurve.CreditsSpeedCurve", OpacityCurve = "CreditsOpacityCurve.CreditsOpacityCurve", VolumeCurve = "MusicVolumeCurve.MusicVolumeCurve", CreditsStartingPosition = "Top", TimeDilationEffectsCredits = true, AutoPlayMusic = true, RestartMusicAtEnd = true, EndCreditsOnEndReached = true, StopMusicOnCreditsEnded = false, StopQueueingMusicWhenCreditsEnded = true, NativeMakeFunc))
	static FCreditsGeneralSettings MakeCreditsGeneralSettings(UCurveFloat* SpeedCurve, UCurveFloat* OpacityCurve, UCurveFloat* VolumeCurve, ECreditsStartingPosition CreditsStartingPosition, bool TimeDilationEffectsCredits, bool AutoPlayMusic, bool RestartMusicAtEnd, bool EndCreditsOnEndReached, bool StopMusicOnCreditsEnded, bool StopQueueingMusicWhenCreditsEnded);

	/**
	 * Break Credits Image Properties.
	 * @param	Image
	 * @param	ImageSizeOverride
	 * @param	ImageSizeProperties
	 * @return	FCreditsImageProperties
	 */
	// Checked
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsImageProperties(FCreditsImageProperties ImageProperties, UTexture2D*& Image, bool& ImageSizeOverride, FVector2D& ImageSizeProperties);

	/**
	 * Make Credits Image Properties.
	 * @param	Image
	 * @param	ImageSizeOverride
	 * @param	ImageSizeProperties
	 * @return	FCreditsImageProperties
	 */
	// Checked
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Image = "", ImageSizeOverride = false, ImageSizeProperties = (5.0f, 4.0f), Keywords = "construct build", NativeMakeFunc))
	static FCreditsImageProperties MakeCreditsImageProperties(UTexture2D* Image, bool ImageSizeOverride, FVector2D ImageSizeProperties);

	/**
	 * Break Credits Music.
	 * @param	Audio
	 * @param	QueueMode
	 * @param	StartTime
	 * @param	PlayDelay
	 * @return	FCreditsMusic
	 */
	// Checked
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsMusic(FCreditsMusic CreditsMusic, USoundWave*& Audio, ECreditsSoundQueueMode& QueueMode, float& StartTime, float& PlayDelay);

	/**
	 * Make Credits Music.
	 * @param	Audio
	 * @param	QueueMode
	 * @param	StartTime
	 * @param	PlayDelay
	 * @return	FCreditsMusic
	 */
	// Checked
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsMusic MakeCreditsMusic(USoundWave* Audio, ECreditsSoundQueueMode QueueMode, float StartTime, float PlayDelay);

	/**
	 * Break Credits Name Overrides.
	 * @param	ParentSection
	 * @param	ParentRole
	 * @param	NameToOverride
	 * @param	OverrideData
	 * @return	FCreditsNameOverrides
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsNameOverrides(FCreditsNameOverrides CreditsNameOverrides, FName& ParentSection, FName& ParentRole, FName& NameToOverride, FCreditsNameTextObject& OverrideData);

	/**
	 * Make Credits Name Overrides.
	 * @param	ParentSection
	 * @param	ParentRole
	 * @param	NameToOverride
	 * @param	OverrideData
	 * @return	FCreditsNameOverrides
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsNameOverrides MakeCreditsNameOverrides(FName ParentSection, FName ParentRole, FName NameToOverride, FCreditsNameTextObject OverrideData);

	/**
	 * Break Credits Name Text Object.
	 * @param	TextProperties
	 * @param	ImageProperties
	 * @param	Padding
	 * @return	FCreditsNameTextObject
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsNameTextObject(FCreditsNameTextObject CreditsNameTextObject, FCreditsTextProperties& TextProperties, FCreditsImageProperties& ImageProperties, FCreditsPaddingMargin& Padding);

	/**
	 * Make Credits Name Text Object.
	 * @param	TextProperties
	 * @param	ImageProperties
	 * @param	Padding
	 * @return	FCreditsNameTextObject
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsNameTextObject MakeCreditsNameTextObject(FCreditsTextProperties TextProperties, FCreditsImageProperties ImageProperties, FCreditsPaddingMargin Padding);

	/**
	 * Break Credits Overrides.
	 * @param	SectionOverride
	 * @param	IsOverridingSection
	 * @param	RoleOverrides
	 * @param	NameOverrides
	 * @return	FCreditsOverrides
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsOverrides(FCreditsOverrides Overrides, FCreditsSectionOverride& SectionOverride, bool& IsOverridingSection, TArray<FCreditsRoleOverride>& RoleOverrides, TArray<FCreditsNameOverrides>& NameOverrides);

	/**
	 * Make Credits Overrides.
	 * @param	SectionOverride
	 * @param	IsOverridingSection
	 * @param	RoleOverrides
	 * @param	NameOverrides
	 * @return	FCreditsOverrides
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsOverrides MakeCreditsOverrides(FCreditsSectionOverride SectionOverride, bool IsOverridingSection, TArray<FCreditsRoleOverride> RoleOverrides, TArray<FCreditsNameOverrides> NameOverrides);

	/**
	 * Break Credits Padding Margin.
	 * @param	Left
	 * @param	Top
	 * @param	Right
	 * @param	Bottom
	 * @return	FCreditsPaddingMargin
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsPaddingMargin(FCreditsPaddingMargin Padding, float& Left, float& Top, float& Right, float& Bottom);

	/**
	 * Make Credits Padding Margin.
	 * @param	Left
	 * @param	Top
	 * @param	Right
	 * @param	Bottom
	 * @return	FCreditsPaddingMargin
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsPaddingMargin MakeCreditsPaddingMargin(float Left, float Top, float Right, float Bottom);

	/**
	 * Break Credits Role.
	 * @param	RoleProperties
	 * @param	PlayedByNames
	 * @return	FCreditsRole
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsRole(FCreditsRole CreditsRole, FCreditsRoleDefaults& RoleProperties, TArray<FCreditsNameTextObject>& PlayedByNames);

	/**
	 * Make Credits Role.
	 * @param	RoleProperties
	 * @param	PlayedByNames
	 * @return	FCreditsRole
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsRole MakeCreditsRole(FCreditsRoleDefaults RoleProperties, TArray<FCreditsNameTextObject> PlayedByNames);

	/**
	 * Break Credits Role Defaults.
	 * @param	Role
	 * @param	RolePosition
	 * @param	DisplayRoleName
	 * @return	FCreditsRoleDefaults
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsRoleDefaults(FCreditsRoleDefaults RoleDefaults, FCreditsTextObject& Role, ECreditsTextPosition& RolePosition, bool& DisplayRoleName);

	/**
	 * Make Credits Role Defaults.
	 * @param	Role
	 * @param	RolePosition
	 * @param	DisplayRoleName
	 * @return	FCreditsRoleDefaults
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsRoleDefaults MakeCreditsRoleDefaults(FCreditsTextObject Role, ECreditsTextPosition RolePosition, bool DisplayRoleName);

	/**
	 * Break Credits Role Override.
	 * @param	ParentSection
	 * @param	RoleToOverride
	 * @param	OverrideData
	 * @return	FCreditsRoleOverride
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsRoleOverride(FCreditsRoleOverride CreditsRoleOverride, FName& ParentSection, FName& RoleToOverride, FCreditsRoleDefaults& OverrideData);

	/**
	 * Make Credits Role Override.
	 * @param	ParentSection
	 * @param	RoleToOverride
	 * @param	OverrideData
	 * @return	FCreditsRoleOverride
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsRoleOverride MakeCreditsRoleOverride(FName ParentSection, FName RoleToOverride, FCreditsRoleDefaults OverrideData);

	/**
	 * Break Credits Role Struct Simple.
	 * @param	Role
	 * @param	DisplayRoleName
	 * @param	PlayedBy
	 * @return	FCreditsRoleStructSimple
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsRoleStructSimple(FCreditsRoleStructSimple CreditsRoleStructSimple, FCreditsTextObjectSimple& Role, bool& DisplayRoleName, TArray<FCreditsTextObjectSimple>& PlayedBy);

	/**
	 * Make Credits Role Struct Simple.
	 * @param	Role
	 * @param	DisplayRoleName
	 * @param	PlayedBy
	 * @return	FCreditsRoleStructSimple
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsRoleStructSimple MakeCreditsRoleStructSimple(FCreditsTextObjectSimple Role, bool DisplayRoleName, TArray<FCreditsTextObjectSimple> PlayedBy);

	/**
	 * Break Credits Section.
	 * @param	SectionProperties
	 * @param	Roles
	 * @return	FCreditsSection
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsSection(FCreditsSection CreditsSection, FCreditsSectionDefaults& SectionProperties, TArray<FCreditsRole>& Roles);

	/**
	 * Make Credits Section.
	 * @param	SectionProperties
	 * @param	Roles
	 * @return	FCreditsSection
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsSection MakeCreditsSection(FCreditsSectionDefaults SectionProperties, TArray<FCreditsRole> Roles);

	/**
	 * Break Credits Section Defaults.
	 * @param	Title
	 * @param	TitlePosition
	 * @param	SectionPadding
	 * @return	FCreditsSectionDefaults
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsSectionDefaults(FCreditsSectionDefaults CreditsSectionDefaults, FCreditsTextObject& Title, ECreditsStartingPosition& TitlePosition, FCreditsPaddingMargin& SectionPadding);

	/**
	 * Make Credits Section Defaults.
	 * @param	Title
	 * @param	TitlePosition
	 * @param	SectionPadding
	 * @return	FCreditsSectionDefaults
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsSectionDefaults MakeCreditsSectionDefaults(FCreditsTextObject Title, ECreditsStartingPosition TitlePosition, FCreditsPaddingMargin SectionPadding);

	/**
	 * Break Credits Section Override.
	 * @param	OverrideData
	 * @return	FCreditsSectionOverride
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsSectionOverride(FCreditsSectionOverride CreditsSectionOverride, FCreditsSectionDefaults& OverrideData);

	/**
	 * Make Credits Section Override.
	 * @param	OverrideData
	 * @return	FCreditsSectionOverride
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsSectionOverride MakeCreditsSectionOverride(FCreditsSectionDefaults OverrideData);

	/**
	 * Break Credits Section Simple.
	 * @param	Title
	 * @param	Roles
	 * @return	FCreditsSectionSimple
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsSectionSimple(FCreditsSectionSimple CreditsSectionSimple, FCreditsTextObjectSimple& Title, TArray<FCreditsRoleStructSimple>& Roles);

	/**
	 * Make Credits Section Simple.
	 * @param	Title
	 * @param	Roles
	 * @return	FCreditsSectionSimple
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsSectionSimple MakeCreditsSectionSimple(FCreditsTextObjectSimple Title, TArray<FCreditsRoleStructSimple> Roles);

	/**
	 * Break Credits Text Object.
	 * @param	TextProperties
	 * @param	ImageProperties
	 * @param	Padding
	 * @return	FCreditsTextObject
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsTextObject(FCreditsTextObject CreditsTextObject, FCreditsTextProperties& TextProperties, FCreditsImageProperties& ImageProperties, FCreditsPaddingMargin& Padding);

	/**
	 * Make Credits Text Object.
	 * @param	TextProperties
	 * @param	ImageProperties
	 * @param	Padding
	 * @return	FCreditsTextObject
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsTextObject MakeCreditsTextObject(FCreditsTextProperties TextProperties, FCreditsImageProperties ImageProperties, FCreditsPaddingMargin Padding);

	/**
	 * Break Credits Text Object Simple.
	 * @param	Text
	 * @param	ImageProperties
	 * @return	FCreditsTextObjectSimple
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsTextObjectSimple(FCreditsTextObjectSimple CreditsTextObjectSimple, FString& Text, FCreditsImageProperties& ImageProperties);

	/**
	 * Make Credits Text Object Simple.
	 * @param	Text
	 * @param	ImageProperties
	 * @return	FCreditsTextObjectSimple
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (Keywords = "construct build", NativeMakeFunc))
	static FCreditsTextObjectSimple MakeCreditsTextObjectSimple(FString Text, FCreditsImageProperties ImageProperties);

	/**
	 * Break Credits Text Properties.
	 * @param	Title
	 * @param	Font
	 * @param	FontMaterial
	 * @param	FontSize
	 * @param	Color
	 * @return	FCreditsTextProperties
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (NativeBreakFunc))
	static void BreakCreditsTextProperties(FCreditsTextProperties Properties, FString& Title, UFont*& Font, UMaterialInterface*& FontMaterial, int& FontSize, FLinearColor& Color);

	/**
	 * Make Credits Text Properties.
	 * @param	Title
	 * @param	Font
	 * @param	FontMaterial
	 * @param	FontSize
	 * @param	Color
	 * @return FCreditsTextProperties
	 */
	UFUNCTION(BlueprintPure, Category = "Credits|Utilities|Struct", meta = (FontSize = 24, Keywords = "construct build", NativeMakeFunc))
	static FCreditsTextProperties MakeCreditsTextProperties(FString Title, UFont* Font, UMaterialInterface* FontMaterial, int FontSize, FLinearColor Color);

	/////////////////////////////
	// End Break/Make Function.
	/////////////////////////////

	/**
	 * Padding Margin To Margin.
	 * @param	ActorsToRecord	The actors to record
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Padding Margin To Margin", Keywords = "Padding Margin To Margin"), Category = "Default")
	static void PaddingMarginToMargin(FCreditsPaddingMargin A, UObject* WorldContextObject, FMargin& B);

	/**
	 * Simple Roles to Complex Roles.
	 * @param	ActorsToRecord	The actors to record
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Simple Roles to Complex Roles", Keywords = "Simple Roles to Complex Roles"), Category = "Default")
	static void SimpleRolesToComplexRoles(TArray<FCreditsRoleStructSimple> SimpleRole, TArray<FCreditsRoleOverride> RoleOverrides, TArray<FCreditsNameOverrides> NameOverrides, UObject* WorldContextObject, TArray<FCreditsRole>& ComplexRole);

	/**
	 * Simple Text Object (Role) to Complex Text Object.
	 * @param	ActorsToRecord	The actors to record
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Simple Text Object (Role) To Complex Text Object", Keywords = "Simple Text Object To Complex Text Object"), Category = "Default")
	static void SimpleTextObjectRoleToComplexTextObject(FCreditsTextObjectSimple Simple, UObject* WorldContextObject, FCreditsTextObject& Complex);

	/**
	 * Simple Played By Names to Complex Played By Names.
	 * @param	ActorsToRecord	The actors to record
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Simple Played By Names to Complex Played By Names", Keywords = "Simple Played By Names to Complex Played By Names"), Category = "Default")
	static void SimplePlayedByNamesToComplexPlayedByNames(TArray<FCreditsTextObjectSimple> Simple, TArray<FCreditsNameOverrides> Overrides, UObject* WorldContextObject, TArray<FCreditsNameTextObject>& Complex);

	/**
	 * Simple Credits Section to Complex Credits Section.
	 * @param	ActorsToRecord	The actors to record
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Simple Credits Section to Complex Credits Section", Keywords = "Simple Credits Section to Complex Credits Section"), Category = "Default")
	static void SimpleCreditsSectionToComplexCreditsSection(FCreditsSectionSimple Simple, FCreditsOverrides Overrides, UObject* WorldContextObject, FCreditsSection& Complex);

	/**
	 * Simple Text Object (Title) to Complex Text Object.
	 * @param	ActorsToRecord	The actors to record
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Simple Text Object (Title) to Complex Text Object", Keywords = "Simple Text Object (Title) to Complex Text Object"), Category = "Default")
	static void SimpleTextObjectTitleToComplexTextObject(FCreditsTextObjectSimple Simple, UObject* WorldContextObject, FCreditsTextObject& Complex);

	/**
	 * Get Overriden Roles.
	 * @param	ActorsToRecord	The actors to record
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Get Overriden Roles", Keywords = "Get Overriden Roles"), Category = "Default")
	static void GetOverridenRoles(FName Section, UObject* WorldContextObject, TArray<FCreditsRoleOverride>& OverridenRoles);

	/**
	 * Get Override Data for Role.
	 * @param	ActorsToRecord	The actors to record
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Get Override Data for Role", Keywords = "Get Override Data for Role"), Category = "Default")
	static void GetOverrideDataForRole(const FString RoleName, TArray<FCreditsRoleOverride> OverridenRoles, UObject* WorldContextObject, FCreditsRoleDefaults& Data, bool& IsOverriding);

	/**
	 * Get Overriden Names.
	 * @param	ActorsToRecord	The actors to record
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Get Overriden Names", Keywords = "Get Overriden Names"), Category = "Default")
	static void GetOverridenNames(FName Section, UObject* WorldContextObject, TArray<FCreditsNameOverrides>& OverridenRoles);

	/**
	 * Get Roles in Section.
	 * @param	ActorsToRecord	The actors to record
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Get Roles in Section", Keywords = "Get Roles in Section"), Category = "Default")
	static void GetRolesInSection(FName Section, UObject* WorldContextObject, TArray<FCreditsRoleStructSimple>& Roles);

	/**
	 * Get Override Data for Name.
	 * @param	ActorsToRecord	The actors to record
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Get Override Data for Name", Keywords = "Get Override Data for Name"), Category = "Default")
	static void GetOverrideDataForName(const FString Name, TArray<FCreditsNameOverrides> OverridenNames, UObject* WorldContextObject, FCreditsNameOverrides& Data, bool& IsOverriding);
};