// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class PitchBlackTarget : TargetRules
{
	public PitchBlackTarget(TargetInfo Target) : base(Target)
	{
        Type = TargetType.Game;

        // Set Unreal Engine 5.5 build settings explicitly
        DefaultBuildSettings = BuildSettingsVersion.V5;

        // Update include order to UE 5.5
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;

        // Set C++20 as the required standard
        CppStandard = CppStandardVersion.Cpp20;

        //// Use a unique build environment to avoid conflicts
        //BuildEnvironment = TargetBuildEnvironment.Unique;

        // Add modules
        ExtraModuleNames.Add("PitchBlack");

        bOverrideBuildEnvironment = true;
    }
}
