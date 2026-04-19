#include "UnrealAiProductSpecialistId.h"

EUnrealAiProductSpecialistId UnrealAiProductSpecialistId::ParseFromString(const FString& In)
{
	FString S = In;
	S.TrimStartAndEndInline();
	S.ToLowerInline();
	if (S == TEXT("scene"))
	{
		return EUnrealAiProductSpecialistId::Scene;
	}
	if (S == TEXT("assets"))
	{
		return EUnrealAiProductSpecialistId::Assets;
	}
	if (S == TEXT("viewport"))
	{
		return EUnrealAiProductSpecialistId::Viewport;
	}
	if (S == TEXT("diagnostics"))
	{
		return EUnrealAiProductSpecialistId::Diagnostics;
	}
	if (S == TEXT("playtest"))
	{
		return EUnrealAiProductSpecialistId::Playtest;
	}
	if (S == TEXT("animation"))
	{
		return EUnrealAiProductSpecialistId::Animation;
	}
	if (S == TEXT("project_intel"))
	{
		return EUnrealAiProductSpecialistId::ProjectIntel;
	}
	if (S == TEXT("editor_ui"))
	{
		return EUnrealAiProductSpecialistId::EditorUi;
	}
	if (S == TEXT("settings"))
	{
		return EUnrealAiProductSpecialistId::Settings;
	}
	if (S == TEXT("materials"))
	{
		return EUnrealAiProductSpecialistId::Materials;
	}
	return EUnrealAiProductSpecialistId::None;
}

FString UnrealAiProductSpecialistId::ToString(EUnrealAiProductSpecialistId Id)
{
	switch (Id)
	{
	case EUnrealAiProductSpecialistId::Scene:
		return TEXT("scene");
	case EUnrealAiProductSpecialistId::Assets:
		return TEXT("assets");
	case EUnrealAiProductSpecialistId::Viewport:
		return TEXT("viewport");
	case EUnrealAiProductSpecialistId::Diagnostics:
		return TEXT("diagnostics");
	case EUnrealAiProductSpecialistId::Playtest:
		return TEXT("playtest");
	case EUnrealAiProductSpecialistId::Animation:
		return TEXT("animation");
	case EUnrealAiProductSpecialistId::ProjectIntel:
		return TEXT("project_intel");
	case EUnrealAiProductSpecialistId::EditorUi:
		return TEXT("editor_ui");
	case EUnrealAiProductSpecialistId::Settings:
		return TEXT("settings");
	case EUnrealAiProductSpecialistId::Materials:
		return TEXT("materials");
	case EUnrealAiProductSpecialistId::None:
	default:
		return TEXT("none");
	}
}
