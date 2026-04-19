#include "Tools/UnrealAiDelegateSpecialistTag.h"

namespace UnrealAiDelegateSpecialistTagPriv
{
	static bool ExtractAttrValue(const FString& OpenTag, const FString& AttrName, FString& OutValue)
	{
		const FString Needle = FString::Printf(TEXT("%s=\""), *AttrName);
		int32 K = OpenTag.Find(Needle, ESearchCase::IgnoreCase);
		if (K == INDEX_NONE)
		{
			const FString NeedleSq = FString::Printf(TEXT("%s='"), *AttrName);
			K = OpenTag.Find(NeedleSq, ESearchCase::IgnoreCase);
			if (K == INDEX_NONE)
			{
				return false;
			}
			const int32 V0 = K + NeedleSq.Len();
			const int32 V1 = OpenTag.Find(TEXT("'"), ESearchCase::CaseSensitive, ESearchDir::FromStart, V0);
			if (V1 == INDEX_NONE || V1 <= V0)
			{
				return false;
			}
			OutValue = OpenTag.Mid(V0, V1 - V0).TrimStartAndEnd();
			return !OutValue.IsEmpty();
		}
		const int32 V0 = K + Needle.Len();
		const int32 V1 = OpenTag.Find(TEXT("\""), ESearchCase::CaseSensitive, ESearchDir::FromStart, V0);
		if (V1 == INDEX_NONE || V1 <= V0)
		{
			return false;
		}
		OutValue = OpenTag.Mid(V0, V1 - V0).TrimStartAndEnd();
		return !OutValue.IsEmpty();
	}
}

void UnrealAiDelegateSpecialistTag::StripProtocolMarkersForUi(FString& InOutText)
{
	if (InOutText.IsEmpty())
	{
		return;
	}
	static const FString End = TEXT("</unreal_ai_delegate>");
	for (;;)
	{
		const int32 B = InOutText.Find(TEXT("<unreal_ai_delegate"), ESearchCase::IgnoreCase);
		if (B == INDEX_NONE)
		{
			break;
		}
		const int32 E = InOutText.Find(End, ESearchCase::IgnoreCase, ESearchDir::FromStart, B);
		if (E == INDEX_NONE)
		{
			break;
		}
		InOutText = InOutText.Left(B) + InOutText.Mid(E + End.Len());
	}
	InOutText.TrimStartAndEndInline();
}

void UnrealAiProductSpecialistResultTag::StripProtocolMarkersForUi(FString& InOutText)
{
	if (InOutText.IsEmpty())
	{
		return;
	}
	static const FString Begin = TEXT("<unreal_ai_specialist_result>");
	static const FString End = TEXT("</unreal_ai_specialist_result>");
	for (;;)
	{
		const int32 B = InOutText.Find(Begin, ESearchCase::IgnoreCase);
		if (B == INDEX_NONE)
		{
			break;
		}
		const int32 E = InOutText.Find(End, ESearchCase::IgnoreCase, ESearchDir::FromStart, B);
		if (E == INDEX_NONE)
		{
			break;
		}
		InOutText = InOutText.Left(B) + InOutText.Mid(E + End.Len());
	}
	InOutText.TrimStartAndEndInline();
}

bool UnrealAiDelegateSpecialistTag::TryConsume(
	const FString& Content,
	EUnrealAiProductSpecialistId& OutSpecialistId,
	FString& OutInnerSpec,
	FString& OutVisibleWithoutTags)
{
	OutSpecialistId = EUnrealAiProductSpecialistId::None;
	OutInnerSpec.Reset();
	OutVisibleWithoutTags = Content;

	static const FString Begin = TEXT("<unreal_ai_delegate");
	static const FString End = TEXT("</unreal_ai_delegate>");

	const int32 B = Content.Find(Begin, ESearchCase::IgnoreCase);
	const int32 E = Content.Find(End, ESearchCase::IgnoreCase);
	if (B == INDEX_NONE || E == INDEX_NONE || E <= B)
	{
		return false;
	}
	const int32 OpenEnd = Content.Find(TEXT(">"), ESearchCase::CaseSensitive, ESearchDir::FromStart, B);
	if (OpenEnd == INDEX_NONE || OpenEnd > E)
	{
		return false;
	}
	const FString OpenTag = Content.Mid(B, OpenEnd - B + 1);
	FString SpecStr;
	if (!UnrealAiDelegateSpecialistTagPriv::ExtractAttrValue(OpenTag, TEXT("specialist"), SpecStr))
	{
		return false;
	}
	OutSpecialistId = UnrealAiProductSpecialistId::ParseFromString(SpecStr);
	if (OutSpecialistId == EUnrealAiProductSpecialistId::None)
	{
		return false;
	}
	const int32 InnerStart = OpenEnd + 1;
	OutInnerSpec = Content.Mid(InnerStart, E - InnerStart).TrimStartAndEnd();
	const FString Before = Content.Left(B);
	const FString After = Content.Mid(E + End.Len());
	OutVisibleWithoutTags = (Before + After).TrimStartAndEnd();
	return true;
}

bool UnrealAiProductSpecialistResultTag::TryConsume(
	const FString& Content,
	FString& OutInnerPayload,
	FString& OutVisibleWithoutTags)
{
	OutInnerPayload.Reset();
	OutVisibleWithoutTags = Content;

	static const FString Begin = TEXT("<unreal_ai_specialist_result>");
	static const FString End = TEXT("</unreal_ai_specialist_result>");

	const int32 B = Content.Find(Begin, ESearchCase::IgnoreCase);
	const int32 E = Content.Find(End, ESearchCase::IgnoreCase);
	if (B == INDEX_NONE || E == INDEX_NONE || E <= B)
	{
		return false;
	}
	const int32 InnerStart = B + Begin.Len();
	OutInnerPayload = Content.Mid(InnerStart, E - InnerStart).TrimStartAndEnd();
	const FString Before = Content.Left(B);
	const FString After = Content.Mid(E + End.Len());
	OutVisibleWithoutTags = (Before + After).TrimStartAndEnd();
	return true;
}
