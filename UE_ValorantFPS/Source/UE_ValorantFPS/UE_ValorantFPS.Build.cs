// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE_ValorantFPS : ModuleRules
{
	public UE_ValorantFPS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
