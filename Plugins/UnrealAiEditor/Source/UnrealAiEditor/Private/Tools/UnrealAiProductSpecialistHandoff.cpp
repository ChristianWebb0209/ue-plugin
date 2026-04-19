#include "Tools/UnrealAiProductSpecialistHandoff.h"

FString UnrealAiProductSpecialistHandoff::SpecialistDisplayName(const EUnrealAiProductSpecialistId SpecialistId)
{
	switch (SpecialistId)
	{
	case EUnrealAiProductSpecialistId::Scene:
		return TEXT("Scene specialist");
	case EUnrealAiProductSpecialistId::Assets:
		return TEXT("Assets specialist");
	case EUnrealAiProductSpecialistId::Viewport:
		return TEXT("Viewport specialist");
	case EUnrealAiProductSpecialistId::Diagnostics:
		return TEXT("Diagnostics specialist");
	case EUnrealAiProductSpecialistId::Playtest:
		return TEXT("Playtest specialist");
	case EUnrealAiProductSpecialistId::Animation:
		return TEXT("Animation specialist");
	case EUnrealAiProductSpecialistId::ProjectIntel:
		return TEXT("Project intelligence specialist");
	case EUnrealAiProductSpecialistId::EditorUi:
		return TEXT("Editor UI specialist");
	case EUnrealAiProductSpecialistId::Settings:
		return TEXT("Settings specialist");
	case EUnrealAiProductSpecialistId::Materials:
		return TEXT("Materials specialist");
	case EUnrealAiProductSpecialistId::None:
	default:
		return TEXT("Product specialist");
	}
}

FString UnrealAiProductSpecialistHandoff::BuildAutomatedSubturnPreamble(const EUnrealAiProductSpecialistId SpecialistId)
{
	const FString Name = SpecialistDisplayName(SpecialistId);
	return FString::Printf(
		TEXT("[Harness — %s]\n")
		TEXT("You are running as a **delegated specialist** (orchestrator handoff). Use only the tools available in this turn. ")
		TEXT("When finished or blocked, emit `<unreal_ai_specialist_result>...</unreal_ai_specialist_result>` with a concise summary for the orchestrator.\n\n"),
		*Name);
}
