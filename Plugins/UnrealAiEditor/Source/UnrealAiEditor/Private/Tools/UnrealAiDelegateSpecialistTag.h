#pragma once

#include "CoreMinimal.h"
#include "UnrealAiProductSpecialistId.h"

/** `<unreal_ai_delegate specialist="scene">...</unreal_ai_delegate>` from orchestrator assistant text. */
namespace UnrealAiDelegateSpecialistTag
{
	bool TryConsume(const FString& Content, EUnrealAiProductSpecialistId& OutSpecialistId, FString& OutInnerSpec, FString& OutVisibleWithoutTags);
	void StripProtocolMarkersForUi(FString& InOutText);
}

/** `<unreal_ai_specialist_result>...</unreal_ai_specialist_result>` from specialist assistant text. */
namespace UnrealAiProductSpecialistResultTag
{
	bool TryConsume(const FString& Content, FString& OutInnerPayload, FString& OutVisibleWithoutTags);
	void StripProtocolMarkersForUi(FString& InOutText);
}
