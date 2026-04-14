#pragma once

#include "CoreMinimal.h"
#include "UnrealAiProductSpecialistId.h"

namespace UnrealAiProductSpecialistHandoff
{
	FString BuildAutomatedSubturnPreamble(EUnrealAiProductSpecialistId SpecialistId);
	FString SpecialistDisplayName(EUnrealAiProductSpecialistId SpecialistId);
}
