#pragma once

#include "CoreMinimal.h"
#include "UnrealAiProductSpecialistId.h"

class FJsonObject;

namespace UnrealAiProductSpecialistToolPolicy
{
	bool PassesSpecialistToolFilter(EUnrealAiProductSpecialistId SpecialistId, const FString& ToolId, const FJsonObject& ToolDef);
}
