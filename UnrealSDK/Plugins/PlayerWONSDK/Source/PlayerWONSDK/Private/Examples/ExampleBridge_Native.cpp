// Copyright of PlayerWON 2022


#include "Examples/ExampleBridge_Native.h"
#include "SDK/TelemetryComponent.h"
#include "MediaPlayer.h"
#include "Engine.h"

AExampleBridge_Native::AExampleBridge_Native()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AExampleBridge_Native::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ExampleWidget)
	{
		if (GetMediaPlayer()->IsPlaying())
		{
			float AdTimePercentage = GetAdPercentageRaw();
			ExampleWidget->SetAdTime(AdTimePercentage);
		}
	}
}

void AExampleBridge_Native::BeginPlay()
{
	Super::BeginPlay();

	if (GetTelemetryComponent())
	{
		GetTelemetryComponent()->ErrorCaughtEvent.AddDynamic(this, &AExampleBridge_Native::PrintError);
	}

	AuthorizationSuccessfulEvent.AddDynamic(this, &AExampleBridge_Native::OnSuccessfulAuthorization);
	OpportunityRetrievedEvent.AddDynamic(this, &AExampleBridge_Native::OnOpportunityRetrieved);
	OpportunityStartedEvent.AddDynamic(this, &AExampleBridge_Native::OnOpportunityStarted);
	OpportunityStoppedEvent.AddDynamic(this, &AExampleBridge_Native::OnOpportunityStopped);
	OpportunityCompletedEvent.AddDynamic(this, &AExampleBridge_Native::OnOpportunityCompleted);
	OpportunityProgressEvent.AddDynamic(this, &AExampleBridge_Native::OnOpportunityProgress);

	if (IsValid(ExampleWidgetClass))
	{
		ExampleWidget = Cast<UExampleWidget_Native>(CreateWidget(GetWorld(), ExampleWidgetClass));
		ExampleWidget->AddToViewport();

		ExampleWidget->SetVisibilityAll(ESlateVisibility::Hidden);

		ExampleWidget->PlayButtonEvent.AddDynamic(this, &AExampleBridge_Native::PlayOpportunity);
		ExampleWidget->StopButtonEvent.AddDynamic(this, &AExampleBridge_Native::StopAd);
	}

	AuthorizeClient("http://localhost:1337/login");

	InitBridge("abcd1234");
}

void AExampleBridge_Native::OnSuccessfulAuthorization(FString Token)
{
	FCurrency LifetimeSpending = FCurrency(ESupportedCurrencies::United_States_Dollar, 10000, 2, ECurrencyType::Real);
	FSessionDetails ClientSession = FSessionDetails(ESupportedCountries::United_States, ESupportedPlatform::PC, ESupportedLanguages::English, "NativeExample", EPlayerIDType::Steam, "NativeExamplePC", 0, 0, 31, 0, 99, EPlayerGender::m, 1, LifetimeSpending, "20220101", 0);
	CallSession(ClientSession, Token);

	FClientDetails Client = FClientDetails(ESupportedCountries::United_States, "abcd1234", ESupportedPlatform::PC, ESupportedLanguages::English);
	SetClientDetails(Client);
	
	RetrieveOpportunity(Token, Client);
}

void AExampleBridge_Native::OnOpportunityRetrieved(FOpportunity Ad)
{
	if (ExampleWidget)
	{
		ExampleWidget->SetPlayButtonVisibility(ESlateVisibility::Visible);
	}
}

void AExampleBridge_Native::OnOpportunityStarted()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Ad has started"));
	}
}

void AExampleBridge_Native::OnOpportunityStopped()
{
	if (ExampleWidget)
	{
		ExampleWidget->SetAdVisibility(ESlateVisibility::Hidden);
		ExampleWidget->SetPlayButtonVisibility(ESlateVisibility::Visible);
		ExampleWidget->SetStopButtonVisibility(ESlateVisibility::Hidden);
	}
}

void AExampleBridge_Native::OnOpportunityCompleted()
{
	if (ExampleWidget)
	{
		ExampleWidget->SetAdVisibility(ESlateVisibility::Hidden);
		ExampleWidget->SetPlayButtonVisibility(ESlateVisibility::Visible);
		ExampleWidget->SetStopButtonVisibility(ESlateVisibility::Hidden);
	}
}

void AExampleBridge_Native::OnOpportunityProgress(int32 PercentageOfProgress)
{
	UE_LOG(LogPlayerWON, Display, TEXT("Ad Progress: %s"), *FString::FromInt(PercentageOfProgress));
}

void AExampleBridge_Native::PrintError(FString Message)
{
	UE_LOG(LogPlayerWON, Error, TEXT("%s"), *Message);
}

void AExampleBridge_Native::StopAd()
{
	StopOpportunity(EReasonForAbort::Cancel);
}
