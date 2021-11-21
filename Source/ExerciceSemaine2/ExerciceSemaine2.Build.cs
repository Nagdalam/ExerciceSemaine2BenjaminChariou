// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ExerciceSemaine2 : ModuleRules
{
	public ExerciceSemaine2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
