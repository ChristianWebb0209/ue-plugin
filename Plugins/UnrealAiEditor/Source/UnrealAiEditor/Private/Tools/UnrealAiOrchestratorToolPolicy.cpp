#include "Tools/UnrealAiOrchestratorToolPolicy.h"

#include "Containers/UnrealString.h"

namespace UnrealAiOrchestratorToolPolicyPriv
{
	// Read-mostly context for routing; all substantive work is delegated via protocol tags.
	static const TCHAR* const GOrchestratorToolIds[] = {
		TEXT("editor_state_snapshot_read"),
		TEXT("engine_message_log_read"),
	};
}

bool UnrealAiOrchestratorToolPolicy::IsOrchestratorTool(const FString& ToolId)
{
	for (int32 I = 0; I < UE_ARRAY_COUNT(UnrealAiOrchestratorToolPolicyPriv::GOrchestratorToolIds); ++I)
	{
		if (ToolId == UnrealAiOrchestratorToolPolicyPriv::GOrchestratorToolIds[I])
		{
			return true;
		}
	}
	return false;
}

void UnrealAiOrchestratorToolPolicy::AppendOrderedOrchestratorToolsIfAllowed(
	TFunctionRef<bool(const FString&)> ToolFilter,
	TArray<FString>& OutOrdered)
{
	for (int32 I = 0; I < UE_ARRAY_COUNT(UnrealAiOrchestratorToolPolicyPriv::GOrchestratorToolIds); ++I)
	{
		const FString Tid(UnrealAiOrchestratorToolPolicyPriv::GOrchestratorToolIds[I]);
		if (ToolFilter(Tid))
		{
			OutOrdered.Add(Tid);
		}
	}
}
