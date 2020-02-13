// Copyright (c) 2020 - 2021 Dazzle Software, LLC. All Rights Reserved.

#include "CreditsBlueprintLibrary.h"
#include "Classes/FCreditsProperties.h" // @todo still WIP while we refactor and get c++ properties using unreal macros.
#include "CreditsModule.h"

UCreditsBlueprintLibrary::UCreditsBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

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
	void UCreditsBlueprintLibrary::BreakCreditsGeneralSettings(FCreditsGeneralSettings GeneralSettings, UCurveFloat*& SpeedCurve, UCurveFloat*& OpacityCurve, UCurveFloat*& VolumeCurve, ECreditsStartingPosition& CreditsStartingPosition, bool& TimeDilationEffectsCredits, bool& AutoPlayMusic, bool& RestartMusicAtEnd, bool& EndCreditsOnEndReached, bool& StopMusicOnCreditsEnded, bool& StopQueueingMusicWhenCreditsEnded)
	{
		SpeedCurve = GeneralSettings.SpeedCurve;
		OpacityCurve = GeneralSettings.OpacityCurve;
		VolumeCurve = GeneralSettings.VolumeCurve;
		CreditsStartingPosition = GeneralSettings.CreditsStartingPosition;
		TimeDilationEffectsCredits = GeneralSettings.TimeDilationEffectsCredits;
		AutoPlayMusic = GeneralSettings.AutoPlayMusic;
		RestartMusicAtEnd = GeneralSettings.RestartMusicAtEnd;
		EndCreditsOnEndReached = GeneralSettings.EndCreditsOnEndReached;
		StopMusicOnCreditsEnded = GeneralSettings.StopMusicOnCreditsEnded;
		StopQueueingMusicWhenCreditsEnded = GeneralSettings.StopQueueingMusicWhenCreditsEnded;
	}

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
	FCreditsGeneralSettings UCreditsBlueprintLibrary::MakeCreditsGeneralSettings(UCurveFloat* SpeedCurve, UCurveFloat* OpacityCurve, UCurveFloat* VolumeCurve, ECreditsStartingPosition CreditsStartingPosition, bool TimeDilationEffectsCredits, bool AutoPlayMusic, bool RestartMusicAtEnd, bool EndCreditsOnEndReached, bool StopMusicOnCreditsEnded, bool StopQueueingMusicWhenCreditsEnded)
	{
		return FCreditsGeneralSettings(SpeedCurve, OpacityCurve, VolumeCurve, CreditsStartingPosition, TimeDilationEffectsCredits, AutoPlayMusic, RestartMusicAtEnd, EndCreditsOnEndReached, StopMusicOnCreditsEnded, StopQueueingMusicWhenCreditsEnded);
	}

	/**
	 * Break Credits Image Properties.
	 * @param	Image
	 * @param	ImageSizeOverride
	 * @param	ImageSizeProperties
	 * @return	FCreditsImageProperties
	 */
	void UCreditsBlueprintLibrary::BreakCreditsImageProperties(FCreditsImageProperties ImageProperties, UTexture2D*& Image, bool& ImageSizeOverride, FVector2D& ImageSizeProperties)
	{
		Image = ImageProperties.Image;
		ImageSizeOverride = ImageProperties.ImageSizeOverride;
		ImageSizeProperties = ImageProperties.ImageSizeProperties;
	}

	/**
	 * Make Credits Image Properties.
	 * @param	Image
	 * @param	ImageSizeOverride
	 * @param	ImageSizeProperties
	 * @return	FCreditsImageProperties
	 */
	FCreditsImageProperties UCreditsBlueprintLibrary::MakeCreditsImageProperties(UTexture2D* Image, bool ImageSizeOverride, FVector2D ImageSizeProperties)
	{
		return FCreditsImageProperties(Image, ImageSizeOverride, ImageSizeProperties);
	}

	/**
	 * Break Credits Music.
	 * @param	Audio
	 * @param	QueueMode
	 * @param	StartTime
	 * @param	PlayDelay
	 * @return	FCreditsMusic
	 */
	 
	void UCreditsBlueprintLibrary::BreakCreditsMusic(FCreditsMusic CreditsMusic, USoundWave*& Audio, ECreditsSoundQueueMode& QueueMode, float& StartTime, float& PlayDelay)
	{
		Audio = CreditsMusic.Audio;
		QueueMode = CreditsMusic.QueueMode;
		StartTime = CreditsMusic.StartTime;
		PlayDelay = CreditsMusic.PlayDelay;
	}

	/**
	 * Make Credits Music.
	 * @param	Audio
	 * @param	QueueMode
	 * @param	StartTime
	 * @param	PlayDelay
	 * @return	FCreditsMusic
	 */
	FCreditsMusic UCreditsBlueprintLibrary::MakeCreditsMusic(USoundWave* Audio, ECreditsSoundQueueMode QueueMode, float StartTime, float PlayDelay)
	{
		return FCreditsMusic(Audio, QueueMode, StartTime, PlayDelay);
	}

	/**
	 * Break Credits Name Overrides.
	 * @param	ParentSection
	 * @param	ParentRole
	 * @param	NameToOverride
	 * @param	OverrideData
	 * @return	FCreditsNameOverrides
	 */
	void UCreditsBlueprintLibrary::BreakCreditsNameOverrides(FCreditsNameOverrides CreditsNameOverrides, FName& ParentSection, FName& ParentRole, FName& NameToOverride, FCreditsNameTextObject& OverrideData)
	{
		ParentSection = CreditsNameOverrides.ParentSection;
		ParentRole = CreditsNameOverrides.ParentRole;
		NameToOverride = CreditsNameOverrides.NameToOverride;
		OverrideData = CreditsNameOverrides.OverrideData;
	}

	/**
	 * Make Credits Name Overrides.
	 * @param	ParentSection
	 * @param	ParentRole
	 * @param	NameToOverride
	 * @param	OverrideData
	 * @return	FCreditsNameOverrides
	 */
	FCreditsNameOverrides UCreditsBlueprintLibrary::MakeCreditsNameOverrides(FName ParentSection, FName ParentRole, FName NameToOverride, FCreditsNameTextObject OverrideData)
	{
		return FCreditsNameOverrides(ParentSection, ParentRole, NameToOverride, OverrideData);
	}

	/**
	 * Break Credits Name Text Object.
	 * @param	TextProperties
	 * @param	ImageProperties
	 * @param	Padding
	 * @return	FCreditsNameTextObject
	 */
	void UCreditsBlueprintLibrary::BreakCreditsNameTextObject(FCreditsNameTextObject CreditsNameTextObject, FCreditsTextProperties& TextProperties, FCreditsImageProperties& ImageProperties, FCreditsPaddingMargin& Padding)
	{
		TextProperties = CreditsNameTextObject.TextProperties;
		ImageProperties = CreditsNameTextObject.ImageProperties;
		Padding = CreditsNameTextObject.Padding;
	}

	/**
	 * Make Credits Name Text Object.
	 * @param	TextProperties
	 * @param	ImageProperties
	 * @param	Padding
	 * @return	FCreditsNameTextObject
	 */
	FCreditsNameTextObject UCreditsBlueprintLibrary::MakeCreditsNameTextObject(FCreditsTextProperties TextProperties, FCreditsImageProperties ImageProperties, FCreditsPaddingMargin Padding)
	{
		return FCreditsNameTextObject(TextProperties, ImageProperties, Padding);
	}

	/**
	 * Break Credits Overrides.
	 * @param	SectionOverride
	 * @param	IsOverridingSection
	 * @param	RoleOverrides
	 * @param	NameOverrides
	 * @return	FCreditsOverrides
	 */
	void UCreditsBlueprintLibrary::BreakCreditsOverrides(FCreditsOverrides Overrides, FCreditsSectionOverride& SectionOverride, bool& IsOverridingSection, TArray<FCreditsRoleOverride>& RoleOverrides, TArray<FCreditsNameOverrides>& NameOverrides)
	{
		SectionOverride = Overrides.SectionOverride;
		IsOverridingSection = Overrides.IsOverridingSection;
		RoleOverrides = Overrides.RoleOverrides;
		NameOverrides = Overrides.NameOverrides;
	}

	/**
	 * Make Credits Overrides.
	 * @param	SectionOverride
	 * @param	IsOverridingSection
	 * @param	RoleOverrides
	 * @param	NameOverrides
	 * @return	FCreditsOverrides
	 */
	FCreditsOverrides UCreditsBlueprintLibrary::MakeCreditsOverrides(FCreditsSectionOverride SectionOverride, bool IsOverridingSection, TArray<FCreditsRoleOverride> RoleOverrides, TArray<FCreditsNameOverrides> NameOverrides)
	{
		return FCreditsOverrides(SectionOverride, IsOverridingSection, RoleOverrides, NameOverrides);
	}

	/**
	 * Break Credits Padding Margin.
	 * @param	Left
	 * @param	Top
	 * @param	Right
	 * @param	Bottom
	 * @return	FCreditsPaddingMargin
	 */
	void UCreditsBlueprintLibrary::BreakCreditsPaddingMargin(FCreditsPaddingMargin Padding, float& Left, float& Top, float& Right, float& Bottom)
	{
		Left = Padding.Left;
		Top = Padding.Top;
		Right = Padding.Right;
		Bottom = Padding.Bottom;
	}

	/**
	 * Make Credits Padding Margin.
	 * @param	Left
	 * @param	Top
	 * @param	Right
	 * @param	Bottom
	 * @return	FCreditsPaddingMargin
	 */
	FCreditsPaddingMargin UCreditsBlueprintLibrary::MakeCreditsPaddingMargin(float Left, float Top, float Right, float Bottom)
	{
		return FCreditsPaddingMargin(Left, Top, Right, Bottom);
	}

	/**
	 * Break Credits Role.
	 * @param	RoleProperties
	 * @param	PlayedByNames
	 * @return	FCreditsRole
	 */
	void UCreditsBlueprintLibrary::BreakCreditsRole(FCreditsRole CreditsRole, FCreditsRoleDefaults& RoleProperties, TArray<FCreditsNameTextObject>& PlayedByNames)
	{
		RoleProperties = CreditsRole.RoleProperties;
		PlayedByNames = CreditsRole.PlayedByNames;
	}

	/**
	 * Make Credits Role.
	 * @param	RoleProperties
	 * @param	PlayedByNames
	 * @return	FCreditsRole
	 */
	FCreditsRole UCreditsBlueprintLibrary::MakeCreditsRole(FCreditsRoleDefaults RoleProperties, TArray<FCreditsNameTextObject> PlayedByNames)
	{
		return FCreditsRole(RoleProperties, PlayedByNames);
	}

	/**
	 * Break Credits Role Defaults.
	 * @param	Role
	 * @param	RolePosition
	 * @param	DisplayRoleName
	 * @return	FCreditsRoleDefaults
	 */
	void UCreditsBlueprintLibrary::BreakCreditsRoleDefaults(FCreditsRoleDefaults RoleDefaults, FCreditsTextObject& Role, ECreditsTextPosition& RolePosition, bool& DisplayRoleName)
	{
		Role = RoleDefaults.Role;
		RolePosition = RoleDefaults.RolePosition;
		DisplayRoleName = RoleDefaults.DisplayRoleName;
	}

	/**
	 * Make Credits Role Defaults.
	 * @param	Role
	 * @param	RolePosition
	 * @param	DisplayRoleName
	 * @return	FCreditsRoleDefaults
	 */
	FCreditsRoleDefaults UCreditsBlueprintLibrary::MakeCreditsRoleDefaults(FCreditsTextObject Role, ECreditsTextPosition RolePosition, bool DisplayRoleName)
	{
		return FCreditsRoleDefaults(Role, RolePosition, DisplayRoleName);
	}

	/**
	 * Break Credits Role Override.
	 * @param	ParentSection
	 * @param	RoleToOverride
	 * @param	OverrideData
	 * @return	FCreditsRoleOverride
	 */
	void UCreditsBlueprintLibrary::BreakCreditsRoleOverride(FCreditsRoleOverride CreditsRoleOverride, FName& ParentSection, FName& RoleToOverride, FCreditsRoleDefaults& OverrideData)
	{
		ParentSection = CreditsRoleOverride.ParentSection;
		RoleToOverride = CreditsRoleOverride.RoleToOverride;
		OverrideData = CreditsRoleOverride.OverrideData;
	}

	/**
	 * Make Credits Role Override.
	 * @param	ParentSection
	 * @param	RoleToOverride
	 * @param	OverrideData
	 * @return	FCreditsRoleOverride
	 */
	FCreditsRoleOverride UCreditsBlueprintLibrary::MakeCreditsRoleOverride(FName ParentSection, FName RoleToOverride, FCreditsRoleDefaults OverrideData)
	{
		return FCreditsRoleOverride(ParentSection, RoleToOverride, OverrideData);
	}

	/**
	 * Break Credits Role Struct Simple.
	 * @param	Role
	 * @param	DisplayRoleName
	 * @param	PlayedBy
	 * @return	FCreditsRoleStructSimple
	 */
	void UCreditsBlueprintLibrary::BreakCreditsRoleStructSimple(FCreditsRoleStructSimple CreditsRoleStructSimple, FCreditsTextObjectSimple& Role, bool& DisplayRoleName, TArray<FCreditsTextObjectSimple>& PlayedBy)
	{
		Role = CreditsRoleStructSimple.Role;
		DisplayRoleName = CreditsRoleStructSimple.DisplayRoleName;
		PlayedBy = CreditsRoleStructSimple.PlayedBy;
	}

	/**
	 * Make Credits Role Struct Simple.
	 * @param	Role
	 * @param	DisplayRoleName
	 * @param	PlayedBy
	 * @return	FCreditsRoleStructSimple
	 */
	FCreditsRoleStructSimple UCreditsBlueprintLibrary::MakeCreditsRoleStructSimple(FCreditsTextObjectSimple Role, bool DisplayRoleName, TArray<FCreditsTextObjectSimple> PlayedBy)
	{
		return FCreditsRoleStructSimple(Role, DisplayRoleName, PlayedBy);
	}

	/**
	 * Break Credits Section.
	 * @param	SectionProperties
	 * @param	Roles
	 * @return	FCreditsSection
	 */
	void UCreditsBlueprintLibrary::BreakCreditsSection(FCreditsSection CreditsSection, FCreditsSectionDefaults& SectionProperties, TArray<FCreditsRole>& Roles)
	{
		SectionProperties = CreditsSection.SectionProperties;
		Roles = CreditsSection.Roles;
	}

	/**
	 * Make Credits Section.
	 * @param	SectionProperties
	 * @param	Roles
	 * @return	FCreditsSection
	 */
	FCreditsSection UCreditsBlueprintLibrary::MakeCreditsSection(FCreditsSectionDefaults SectionProperties, TArray<FCreditsRole> Roles)
	{
		return FCreditsSection(SectionProperties, Roles);
	}

	/**
	 * Break Credits Section Defaults.
	 * @param	Title
	 * @param	TitlePosition
	 * @param	SectionPadding
	 * @return	FCreditsSectionDefaults
	 */
	void UCreditsBlueprintLibrary::BreakCreditsSectionDefaults(FCreditsSectionDefaults CreditsSectionDefaults, FCreditsTextObject& Title, ECreditsStartingPosition& TitlePosition, FCreditsPaddingMargin& SectionPadding)
	{
		Title = CreditsSectionDefaults.Title;
		TitlePosition = CreditsSectionDefaults.TitlePosition;
		SectionPadding = CreditsSectionDefaults.SectionPadding;
	}

	/**
	 * Make Credits Section Defaults.
	 * @param	Title
	 * @param	TitlePosition
	 * @param	SectionPadding
	 * @return	FCreditsSectionDefaults
	 */
	FCreditsSectionDefaults UCreditsBlueprintLibrary::MakeCreditsSectionDefaults(FCreditsTextObject Title, ECreditsStartingPosition TitlePosition, FCreditsPaddingMargin SectionPadding)
	{
		return FCreditsSectionDefaults(Title, TitlePosition, SectionPadding);
	}

	/**
	 * Break Credits Section Override.
	 * @param	OverrideData
	 * @return	FCreditsSectionOverride
	 */
	void UCreditsBlueprintLibrary::BreakCreditsSectionOverride(FCreditsSectionOverride CreditsSectionOverride, FCreditsSectionDefaults& OverrideData)
	{
		OverrideData = CreditsSectionOverride.OverrideData;
	}

	/**
	 * Make Credits Section Override.
	 * @param	OverrideData
	 * @return	FCreditsSectionOverride
	 */
	FCreditsSectionOverride UCreditsBlueprintLibrary::MakeCreditsSectionOverride(FCreditsSectionDefaults OverrideData)
	{
		return FCreditsSectionOverride(OverrideData);
	}

	/**
	 * Break Credits Section Simple.
	 * @param	Title
	 * @param	Roles
	 * @return	FCreditsSectionSimple
	 */
	void UCreditsBlueprintLibrary::BreakCreditsSectionSimple(FCreditsSectionSimple CreditsSectionSimple, FCreditsTextObjectSimple& Title, TArray<FCreditsRoleStructSimple>& Roles)
	{
		Title = CreditsSectionSimple.Title;
		Roles = CreditsSectionSimple.Roles;
	}

	/**
	 * Make Credits Section Simple.
	 * @param	Title
	 * @param	Roles
	 * @return	FCreditsSectionSimple
	 */
	FCreditsSectionSimple UCreditsBlueprintLibrary::MakeCreditsSectionSimple(FCreditsTextObjectSimple Title, TArray<FCreditsRoleStructSimple> Roles)
	{
		return FCreditsSectionSimple(Title, Roles);
	}

	/**
	 * Break Credits Text Object.
	 * @param	TextProperties
	 * @param	ImageProperties
	 * @param	Padding
	 * @return	FCreditsTextObject
	 */
	void UCreditsBlueprintLibrary::BreakCreditsTextObject(FCreditsTextObject CreditsTextObject, FCreditsTextProperties& TextProperties, FCreditsImageProperties& ImageProperties, FCreditsPaddingMargin& Padding)
	{
		TextProperties = CreditsTextObject.TextProperties;
		ImageProperties = CreditsTextObject.ImageProperties;
		Padding = CreditsTextObject.Padding;
	}

	/**
	 * Make Credits Text Object.
	 * @param	TextProperties
	 * @param	ImageProperties
	 * @param	Padding
	 * @return	FCreditsTextObject
	 */
	FCreditsTextObject UCreditsBlueprintLibrary::MakeCreditsTextObject(FCreditsTextProperties TextProperties, FCreditsImageProperties ImageProperties, FCreditsPaddingMargin Padding)
	{
		return FCreditsTextObject(TextProperties, ImageProperties, Padding);
	}

	/**
	 * Break Credits Text Object Simple.
	 * @param	Text
	 * @param	ImageProperties
	 * @return	FCreditsTextObjectSimple
	 */
	void UCreditsBlueprintLibrary::BreakCreditsTextObjectSimple(FCreditsTextObjectSimple CreditsTextObjectSimple, FString& Text, FCreditsImageProperties& ImageProperties)
	{
		Text = CreditsTextObjectSimple.Text;
		ImageProperties = CreditsTextObjectSimple.ImageProperties;
	}

	/**
	 * Make Credits Text Object Simple.
	 * @param	Text
	 * @param	ImageProperties
	 * @return	FCreditsTextObjectSimple
	 */
	FCreditsTextObjectSimple UCreditsBlueprintLibrary::MakeCreditsTextObjectSimple(FString Text, FCreditsImageProperties ImageProperties)
	{
		return FCreditsTextObjectSimple(Text, ImageProperties);
	}

	/**
	 * Break Credits Text Properties.
	 * @param	Title
	 * @param	Font
	 * @param	FontMaterial
	 * @param	FontSize
	 * @param	Color
	 * @return	FCreditsTextProperties
	 */
	void UCreditsBlueprintLibrary::BreakCreditsTextProperties(FCreditsTextProperties Properties, FString& Title, UFont*& Font, UMaterialInterface*& FontMaterial, int& FontSize, FLinearColor& Color)
	{
		Title = Properties.Title;
		Font = Properties.Font;
		FontMaterial = Properties.FontMaterial;
		FontSize = Properties.FontSize;
		Color = Properties.Color;
	}

	/**
	 * Make Credits Text Properties.
	 * @param	Title
	 * @param	Font
	 * @param	FontMaterial
	 * @param	FontSize
	 * @param	Color
	 * @return	FCreditsTextProperties
	 */
	FCreditsTextProperties UCreditsBlueprintLibrary::MakeCreditsTextProperties(FString Title, UFont* Font, UMaterialInterface* FontMaterial, int FontSize, FLinearColor Color)
	{
		return FCreditsTextProperties(Title, Font, FontMaterial, FontSize, Color);
	}

