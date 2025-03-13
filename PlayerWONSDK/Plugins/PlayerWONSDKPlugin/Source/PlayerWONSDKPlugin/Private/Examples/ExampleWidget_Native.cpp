// Copyright of PlayerWON 2022

//SDK
#include "Examples/ExampleWidget_Native.h"

//Epic
#include "Components/Button.h"
#include "Components/Overlay.h"
#include "Components/Slider.h"

void UExampleWidget_Native::NativeConstruct()
{
	Super::NativeConstruct();

	if (PlayAdButton)
	{
		PlayAdButton->OnClicked.AddDynamic(this, &UExampleWidget_Native::PlayButton);
	}
	if (StopAdButton)
	{
		StopAdButton->OnClicked.AddDynamic(this, &UExampleWidget_Native::StopButton);
	}

	AdTime = 0.0f;
}

void UExampleWidget_Native::SetPlayButtonVisibility(ESlateVisibility InVisibility)
{
	if (PlayAdButton)
	{
		PlayAdButton->SetVisibility(InVisibility);
	}
}

void UExampleWidget_Native::SetStopButtonVisibility(ESlateVisibility InVisibility)
{
	if (StopAdButton)
	{
		StopAdButton->SetVisibility(InVisibility);
	}
}

void UExampleWidget_Native::SetAdVisibility(ESlateVisibility InVisibility)
{
	if (AdDisplayOverlay)
	{
		AdDisplayOverlay->SetVisibility(InVisibility);
	}
}

void UExampleWidget_Native::SetVisibilityAll(ESlateVisibility InVisibility)
{
	SetPlayButtonVisibility(InVisibility);
	SetStopButtonVisibility(InVisibility);
	SetAdVisibility(InVisibility);
}

void UExampleWidget_Native::SetAdTime(float InTime)
{
	AdTime = InTime;
	if (AdTimeSlider)
	{
		AdTimeSlider->SetValue(AdTime);
	}
}

float UExampleWidget_Native::GetAdTime()
{
	return AdTime;
}

void UExampleWidget_Native::PlayButton()
{
	SetAdVisibility(ESlateVisibility::Visible);
	PlayButtonEvent.Broadcast();

	SetStopButtonVisibility(ESlateVisibility::Visible);
	SetPlayButtonVisibility(ESlateVisibility::Hidden);
}

void UExampleWidget_Native::StopButton()
{
	SetAdVisibility(ESlateVisibility::Hidden);
	StopButtonEvent.Broadcast();

	SetStopButtonVisibility(ESlateVisibility::Hidden);
	SetPlayButtonVisibility(ESlateVisibility::Visible);
}
