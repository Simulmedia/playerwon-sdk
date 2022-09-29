// Copyright of PlayerWON 2022


#include "Examples/ExampleWidget_Native.h"

void UExampleWidget_Native::NativeConstruct()
{
	Super::NativeConstruct();

	AdTime = 0.0f;
}

void UExampleWidget_Native::SetPlayButtonVisibility_Implementation(ESlateVisibility InVisibility)
{
	//Filled out in blueprints
}

void UExampleWidget_Native::SetStopButtonVisibility_Implementation(ESlateVisibility InVisibility)
{
	//Filled out in blueprints
}

void UExampleWidget_Native::SetAdVisibility_Implementation(ESlateVisibility InVisibility)
{
	//Filled out in blueprints
}

void UExampleWidget_Native::SetVisibilityAll_Implementation(ESlateVisibility InVisibility)
{
	//Filled out in blueprints
}

void UExampleWidget_Native::SetAdTime(float InTime)
{
	AdTime = InTime;
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
