#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PitchBlackGameInstance.generated.h"

UCLASS()
class PITCHBLACK_API UPitchBlackGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    virtual void Init() override;
};