/**
This function will convert from a Padding Marging to a Margin, which are essentially the same thing.
We use Padding Margin, which is a custom struct, but widgets need Margin. This is a workaround to UE-26443.
*/
void UCreditsBlueprintLibrary::PaddingMarginToMargin(FCreditsPaddingMargin A, UObject* WorldContextObject, FMargin& B)
{
	//float Left = A.Left;
	//float Top = A.Top;
	//float Right = A.Right;
	//float Bottom = A.Bottom;
	//A* PaddingMargin;
	//BreakCreditsPaddingMargin(A, Left, Top, Right, Bottom);
	//UEdGraphPin
	FMargin MarginAttribute {};
	MarginAttribute.Left = A.Left;
	MarginAttribute.Top = A.Top;
	MarginAttribute.Right = A.Right;
	MarginAttribute.Bottom = A.Bottom;
	B = MarginAttribute;
	//APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(WorldContextObject, 0);
	//return;
}

/**
	TArray<FCreditsRoleOverride>
*/
void UCreditsBlueprintLibrary::SimpleRolesToComplexRoles(TArray<FCreditsRoleStructSimple> SimpleRole, TArray<FCreditsRoleOverride> RoleOverrides, TArray<FCreditsNameOverrides> NameOverrides, UObject* WorldContextObject, TArray<FCreditsRole>& ComplexRole)
{
	/* Set the Role Defaults to the default values in the Role struct */
	FCreditsRoleDefaults RoleDefaults;
	/* TempComplexRoles */
	TArray<FCreditsRoleStructSimple> TempComplexRoles;
	FCreditsProperties GroupMatch;
	GroupMatch.MatchNumber = 10;
	UE_LOG(ClosingCreditsLog, Warning, TEXT("UCreditsBlueprintLibrary::SimpleRolesToComplexRoles"));
	//MatchNumber = 10;
	//CaptureGroupNumber = 10;
	//FontSize = 10;


	for (uint32 Index = 0; Index; ++Index)
	{
		//
	}
	//return;
}

