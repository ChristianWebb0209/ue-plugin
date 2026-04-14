#pragma once

#include "CoreMinimal.h"
#include "Templates/Function.h"

/** Fixed tool allow-list for the orchestrator (delegation) lane — see docs/planning/tooling-subagent-delegation.md */
namespace UnrealAiOrchestratorToolPolicy
{
	bool IsOrchestratorTool(const FString& ToolId);

	/** Stable catalog order: snapshot read, then message log. Invokes ToolFilter per id; appends when true. */
	void AppendOrderedOrchestratorToolsIfAllowed(TFunctionRef<bool(const FString&)> ToolFilter, TArray<FString>& OutOrdered);
}
