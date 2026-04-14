#pragma once

#include "CoreMinimal.h"
#include "Context/AgentContextTypes.h"
#include "Templates/Function.h"
#include "UnrealAiProductSpecialistId.h"

struct FUnrealAiModelCapabilities;
struct FUnrealAiToolPackOptions;
class FUnrealAiToolCatalog;

namespace UnrealAiProductSpecialistCoreTools
{
	/**
	 * Ensures high-signal tools for the active specialist appear in the tiered roster (same pattern as Blueprint/Environment builder core merge).
	 */
	void MergeCoreToolsAfterGuardrails(
		EUnrealAiProductSpecialistId SpecialistId,
		TFunctionRef<bool(const FString&)> ToolFilter,
		TArray<FString>& InOutOrdered);

	/**
	 * Full specialist allow-list in stable appendix order: pinned core tools first (see MergeCoreToolsAfterGuardrails),
	 * then remaining enabled tools that pass ToolFilter, sorted by tool_id.
	 */
	void BuildSpecialistTieredAppendixOrder(
		EUnrealAiProductSpecialistId SpecialistId,
		FUnrealAiToolCatalog& Catalog,
		EUnrealAiAgentMode Mode,
		const FUnrealAiModelCapabilities& Caps,
		const FUnrealAiToolPackOptions* PackOptions,
		TFunctionRef<bool(const FString&)> ToolFilter,
		TArray<FString>& OutOrdered);
}