void UCreditsBlueprintLibrary::SimpleTextObjectRoleToComplexTextObject(FCreditsTextObjectSimple Simple, UObject* WorldContextObject, FCreditsTextObject& Complex)
{
	//return;
}

void UCreditsBlueprintLibrary::SimplePlayedByNamesToComplexPlayedByNames(TArray<FCreditsTextObjectSimple> Simple, TArray<FCreditsNameOverrides> Overrides, UObject* WorldContextObject, TArray<FCreditsNameTextObject>& Complex)
{
	//return;
}

void UCreditsBlueprintLibrary::SimpleCreditsSectionToComplexCreditsSection(FCreditsSectionSimple Simple, FCreditsOverrides Overrides, UObject* WorldContextObject, FCreditsSection& Complex)
{
	//return;
}

void UCreditsBlueprintLibrary::SimpleTextObjectTitleToComplexTextObject(FCreditsTextObjectSimple Simple, UObject* WorldContextObject, FCreditsTextObject& Complex)
{
	//return;
}

void UCreditsBlueprintLibrary::GetOverridenRoles(FName Section, UObject* WorldContextObject, TArray<FCreditsRoleOverride>& OverridenRoles)
{
	//return;
}

void UCreditsBlueprintLibrary::GetOverrideDataForRole(const FString RoleName, TArray<FCreditsRoleOverride> OverridenRoles, UObject* WorldContextObject, FCreditsRoleDefaults& Data, bool& IsOverriding)
{
	//return;
}

void UCreditsBlueprintLibrary::GetOverridenNames(FName Section, UObject* WorldContextObject, TArray<FCreditsNameOverrides>& OverridenRoles)
{
	//return;
}

void UCreditsBlueprintLibrary::GetRolesInSection(FName Section, UObject* WorldContextObject, TArray<FCreditsRoleStructSimple>& Roles)
{
	//return;
}

void UCreditsBlueprintLibrary::GetOverrideDataForName(const FString Name, TArray<FCreditsNameOverrides> OverridenNames, UObject* WorldContextObject, FCreditsNameOverrides& Data, bool& IsOverriding)
{
	//return;
}