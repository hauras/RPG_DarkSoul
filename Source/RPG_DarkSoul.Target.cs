// Free to use, credit will be highly appreciated. 

using UnrealBuildTool;
using System.Collections.Generic;

public class RPG_DarkSoulTarget : TargetRules
{
	public RPG_DarkSoulTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "RPG_DarkSoul" } );
	}
}
