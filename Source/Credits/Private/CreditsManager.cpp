// Copyright (c) 2019 - 2020 Dazzle Software, LLC. All Rights Reserved.

#include "CreditsManager.h"

FCreditsTextProperties::FCreditsTextProperties(const FString InTitle, UFont* InFont, UMaterialInterface* InFontMaterial, int InFontSize, const FLinearColor& InColor)
{
	Title = InTitle;
	Font = InFont;
	FontMaterial = InFontMaterial;
	FontSize = InFontSize;
	Color = InColor;
}

FCreditsImageProperties::FCreditsImageProperties(UTexture2D* InImage, bool InImageSizeOverride, FVector2D InImageSizeProperties)
{
	Image = InImage;
	ImageSizeOverride = InImageSizeOverride;
	ImageSizeProperties = InImageSizeProperties;
}

FCreditsPaddingMargin::FCreditsPaddingMargin(float InLeft, float InTop, float InRight, float InBottom)
{
	Left = InLeft;
	Top = InTop;
	Right = InRight;
	Bottom = InBottom;
}

FCreditsTextObject::FCreditsTextObject(const FCreditsTextProperties& InTextProperties, const FCreditsImageProperties& InImageProperties, const FCreditsPaddingMargin& InPadding)
{
	TextProperties = InTextProperties;
	ImageProperties = InImageProperties;
	Padding = InPadding;
}

FCreditsRoleDefaults::FCreditsRoleDefaults(const FCreditsTextObject& InRole, const ECreditsTextPosition& InRolePosition, bool InDisplayRoleName)
{
	Role = InRole;
	RolePosition = InRolePosition;
	DisplayRoleName = InDisplayRoleName;
}

FCreditsSectionDefaults::FCreditsSectionDefaults(const FCreditsTextObject& InTitle, const ECreditsStartingPosition& InTitlePosition, const FCreditsPaddingMargin& InSectionPadding)
{
	Title = InTitle;
	TitlePosition = InTitlePosition;
	SectionPadding = InSectionPadding;
}

FCreditsGeneralSettings::FCreditsGeneralSettings(UCurveFloat* InSpeedCurve, UCurveFloat* InOpacityCurve, UCurveFloat* InVolumeCurve, const ECreditsStartingPosition& InCreditsStartingPosition, bool InTimeDilationEffectsCredits, bool InAutoPlayMusic, bool InRestartMusicAtEnd, bool InEndCreditsOnEndReached, bool InStopMusicOnCreditsEnded, bool InStopQueueingMusicWhenCreditsEnded)
{
	SpeedCurve = InSpeedCurve;
	OpacityCurve = InOpacityCurve;
	VolumeCurve = InVolumeCurve;
	CreditsStartingPosition = InCreditsStartingPosition;
	TimeDilationEffectsCredits = InTimeDilationEffectsCredits;
	AutoPlayMusic = InAutoPlayMusic;
	RestartMusicAtEnd = InRestartMusicAtEnd;
	EndCreditsOnEndReached = InEndCreditsOnEndReached;
	StopMusicOnCreditsEnded = InStopMusicOnCreditsEnded;
	StopQueueingMusicWhenCreditsEnded = InStopQueueingMusicWhenCreditsEnded;
}

FCreditsNameTextObject::FCreditsNameTextObject(const FCreditsTextProperties& InTextProperties, const FCreditsImageProperties& InImageProperties, const FCreditsPaddingMargin& InPadding)
{
	TextProperties = InTextProperties;
	ImageProperties = InImageProperties;
	Padding = InPadding;
}

FCreditsMusic::FCreditsMusic(USoundWave* InAudio, const ECreditsSoundQueueMode& InQueueMode, float InStartTime, float InPlayDelay)
{
	Audio = InAudio;
	QueueMode = InQueueMode;
	StartTime = InStartTime;
	PlayDelay = InPlayDelay;
}

FCreditsSectionOverride::FCreditsSectionOverride(const FCreditsSectionDefaults& InOverrideData)
{
	OverrideData = InOverrideData;
}

FCreditsRoleOverride::FCreditsRoleOverride(const FName& InParentSection, const FName& InRoleToOverride, const FCreditsRoleDefaults& InOverrideData)
{
	ParentSection = InParentSection;
	RoleToOverride = InRoleToOverride;
	OverrideData = InOverrideData;
}

FCreditsNameOverrides::FCreditsNameOverrides(const FName& InParentSection, const FName& InParentRole, const FName& InNameToOverride, const FCreditsNameTextObject& InOverrideData)
{
	ParentSection = InParentSection;
	ParentRole = InParentRole;
	NameToOverride = InNameToOverride;
	OverrideData = InOverrideData;
}

FCreditsOverrides::FCreditsOverrides(const FCreditsSectionOverride& InSectionOverride, bool InOverridingSection, TArray<FCreditsRoleOverride>& InRoleOverrides, TArray<FCreditsNameOverrides>& InNameOverrides)
{
	SectionOverride = InSectionOverride;
	IsOverridingSection = InOverridingSection;
	RoleOverrides = InRoleOverrides;
	NameOverrides = InNameOverrides;
}

FCreditsRole::FCreditsRole(const FCreditsRoleDefaults& InRoleProperties, const TArray<FCreditsNameTextObject>& InPlayedByNames)
{
	RoleProperties = InRoleProperties;
	PlayedByNames = InPlayedByNames;
}

FCreditsTextObjectSimple::FCreditsTextObjectSimple(const FString& InText, const FCreditsImageProperties& InImageProperties)
{
	Text = InText;
	ImageProperties = InImageProperties;
}

FCreditsRoleStructSimple::FCreditsRoleStructSimple(const FCreditsTextObjectSimple& InRole, bool InDisplayRoleName, TArray<FCreditsTextObjectSimple>& InPlayedBy)
{
	Role = InRole;
	DisplayRoleName = InDisplayRoleName;
	PlayedBy = InPlayedBy;
}

FCreditsSection::FCreditsSection(const FCreditsSectionDefaults& InSectionProperties, const TArray<FCreditsRole>& InRoles)
{
	SectionProperties = InSectionProperties;
	Roles = InRoles;
}

FCreditsSectionSimple::FCreditsSectionSimple(const FCreditsTextObjectSimple& InTitle, const TArray<FCreditsRoleStructSimple>& InRoles)
{
	Title = InTitle;
	Roles = InRoles;
}
