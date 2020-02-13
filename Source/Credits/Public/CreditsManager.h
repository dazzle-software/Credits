// Copyright (c) 2020 - 2021 Dazzle Software, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Containers/UnrealString.h"
#include "Curves/CurveFloat.h"
#include "Engine/DataTable.h"
#include "Engine/Font.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInterface.h"
#include "Math/Color.h"
#include "Math/Vector2D.h"
#include "Sound/SoundWave.h"
#include "UObject/ConstructorHelpers.h"
#include "UObject/NameTypes.h"
#include "CreditsManager.generated.h"

/** Simple enum for closing credits starting position. */
UENUM(BlueprintType)
enum class ECreditsStartingPosition : uint8
{
	Top UMETA( DisplayName = "Top", ToolTip = "Starting Position - Top" ),
	Bottom UMETA( DisplayName = "Bottom", ToolTip = "Starting Position - Bottom" ),
};

/** Simple enum for closing credits sound queue mode. */
UENUM(BlueprintType)
enum class ECreditsSoundQueueMode : uint8
{
	AfterPreviousAudio UMETA( DisplayName = "After Previous Audio", ToolTip = "Queue Audio After Previous Audio" ),
	DoNotAutoQueue UMETA( DisplayName = "Do Not Auto Queue Audio", ToolTip = "Do Not Auto Queue Audio" ),
	SkipAudio UMETA( DisplayName = "Skip Audio", ToolTip = "Skip Audio" ),
};

/** Simple enum for closing credits text position. */
UENUM(BlueprintType)
enum class ECreditsTextPosition : uint8
{
	Side UMETA( DisplayName = "Side", ToolTip = "Text Position - Side" ),
	Top UMETA( DisplayName = "Top", ToolTip = "Text Position - Top" ),
};

