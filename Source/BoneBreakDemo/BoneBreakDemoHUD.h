// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BoneBreakDemoHUD.generated.h"

UCLASS()
class ABoneBreakDemoHUD : public AHUD
{
	GENERATED_BODY()

public:
	ABoneBreakDemoHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

