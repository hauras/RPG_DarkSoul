// Free to use, credit will be highly appreciated. 

using UnrealBuildTool;
using System.Collections.Generic;

public class RPG_DarkSoulEditorTarget : TargetRules
{
	public RPG_DarkSoulEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "RPG_DarkSoul" } );
	}
}