/** Simple struct for closing credits manager. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsManager : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
};

/** Simple struct for closing credits text properties. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsTextProperties /*: public FCreditsManager*/
{
	GENERATED_USTRUCT_BODY()

	// default asset properties.
	UFont* DefaultFont = LoadObject<UFont>(NULL, TEXT("/Engine/EngineFonts/Roboto.Roboto"), NULL, LOAD_None, NULL);
	UMaterialInterface* DefaultFontMaterial = LoadObject<UMaterialInterface>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsTextProperties()
		: Title(FString())
		, Font(DefaultFont)
		, FontMaterial(DefaultFontMaterial)
		, FontSize(24)
		, Color(1.0f, 1.0f, 1.0f, 1.0f)
		{}

	/** Simple constructor */
	FCreditsTextProperties(const FString InTitle, UFont* InFont, UMaterialInterface* InFontMaterial, int InFontSize, const FLinearColor& InColor);

	/** reference to the image name. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Text"))
	FString Title;

	/** reference to the font. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Font"))
	UFont* Font;

	/** reference to the font material. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Font Material"))
	UMaterialInterface* FontMaterial;

	/** reference to the font size. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Font Size"))
	int FontSize;

	/** reference to the font color. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Color"))
	FLinearColor Color;
};

/** Simple struct for closing credits image properties. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsImageProperties /*: public FCreditsManager*/
{
	GENERATED_USTRUCT_BODY()

	// default asset properties.
	UTexture2D* DefaultImage = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsImageProperties()
		: Image(DefaultImage)
		, ImageSizeOverride(false)
		, ImageSizeProperties(0.0f, 0.0f)
	{}

	/** Simple constructor */
	FCreditsImageProperties(UTexture2D* InImage, bool InImageSizeOverride, FVector2D InImageSizeProperties);

	/** reference to the image. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Image"))
	UTexture2D* Image;

	/** reference to the override size. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Image Size Override?"))
	bool ImageSizeOverride;

	/** reference to the size override. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Image Size Properties"))
	FVector2D ImageSizeProperties;
};

/** Simple struct for closing credits padding margin. */
/* Special thanks goes to BrUnO XaVIeR for the help with our new constructor. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsPaddingMargin
{
	GENERATED_USTRUCT_BODY()

	/** default constructor */ 
	FCreditsPaddingMargin()
		: Left(0.0f)
		, Top(0.0f)
		, Right(0.0f)
		, Bottom(0.0f)
	{}

	/** Simple constructor */
	FCreditsPaddingMargin(float InLeft, float InTop, float InRight, float InBottom);

	/** reference to the left margin. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Left Padding"))
	float Left;

	/** reference to the top margin. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Top Padding"))
	float Top;

	/** reference to the right margin. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Right Padding"))
	float Right;

	/** reference to the bottom margin. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Bottom Padding"))
	float Bottom;
};

/** Simple struct for closing credits text object. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsTextObject /*: public FCreditsManager*/
{
	GENERATED_USTRUCT_BODY()

	// default asset properties.
	UFont* DefaultFont = LoadObject<UFont>(NULL, TEXT("/Engine/EngineFonts/Roboto.Roboto"), NULL, LOAD_None, NULL);
	UMaterialInterface* DefaultFontMaterial = LoadObject<UMaterialInterface>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsTextObject()
		: TextProperties(FCreditsTextProperties(FString(), DefaultFont, DefaultFontMaterial, 24, FLinearColor(1.0f, 1.0f, 1.0f, 1.0f)))
		, ImageProperties(FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f)))
		, Padding(FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 0.0f))
	{}

	/** Simple constructor */
	FCreditsTextObject(const FCreditsTextProperties& InTextProperties, const FCreditsImageProperties& InImageProperties, const FCreditsPaddingMargin& InPadding);

	/** reference to the text properties. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Text Properties"))
	FCreditsTextProperties TextProperties;

	/** reference to the image properties. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Image Properties"))
	FCreditsImageProperties ImageProperties;

	/** reference to the padding. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Padding"))
	FCreditsPaddingMargin Padding;
};

/** Simple struct for closing credits role defaults. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsRoleDefaults /*: public FCreditsManager*/
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UFont* DefaultFont = LoadObject<UFont>(NULL, TEXT("/Engine/EngineFonts/Roboto.Roboto"), NULL, LOAD_None, NULL);
	UMaterialInterface* DefaultFontMaterial = LoadObject<UMaterialInterface>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsRoleDefaults()
		: Role(
			FCreditsTextObject(
				FCreditsTextProperties(FString(), DefaultFont, DefaultFontMaterial, 24, FLinearColor(0.1f, 0.8f, 0.5f, 1.0f)),
				FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f)),
				FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 0.0f)
			)
		)
		, RolePosition(ECreditsTextPosition::Side)
		, DisplayRoleName(true)
	{}

	/** Simple constructor */
	FCreditsRoleDefaults(const FCreditsTextObject& InRole, const ECreditsTextPosition& InRolePosition, bool InDisplayRoleName);

	/** reference to the role. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Role"))
	FCreditsTextObject Role;

	/** reference to the role position. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Role Position"))
	ECreditsTextPosition RolePosition;

	/** reference to the display role name. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Display Role Name?"))
	bool DisplayRoleName;
};

/** Simple struct for closing credits section defaults. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsSectionDefaults /*: public FCreditsManager*/
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UFont* DefaultFont = LoadObject<UFont>(NULL, TEXT("/Engine/EngineFonts/Roboto.Roboto"), NULL, LOAD_None, NULL);
	UMaterialInterface* DefaultFontMaterial = LoadObject<UMaterialInterface>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsSectionDefaults()
		: Title(
			FCreditsTextProperties(FString(), DefaultFont, DefaultFontMaterial, 30, FLinearColor(0.9f, 0.4f, 0.06f, 1.0)),
			FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f)),
			FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 15.0f)
		)
		, TitlePosition(ECreditsStartingPosition::Top)
		, SectionPadding(FCreditsPaddingMargin(0.f, 0.f, 0.f, 80.f))
	{}

	/** Simple constructor */
	FCreditsSectionDefaults(const FCreditsTextObject& InTitle, const ECreditsStartingPosition& InTitlePosition, const FCreditsPaddingMargin& InSectionPadding);

	/** reference to the credits text object. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Title"))
	FCreditsTextObject Title;

	/** reference to the credits starting position. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Title Position"))
	ECreditsStartingPosition TitlePosition;

	/** reference to the credits padding margin. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Section Padding"))
	FCreditsPaddingMargin SectionPadding;
};

/** Simple struct for closing credits general settings. */
/** UserDefinedStruct'/Game/ClosingCreditsSystem/Blueprints/Structs/CreditsGeneralSettings.CreditsGeneralSettings' */
/** @todo refactor long variables in this struct. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsGeneralSettings /*: public FCreditsManager*/
{
	GENERATED_USTRUCT_BODY()

	// default float curves asset locations.
	UCurveFloat* SpeedCurveFloat = LoadObject<UCurveFloat>(NULL, TEXT("/Game/Base/Blueprints/FloatCurves/CreditsSpeedCurve.CreditsSpeedCurve"), NULL, LOAD_None, NULL);
	UCurveFloat* OpacityCurveFloat = LoadObject<UCurveFloat>(NULL, TEXT("/Game/Base/Blueprints/FloatCurves/CreditsOpacityCurve.CreditsOpacityCurve"), NULL, LOAD_None, NULL);
	UCurveFloat* VolumeCurveFloat = LoadObject<UCurveFloat>(NULL, TEXT("/Game/Base/Blueprints/FloatCurves/MusicVolumeCurve.MusicVolumeCurve"), NULL, LOAD_None, NULL);

	/** default constructor */
	FCreditsGeneralSettings()
		: SpeedCurve(SpeedCurveFloat)
		, OpacityCurve(OpacityCurveFloat)
		, VolumeCurve(VolumeCurveFloat)
		, CreditsStartingPosition(ECreditsStartingPosition::Top)
		, TimeDilationEffectsCredits(true)
		, AutoPlayMusic(true)
		, RestartMusicAtEnd(true)
		, EndCreditsOnEndReached(true)
		, StopMusicOnCreditsEnded(false)
		, StopQueueingMusicWhenCreditsEnded(true)
		{}

	/** Simple constructor */
	FCreditsGeneralSettings(
		UCurveFloat* InSpeedCurve,
		UCurveFloat* InOpacityCurve,
		UCurveFloat* InVolumeCurve,
		const ECreditsStartingPosition& InCreditsStartingPosition,
		bool InTimeDilationEffectsCredits,
		bool InAutoPlayMusic,
		bool InRestartMusicAtEnd,
		bool InEndCreditsOnEndReached,
		bool InStopMusicOnCreditsEnded,
		bool InStopQueueingMusicWhenCreditsEnded
	);

	/** reference to the credits speed curve. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Speed Curve"))
	UCurveFloat* SpeedCurve;

	/** reference to the credits opacity curve. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Opacity Curve"))
	UCurveFloat* OpacityCurve;

	/** reference to the credits volume curve. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Volume Curve"))
	UCurveFloat* VolumeCurve;

	/** reference to the start credits from . */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Start Credits From"))
	ECreditsStartingPosition CreditsStartingPosition;

	/** reference to the time dilation effects credits . */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Time Dilation Effects Credits"))
	bool TimeDilationEffectsCredits;

	/** reference to the credits auto play music . */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Auto Play Music"))
	bool AutoPlayMusic;

	/** reference to the restart music at end . */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Restart Music At End"))
	bool RestartMusicAtEnd;

	/** reference to the end credits on end reached . */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "End Credits On End Reached"))
	bool EndCreditsOnEndReached;

	/** reference to the stop music on credits ended . */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Stop Music On Credits Ended"))
	bool StopMusicOnCreditsEnded;

	/** reference to the stop queueing music when credits ended . */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Stop Queueing Music When Credits Ended"))
	bool StopQueueingMusicWhenCreditsEnded;
};

