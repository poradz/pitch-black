#include "PitchBlackGameInstance.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "PitchBlackGameInstance.h"
#include "CommonInputSettings.h"
#include "CommonUISettings.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"

void UPitchBlackGameInstance::Init()
{
    Super::Init();

    UE_LOG(LogTemp, Warning, TEXT("TEST LOG22222"));

    // Ensure CommonInputSettings is loaded
    UCommonInputSettings* InputSettings = GetMutableDefault<UCommonInputSettings>();
    if (InputSettings)
    {
        UE_LOG(LogTemp, Warning, TEXT("Inputti CommonInputSettings loaded during GameInstance initialization."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Inputti Failed to load CommonInputSettings."));
    }

    // Ensure CommonUISettings is loaded
    UCommonUISettings* UISettings = GetMutableDefault<UCommonUISettings>();
    if (UISettings)
    {
        UE_LOG(LogTemp, Warning, TEXT("Inputti CommonUISettings loaded during GameInstance initialization."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Inputti Failed to load CommonUISettings."));
    }
    
    // Explicitly load BP_KeyboardControllerData
    FStringAssetReference KeyboardControllerDataRef(TEXT("/Game/PitchBlack/Core/UI/BP_KeyboardControllerDataTest.BP_KeyboardControllerDataTest_C"));
    FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
    Streamable.RequestSyncLoad(KeyboardControllerDataRef);

    // Explicitly load BP_PadControllerData
    FStringAssetReference PadControllerDataRef(TEXT("/Game/PitchBlack/Core/UI/BP_PadControllerDataTest.BP_PadControllerDataTest_C"));
    Streamable.RequestSyncLoad(PadControllerDataRef);

    UE_LOG(LogTemp, Warning, TEXT("Explicitly loaded controller data assets."));
}