/** Simple struct for closing credits name text object. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsNameTextObject
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UFont* DefaultFont = LoadObject<UFont>(NULL, TEXT("/Engine/EngineFonts/Roboto.Roboto"), NULL, LOAD_None, NULL);
	UMaterialInterface* DefaultFontMaterial = LoadObject<UMaterialInterface>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsNameTextObject()
		: TextProperties(FCreditsTextProperties(FString(), DefaultFont, DefaultFontMaterial, 24, FLinearColor(0.9f, 0.9f, 0.9f, 1.0f)))
		, ImageProperties(FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f)))
		, Padding(FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 10.0f))
	{}

	/** Simple constructor */
	FCreditsNameTextObject(const FCreditsTextProperties& InTextProperties, const FCreditsImageProperties& InImageProperties, const FCreditsPaddingMargin& InPadding);

	/** reference to the text properties. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Text Properties"))
	FCreditsTextProperties TextProperties;

	/** reference to the image properties. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Image Properties"))
	FCreditsImageProperties ImageProperties;

	/** reference to the padding. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Padding"))
	FCreditsPaddingMargin Padding;
};

/** Simple struct for closing credits music. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsMusic : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	USoundWave* DefaultSoundWave = LoadObject<USoundWave>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsMusic()
		: Audio(DefaultSoundWave)
		, QueueMode(ECreditsSoundQueueMode::AfterPreviousAudio)
		, StartTime(0.0f)
		, PlayDelay(0.0f)
	{}

	/** Simple constructor */
	FCreditsMusic(USoundWave* InAudio, const ECreditsSoundQueueMode& InQueueMode, float InStartTime, float InPlayDelay);

	/** reference to the music wave file. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Audio File"))
	USoundWave* Audio;

	/** reference to the music queue mode. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Queue Mode"))
	ECreditsSoundQueueMode QueueMode;

	/** reference to the music start time. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Start Time"))
	float StartTime;

	/** reference to the music play delay. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Play Delay"))
	float PlayDelay;
};

/** Simple struct for closing credits section override. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsSectionOverride : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UFont* DefaultFont = LoadObject<UFont>(NULL, TEXT("/Engine/EngineFonts/Roboto.Roboto"), NULL, LOAD_None, NULL);
	UMaterialInterface* DefaultFontMaterial = LoadObject<UMaterialInterface>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsSectionOverride()
		: OverrideData(
			FCreditsSectionDefaults(
				FCreditsTextObject(
					FCreditsTextProperties(FString(), DefaultFont, DefaultFontMaterial, 30, FLinearColor(0.9f, 0.4f, 0.06f, 1.0f)),
					FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f)),
					FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 15.0f)
				),
				ECreditsStartingPosition(ECreditsStartingPosition::Top),
				FCreditsPaddingMargin(0.f, 0.f, 0.f, 80.f)
			)
		)
	{}

	/** Simple constructor */
	FCreditsSectionOverride(const FCreditsSectionDefaults& InOverrideData);

	/** reference to the credits section defaults. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Override Data"))
	FCreditsSectionDefaults OverrideData;
};

/** Simple struct for closing credits role override. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsRoleOverride : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UFont* DefaultFont = LoadObject<UFont>(NULL, TEXT("/Engine/EngineFonts/Roboto.Roboto"), NULL, LOAD_None, NULL);
	UMaterialInterface* DefaultFontMaterial = LoadObject<UMaterialInterface>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsRoleOverride()
		: ParentSection(FName(TEXT("None")))
		, RoleToOverride(FName(TEXT("None")))
		, OverrideData(
			FCreditsRoleDefaults(
				FCreditsTextObject(
					FCreditsTextProperties(FString(), DefaultFont, DefaultFontMaterial, 24, FLinearColor(0.1f, 0.8f, 0.5f, 1.0f)),
					FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f)),
					FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 0.0f)
				),
				ECreditsTextPosition(ECreditsTextPosition::Side),
				false // @todo create static variable in FCreditsRoleDefaults::DisplayRoleName so we dont hard code false. since it has no meaning.
			)
		)
	{}

	/** Simple constructor */
	FCreditsRoleOverride(const FName& InParentSection, const FName& InRoleToOverride, const FCreditsRoleDefaults& InOverrideData);

	/** reference to the actual sound play delay. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Parent Section"))
	FName ParentSection;

	/** the generic name of the sound that will be used to look up the audio. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Role To Override"))
	FName RoleToOverride;

	/** the generic name of the sound that will be used to look up the audio. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Override Data"))
	FCreditsRoleDefaults OverrideData;
};

/** Simple struct for closing credits name overrides. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsNameOverrides : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UFont* DefaultFont = LoadObject<UFont>(NULL, TEXT("/Engine/EngineFonts/Roboto.Roboto"), NULL, LOAD_None, NULL);
	UMaterialInterface* DefaultFontMaterial = LoadObject<UMaterialInterface>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsNameOverrides()
		: ParentSection(FName(TEXT("None")))
		, ParentRole(FName(TEXT("None")))
		, NameToOverride(FName(TEXT("None")))
		, OverrideData(
			FCreditsNameTextObject(
				FCreditsTextProperties(FString(), DefaultFont, DefaultFontMaterial, 24, FLinearColor(0.9f, 0.9f, 0.9f, 1.0f)),
				FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f)),
				FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 10.0f)
			)
		)
	{}

	/** Simple constructor */
	FCreditsNameOverrides(const FName& InParentSection, const FName& InParentRole, const FName& InNameToOverride, const FCreditsNameTextObject& InOverrideData);

	/** reference to the parent section. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Parent Section"))
	FName ParentSection;

	/** reference to the parent role. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Parent Role"))
	FName ParentRole;

	/** reference to the name to override. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Name To Override"))
	FName NameToOverride;

	/** reference to the override data. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Override Data"))
	FCreditsNameTextObject OverrideData;
};

/** Simple struct for closing credits overrides. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsOverrides
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UFont* DefaultFont = LoadObject<UFont>(NULL, TEXT("/Engine/EngineFonts/Roboto.Roboto"), NULL, LOAD_None, NULL);
	UMaterialInterface* DefaultFontMaterial = LoadObject<UMaterialInterface>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsOverrides()
		: SectionOverride(
			FCreditsSectionOverride(
				FCreditsSectionDefaults(
					FCreditsTextObject(
						FCreditsTextProperties(FString(), DefaultFont, DefaultFontMaterial, 30, FLinearColor(0.9f, 0.4f, 0.06f, 1.0f)),
						FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f)),
						FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 15.0f)
					),
					ECreditsStartingPosition(ECreditsStartingPosition::Top),
					FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 80.0f)
				)
			)
		)
		, IsOverridingSection(false)
		, RoleOverrides()
		, NameOverrides()
	{}

	/** Simple constructor */
	FCreditsOverrides(const FCreditsSectionOverride& InSectionOverride, bool InOverridingSection, TArray<FCreditsRoleOverride>& InRoleOverrides, TArray<FCreditsNameOverrides>& InNameOverrides);

	/** reference to the actual sound queue mode. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Section Override"))
	FCreditsSectionOverride SectionOverride;

	/** reference to the actual sound queue mode. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Allow Overriding Section"))
	bool IsOverridingSection;

	/** reference to the actual sound queue mode. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Role Overrides"))
	TArray<FCreditsRoleOverride> RoleOverrides;

	/** reference to the actual sound start time. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Name Overrides"))
	TArray<FCreditsNameOverrides> NameOverrides;
};

/** Simple struct for closing credits role. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsRole
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UFont* DefaultFont = LoadObject<UFont>(NULL, TEXT("/Engine/EngineFonts/Roboto.Roboto"), NULL, LOAD_None, NULL);
	UMaterialInterface* DefaultFontMaterial = LoadObject<UMaterialInterface>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsRole()
		: RoleProperties(
			FCreditsRoleDefaults(
				FCreditsTextObject(
					FCreditsTextProperties(FString(), DefaultFont, DefaultFontMaterial, 24, FLinearColor(0.1f, 0.8f, 0.5f, 1.0f)),
					FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f)),
					FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 0.0f)
				),
				ECreditsTextPosition(ECreditsTextPosition::Side),
				true // @todo create static variable in FCreditsRoleDefaults::DisplayRoleName so we dont hard code false. since it has no meaning.
			)
		)
		, PlayedByNames()
	{}

	/** Simple constructor */
	FCreditsRole(const FCreditsRoleDefaults& InRoleProperties, const TArray<FCreditsNameTextObject>& InPlayedByNames);

	/** reference to the role defaults. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Role Properties"))
	FCreditsRoleDefaults RoleProperties;

	/** reference to the name text object. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Played By Names"))
	TArray<FCreditsNameTextObject> PlayedByNames;
};

/** Simple struct for closing credits text object simple. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsTextObjectSimple
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsTextObjectSimple()
		: Text(FString())
		, ImageProperties(FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f)))
	{}

	/** Simple constructor */
	FCreditsTextObjectSimple(const FString& InText, const FCreditsImageProperties& InImageProperties);

	/** reference to the parent section. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Text"))
	FString Text;

	/** reference to the parent role. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Image Properties"))
	FCreditsImageProperties ImageProperties;
};

/** Simple struct for closing credits role struct simple. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsRoleStructSimple
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsRoleStructSimple()
		: Role(
			FCreditsTextObjectSimple(
				FString(),
				FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f))
			)
		)
		, DisplayRoleName(false)
		, PlayedBy()
	{}

	/** Simple constructor */
	FCreditsRoleStructSimple(const FCreditsTextObjectSimple& InRole, bool InDisplayRoleName, TArray<FCreditsTextObjectSimple>& InPlayedBy);

	/** reference to the text object simple. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Role"))
	FCreditsTextObjectSimple Role;

	/** reference to the display role name. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Display Role Name"))
	bool DisplayRoleName;

	/** reference to the text object simple. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Played By"))
	TArray<FCreditsTextObjectSimple> PlayedBy;
};

/** Simple struct for closing credits section. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsSection
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UFont* DefaultFont = LoadObject<UFont>(NULL, TEXT("/Engine/EngineFonts/Roboto.Roboto"), NULL, LOAD_None, NULL);
	UMaterialInterface* DefaultFontMaterial = LoadObject<UMaterialInterface>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsSection()
		: SectionProperties(
			FCreditsTextObject(
				FCreditsTextProperties(FString(), DefaultFont, DefaultFontMaterial, 30, FLinearColor(0.9f, 0.4f, 0.06f, 1.0f)),
				FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f)),
				FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 15.0f)
			),
			ECreditsStartingPosition(ECreditsStartingPosition::Top),
			FCreditsPaddingMargin(0.0f, 0.0f, 0.0f, 80.0f)
		)
		, Roles()
	{}

	/** Simple constructor */
	FCreditsSection(const FCreditsSectionDefaults& InSectionProperties, const TArray<FCreditsRole>& InRoles);

	/** reference to the credits section defaults. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Section Properties"))
	FCreditsSectionDefaults SectionProperties;

	/** reference to the credits section roles. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Roles"))
	TArray<FCreditsRole> Roles;
};

/** Simple struct for closing credits section simple. */
USTRUCT(BlueprintType)
struct CREDITS_API FCreditsSectionSimple : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	// default asset locations.
	UTexture2D* DefaultTexture2D = LoadObject<UTexture2D>(NULL, TEXT(""), NULL, LOAD_NoWarn, NULL);

	/** default constructor */
	FCreditsSectionSimple()
		: Title(
			FCreditsTextObjectSimple(
				FString(),
				FCreditsImageProperties(DefaultTexture2D, false, FVector2D(0.0f, 0.0f))
			)
		)
		, Roles()
	{}

	/** Simple constructor */
	FCreditsSectionSimple(const FCreditsTextObjectSimple& InTitle, const TArray<FCreditsRoleStructSimple>& InRoles);

	/** reference to the simple text object. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Title"))
	FCreditsTextObjectSimple Title;

	/** reference to the simple credits role. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Credits, meta = (DisplayName = "Roles"))
	TArray<FCreditsRoleStructSimple> Roles;
};