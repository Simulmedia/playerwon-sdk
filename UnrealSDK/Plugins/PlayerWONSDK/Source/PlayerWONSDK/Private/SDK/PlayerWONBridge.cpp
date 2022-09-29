// Copyright of PlayerWON 2022

//SDK
#include "SDK/PlayerWONBridge.h"
#include "SDK/TelemetryComponent.h"

//Epic
#include "Json.h"
#include "MediaPlayer.h"
#include "MediaSoundComponent.h"
#include "Misc/EngineVersion.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Misc/Timespan.h"
#include "Math/UnrealMathUtility.h"


APlayerWONBridge::APlayerWONBridge()
{
	PrimaryActorTick.bCanEverTick = true;

	SDK_GUID.NewGuid();

	SoundComponent = CreateDefaultSubobject<UMediaSoundComponent>(TEXT("Sound Component"));
	SoundComponent->SetupAttachment(RootComponent);

	TelemetryComponent = CreateDefaultSubobject<UTelemetryComponent>(TEXT("Telemetry Component"));

	ResetProgress();
}

void APlayerWONBridge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MediaPlayer)
	{
		if (MediaPlayer->IsPlaying())
		{
			CheckOpportunityProgress();
		}
	}
}

void APlayerWONBridge::BeginPlay()
{
	Super::BeginPlay();

	if (SoundComponent)
	{
		SoundComponent->SetMediaPlayer(MediaPlayer);
		SoundComponent->Channels = EMediaSoundChannels::Stereo;
	}

	if (MediaPlayer)
	{
		MediaPlayer->OnMediaOpened.AddDynamic(this, &APlayerWONBridge::OnMediaPrepared);
		MediaPlayer->OnMediaClosed.AddDynamic(this, &APlayerWONBridge::OnMediaClosed);
		MediaPlayer->OnEndReached.AddDynamic(this, &APlayerWONBridge::OnMediaComplete);
	}
}


void APlayerWONBridge::InitBridge(FString IDFA)
{
	if (TelemetryComponent)
	{
		FString EngineVersion = FEngineVersion().Current().ToString();
		FString GameTitle = UKismetSystemLibrary::GetGameName();

		TelemetryComponent->InitializeTelemetry(FInitializeMessage(IDFA, SDK_VERSION, EngineVersion, GameTitle, SDK_GUID.ToString(), TEXT("Initialize")));
	}
}

void APlayerWONBridge::RetrieveOpportunity(FString Token, FClientDetails Details)
{
	if (AuthToken.IsEmpty() && !Token.IsEmpty())
	{
		AuthToken = Token;
	}	
	if (Details.IsValid())
	{
		SetClientDetails(Details);
	}

	if (AuthToken.IsEmpty())
	{
		if (!ClientDetails.IsValid())
		{
			if (TelemetryComponent)
			{
				TelemetryComponent->CatchError(TEXT("PlayerWONBridge::RetrieveOpportunity - Invalid ClientCredentials."));
				return;
			}
			UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::RetrieveOpportunity - Invalid ClientCredentials."));
			return;
		}

		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::RetrieveOpportunity - Invalid AuthorizationToken."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::RetrieveOpportunity - Invalid AuthorizationToken."));
		return;
	}

	OpportunityAPI(AuthToken, ClientDetails);
}

void APlayerWONBridge::k2_RetrieveOpportunity(FString Token, FClientDetails Details)
{
	RetrieveOpportunity(Token, Details);
}

void APlayerWONBridge::CallSession(FSessionDetails Details, FString Token)
{
	if (AuthToken.IsEmpty() && !Token.IsEmpty())
	{
		AuthToken = Token;
	}

	if (AuthToken.IsEmpty())
	{
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::CallSession - AuthorizationToken not valid."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::CallSession - AuthorizationToken not valid."));
		return;
	}

	if (!Details.IsValid())
	{
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::CallSession - SessionDetails not valid."));			
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::CallSession - SessionDetails not valid."));
		return;
	}

	SessionAPI(AuthToken, Details);
}

void APlayerWONBridge::k2_CallSession(FSessionDetails Details, FString Token)
{
	CallSession(Details, Token);
}


void APlayerWONBridge::AuthorizeClient(FString ServerURL)
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &APlayerWONBridge::OnAuthorizationResponse);
	Request->SetVerb(TEXT("POST"));
	Request->SetURL(ServerURL);

	Request->ProcessRequest();
}

void APlayerWONBridge::SetClientDetails(FClientDetails InClientDetails)
{
	ClientDetails = InClientDetails;
}

void APlayerWONBridge::PlayOpportunity()
{
	if (MediaPlayer)
	{
		if (Opportunity.IsValid())
		{

			if (MediaPlayer->CanPlayUrl(Opportunity.CreativeURL))
			{
				MediaPlayer->OpenUrl(Opportunity.CreativeURL);
				return;
			}

			if (TelemetryComponent)
			{
				TelemetryComponent->CatchError(TEXT("PlayerWONBridge::PlayOpportunity - MediaPlayer cannot play given URL"));
				return;
			}
			UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::PlayOpportunity - MediaPlayer cannot play given URL"));
			return;
		}

		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::PlayOpportunity - Opportunity not valid."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::PlayOpportunity - Opportunity not valid."));
		return;
	}
	
	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::PlayOpportunity - MediaPlayer not set."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::PlayOpportunity - MediaPlayer not set."));
}

void APlayerWONBridge::StopOpportunity(EReasonForAbort Reason)
{
	if (MediaPlayer)
	{
		if (Opportunity.IsValid())
		{
			FTimespan Time = MediaPlayer->GetTime();
			double TotalSeconds = Time.GetTotalSeconds();
			int32 FlooredSeconds = FMath::FloorToInt(TotalSeconds);
			AbortAPI(Reason, FlooredSeconds);
			
			MediaPlayer->Close();
			
			OpportunityStoppedEvent.Broadcast();
			return;
		}

		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::StopOpportunity - Opportunity not valid."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::StopOpportunity - Opportunity not valid."));
		return;
	}

	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::StopOpportunity - MediaPlayer not set."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::StopOpportunity - MediaPlayer not set."));
}

FString APlayerWONBridge::GetAuthToken()
{
	return AuthToken;
}

UMediaPlayer* APlayerWONBridge::GetMediaPlayer()
{
	if (MediaPlayer)
	{
		return MediaPlayer;
	}

	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::GetMediaPlayer - MediaPlayer not set."));
		return nullptr;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::GetMediaPlayer - MediaPlayer not set."));
	return nullptr;
}

UTelemetryComponent* APlayerWONBridge::GetTelemetryComponent()
{
	if (TelemetryComponent)
	{
		return TelemetryComponent;
	}

	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::GetTelemetryComponent - TelemetryComponent not set."));
	return nullptr;
}

FGuid APlayerWONBridge::GetSDKGUID()
{
	return SDK_GUID;
}

void APlayerWONBridge::SetSendTelemetryData(bool InSendTelemetryData)
{
	if (TelemetryComponent)
	{
		TelemetryComponent->SetSendTelemetryData(true);
		return;
	}

	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::SetSendTelemetryData - TelemetryComponent not set."));
}

void APlayerWONBridge::OnAuthorizationResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		SetAuthorizationToken(Response->GetContentAsString());
		return;
	}

	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("Blueprint authorization request was not successsful."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("Blueprint authorization request was not successsful."));
}

void APlayerWONBridge::OnOpportunityResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
		TSharedPtr<FJsonValue> JsonResponse;
		if (FJsonSerializer::Deserialize(Reader, JsonResponse))
		{
			TSharedPtr<FJsonObject> ResponseObject = JsonResponse->AsObject();
			TArray<TSharedPtr<FJsonValue>> OpportunityArray = ResponseObject->GetArrayField(TEXT("opportunities"));
			TSharedPtr<FJsonObject> FirstOpportunity = OpportunityArray[0]->AsObject();

			Opportunity.CreativeURL = FirstOpportunity->GetStringField(TEXT("creativeURL"));
			Opportunity.Length = FirstOpportunity->GetNumberField(TEXT("length"));
			Opportunity.Receipt = FirstOpportunity->GetStringField(TEXT("receipt"));

			if (Opportunity.IsValid())
			{
				OpportunityRetrievedEvent.Broadcast(Opportunity);
				return;
			}
			if (TelemetryComponent)
			{
				TelemetryComponent->CatchError(TEXT("PlayerWONBridge - Opportunity is not valid."));
				return;
			}
			UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge - Opportunity is not valid."));
			return;
		}
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge - Could not deserialize Opportunity from Json"));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge - Could not deserialize Opportunity from Json"));
		return;
	}
	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::OnOpportunityResponse - Opportunity request failed."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::OnOpportunityResponse - Opportunity request failed."));
}

//AddToWWWForm
void APlayerWONBridge::AddToWWWForm(const FString Param, const FString Value, FString& Form)
{
	const FString Delim = TEXT("&");
	Form += (Delim + Param + "=" + Value);
}

void APlayerWONBridge::OpportunityAPI(FString Token, FClientDetails Details)
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &APlayerWONBridge::OnOpportunityResponse);
	Request->SetVerb(TEXT("POST"));
	Request->SetURL(TEXT("https://game.simulmedia-apis.com/opportunity"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), Token);

	TSharedPtr<FJsonObject> DetailsObject = MakeShareable(new FJsonObject);
	DetailsObject->SetStringField(TEXT("country"), Details.Country);
	DetailsObject->SetStringField(TEXT("idfa"), Details.IDFA);
	DetailsObject->SetStringField(TEXT("plat"), Details.Platform);
	DetailsObject->SetStringField(TEXT("lang"), Details.Language);

	if (!Details.IP.IsEmpty())
	{
		DetailsObject->SetStringField(TEXT("ip"), Details.IP);
	}
	if (Details.WidthInPixels > 0)
	{
		DetailsObject->SetNumberField(TEXT("w"), Details.WidthInPixels);
	}
	if (Details.HeightInPixels > 0)
	{
		DetailsObject->SetNumberField(TEXT("h"), Details.HeightInPixels);
	}
	if (!Details.PlayerID.IsEmpty())
	{
		DetailsObject->SetStringField(TEXT("pid"), Details.PlayerID);
	}
	if (!Details.PlayerIDType.IsEmpty())
	{
		DetailsObject->SetStringField(TEXT("pid_type"), Details.PlayerIDType);
	}
	if (!Details.Device.IsEmpty())
	{
		DetailsObject->SetStringField(TEXT("device"), Details.Device);
	}		
	DetailsObject->SetNumberField(TEXT("coppa"), Details.COPPA);
	DetailsObject->SetNumberField(TEXT("underage"), Details.UnderAge);
	if (Details.Age > 0)
	{
		DetailsObject->SetNumberField(TEXT("age"), Details.Age);
	}
	if (!Details.SlotID.IsEmpty())
	{
		DetailsObject->SetStringField(TEXT("slot_id"), Details.SlotID);
	}
	if(Details.LifetimeSpending > 0)
	{
		DetailsObject->SetNumberField(TEXT("ls"), Details.LifetimeSpending);
	}	
	if (Details.LifetimeSpendingValue.Value > 0)
	{
		TSharedPtr<FJsonObject> LifetimeSpendingObject = MakeShareable(new FJsonObject);
		LifetimeSpendingObject->SetStringField(TEXT("cur"), Details.LifetimeSpendingValue.CurrencyName);
		LifetimeSpendingObject->SetNumberField(TEXT("val"), Details.LifetimeSpendingValue.Value);
		LifetimeSpendingObject->SetNumberField(TEXT("d"), Details.LifetimeSpendingValue.DecimalPointDigitFromRight);
		LifetimeSpendingObject->SetNumberField(TEXT("t"), Details.LifetimeSpendingValue.CurrencyType);

		DetailsObject->SetObjectField(TEXT("lsv"), LifetimeSpendingObject);
	}
	if (Details.RewardValues.Num() > 0)
	{
		TArray<TSharedPtr<FJsonValue>> RewardArray;
		for (FCurrency Reward : Details.RewardValues)
		{
			TSharedPtr<FJsonObject> RewardObject = MakeShareable(new FJsonObject);
			RewardObject->SetStringField(TEXT("cur"), Reward.CurrencyName);
			RewardObject->SetNumberField(TEXT("val"), Reward.Value);
			RewardObject->SetNumberField(TEXT("d"), Reward.DecimalPointDigitFromRight);
			RewardObject->SetNumberField(TEXT("t"), Reward.CurrencyType);

			TSharedRef<FJsonValueObject> RewardValue = MakeShareable(new FJsonValueObject(RewardObject));
			RewardArray.Add(RewardValue);
		}

		DetailsObject->SetArrayField(TEXT("rv"), RewardArray);
	}
	DetailsObject->SetNumberField(TEXT("gs"), Details.GameServer);

	FString ContentString;
	TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&ContentString);
	if (FJsonSerializer::Serialize(DetailsObject.ToSharedRef(), JsonWriter))
	{
		Request->SetContentAsString(ContentString);
		Request->ProcessRequest();
		return;
	}

	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::OpportunityAPI - ClientDetails could not be serialized to Json."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::OpportunityAPI - ClientDetails could not be serialized to Json."));
}

void APlayerWONBridge::OnSessionResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		return;
	}

	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::OnSessionResponse - Session request failed."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::OnSessionResponse - Session request failed."));
}

void APlayerWONBridge::OnAbortResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		return;
	}

	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::OnAbortRespoinse - Abort request failed."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::OnAbortRespoinse - Abort request failed."));
}

void APlayerWONBridge::OnCompleteResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		return;
	}

	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::OnCompleteResponse - Complete request failed."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::OnCompleteResponse - Complete request failed."));
}

void APlayerWONBridge::OnProgressResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		return;
	}

	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::OnProgressResponse - Progress request failed."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::OnProgressResponse - Progress request failed."));
}

void APlayerWONBridge::OnStartResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		return;
	}

	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::OnStartResponse - Start request failed."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::OnStartResponse - Start request failed."));
}

void APlayerWONBridge::OnMediaPrepared(FString Media)
{
	OpportunityStartedEvent.Broadcast();
	StartAPI();
}

void APlayerWONBridge::OnMediaClosed()
{
	ResetProgress();
}

void APlayerWONBridge::OnMediaComplete()
{
	OpportunityCompletedEvent.Broadcast();
	CompleteAPI();

	if (MediaPlayer)
	{
		MediaPlayer->Close();
		return;
	}

	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::OnMediaComplete - MediaPlayer not set."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::OnMediaComplete - MediaPlayer not set."));
}

void APlayerWONBridge::AbortAPI(EReasonForAbort Reason, int32 SecondsIntoOpportunity)
{
	if (AuthToken.IsEmpty())
	{
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::AbortAPI - AuthorizationToken is invalid."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::AbortAPI - AuthorizationToken is invalid."));
		return;
	}

	if (!Opportunity.IsValid())
	{
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::AbortAPI - Opportunity is invalid."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::AbortAPI - Opportunity is invalid."));
		return;
	}

	FString AbortURL = "https://game.simulmedia-apis.com/abort/";
	AbortURL.Append(Opportunity.Receipt);
	AbortURL.Append(TEXT("?reason="));
	AbortURL.Append(AbortReasonsMap[Reason]);
	AbortURL.Append(TEXT("&t="));
	AbortURL.Append(FString::FromInt(SecondsIntoOpportunity));

	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &APlayerWONBridge::OnAbortResponse);
	Request->SetVerb(TEXT("PUT"));
	Request->SetURL(AbortURL);
	Request->SetHeader(TEXT("Authorization"), AuthToken);

	Request->ProcessRequest();
}

void APlayerWONBridge::CompleteAPI()
{
	if (AuthToken.IsEmpty())
	{
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::CompleteAPI - AuthorizationToken is invalid."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::CompleteAPI - AuthorizationToken is invalid."));
		return;
	}

	if (!Opportunity.IsValid())
	{
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::CompleteAPI - Opportunity is invalid."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::CompleteAPI - Opportunity is invalid."));
		return;
	}

	FString CompleteURL = "https://game.simulmedia-apis.com/complete/";
	CompleteURL.Append(Opportunity.Receipt);

	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &APlayerWONBridge::OnCompleteResponse);
	Request->SetVerb(TEXT("PUT"));
	Request->SetURL(CompleteURL);
	Request->SetHeader(TEXT("Authorization"), AuthToken);

	Request->ProcessRequest();
}

void APlayerWONBridge::ProgressAPI(int32 PercentageOfProgress)
{
	if (AuthToken.IsEmpty())
	{
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::ProgressAPI - AuthorizationToken is invalid."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::ProgressAPI - AuthorizationToken is invalid."));
		return;
	}

	if (!Opportunity.IsValid())
	{
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::ProgressAPI - Opportunity is invalid."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::ProgressAPI - Opportunity is invalid."));
		return;
	}

	FString ProgressURL = "https://game.simulmedia-apis.com/progress/";
	ProgressURL.Append(Opportunity.Receipt);
	ProgressURL.Append(TEXT("?p="));
	ProgressURL.Append(FString::FromInt(PercentageOfProgress));

	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &APlayerWONBridge::OnProgressResponse);
	Request->SetVerb(TEXT("PUT"));
	Request->SetURL(ProgressURL);
	Request->SetHeader(TEXT("Authorization"), AuthToken);

	Request->ProcessRequest();
}

void APlayerWONBridge::StartAPI()
{
	if (AuthToken.IsEmpty())
	{
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::StartAPI - AuthorizationToken is invalid."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::StartAPI - AuthorizationToken is invalid."));
		return;
	}

	if (!Opportunity.IsValid())
	{
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("PlayerWONBridge::StartAPI - Opportunity is invalid."));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::StartAPI - Opportunity is invalid."));
		return;
	}

	FString StartURL = "https://game.simulmedia-apis.com/start/";
	StartURL.Append(Opportunity.Receipt);

	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &APlayerWONBridge::OnStartResponse);
	Request->SetVerb(TEXT("PUT"));
	Request->SetURL(StartURL);
	Request->SetHeader(TEXT("Authorization"), AuthToken);

	Request->ProcessRequest();
}

void APlayerWONBridge::CheckOpportunityProgress()
{
	FTimespan CurrentTime = MediaPlayer->GetTime();
	FTimespan Duration = MediaPlayer->GetDuration();
	double TotalSecondsPlayed = CurrentTime.GetTotalSeconds();
	double TotalMaxSeconds = Duration.GetTotalSeconds();

	float Percentage = (TotalSecondsPlayed / TotalMaxSeconds) * 100;
	int32 FlooredPercentage = FMath::FloorToInt(Percentage);

	if (FlooredPercentage >= 25.0f && FlooredPercentage < 50.0f && !bQuarterInvoked)
	{
		OpportunityProgressEvent.Broadcast(FlooredPercentage);
		ProgressAPI(25);
		bQuarterInvoked = true;
	}
	else if (FlooredPercentage >= 50.0f && FlooredPercentage < 75.0f && !bHalfInvoked)
	{
		OpportunityProgressEvent.Broadcast(FlooredPercentage);
		ProgressAPI(50);
		bHalfInvoked = true;
	}
	else if (FlooredPercentage >= 75.0f && FlooredPercentage < 100.0f && !bThreeQuartersInvoked)
	{
		OpportunityProgressEvent.Broadcast(FlooredPercentage);
		ProgressAPI(75);
		bThreeQuartersInvoked = true;
	}
}

void APlayerWONBridge::ResetProgress()
{
	bQuarterInvoked = false;
	bHalfInvoked = false;
	bThreeQuartersInvoked = false;
}

void APlayerWONBridge::SetAuthorizationToken(FString Token)
{
	if (Token.IsEmpty())
	{
		if (TelemetryComponent)
		{
			TelemetryComponent->CatchError(TEXT("APlayerWONBridge::SetAuthorizationToken - Invalid token"));
			return;
		}
		UE_LOG(LogTemp, Error, TEXT("APlayerWONBridge::SetAuthorizationToken - Invalid token"));
		return;
	}

	AuthToken = TEXT("Bearer ");
	AuthToken.Append(Token);

	AuthorizationSuccessfulEvent.Broadcast(AuthToken);
}

float APlayerWONBridge::GetAdPercentageRaw()
{
	FTimespan CurrentTime = MediaPlayer->GetTime();
	FTimespan Duration = MediaPlayer->GetDuration();
	double TotalSecondsPlayed = CurrentTime.GetTotalSeconds();
	double TotalMaxSeconds = Duration.GetTotalSeconds();
	float Percentage = (TotalSecondsPlayed / TotalMaxSeconds) * 100;

	return Percentage;
}

int32 APlayerWONBridge::GetAdPercentageInt()
{
	FTimespan CurrentTime = MediaPlayer->GetTime();
	FTimespan Duration = MediaPlayer->GetDuration();
	double TotalSecondsPlayed = CurrentTime.GetTotalSeconds();
	double TotalMaxSeconds = Duration.GetTotalSeconds();

	float Percentage = (TotalSecondsPlayed / TotalMaxSeconds) * 100;
	int32 FlooredPercentage = FMath::FloorToInt(Percentage);

	return FlooredPercentage;
}

void APlayerWONBridge::SessionAPI(FString Token, FSessionDetails Details)
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &APlayerWONBridge::OnSessionResponse);
	Request->SetVerb(TEXT("POST"));
	Request->SetURL(TEXT("https://game.simulmedia-apis.com/session"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), Token);

	TSharedPtr<FJsonObject> DetailsObject = MakeShareable(new FJsonObject);
	DetailsObject->SetStringField(TEXT("country"), Details.Country);
	DetailsObject->SetStringField(TEXT("plat"), Details.Platform);
	DetailsObject->SetStringField(TEXT("lang"), Details.Language);
	
	if (!Details.PlayerID.IsEmpty())
	{
		DetailsObject->SetStringField(TEXT("pid"), Details.PlayerID);
	}
	if (!Details.PlayerIDType.IsEmpty())
	{
		DetailsObject->SetStringField(TEXT("pid_type"), Details.PlayerIDType);
	}
	if (!Details.Device.IsEmpty())
	{
		DetailsObject->SetStringField(TEXT("device"), Details.Device);
	}

	DetailsObject->SetNumberField(TEXT("coppa"), Details.COPPA);
	DetailsObject->SetNumberField(TEXT("underage"), Details.UnderAge);

	if (Details.Age > 0)
	{
		DetailsObject->SetNumberField(TEXT("age"), Details.Age);
	}

	if (Details.MinAge >= 0)
	{
		DetailsObject->SetNumberField(TEXT("min_age"), Details.MinAge);
	}
	if (Details.MaxAge > 0)
	{
		DetailsObject->SetNumberField(TEXT("max_age"), Details.MaxAge);
	}

	DetailsObject->SetStringField(TEXT("gg"), Details.Gender);

	if (Details.LifetimeSpending > 0)
	{
		DetailsObject->SetNumberField(TEXT("ls"), Details.LifetimeSpending);
	}

	if (Details.LifetimeSpendingValue.Value > 0)
	{
		TSharedPtr<FJsonObject> LifetimeSpendingObject = MakeShareable(new FJsonObject);
		LifetimeSpendingObject->SetStringField(TEXT("cur"), Details.LifetimeSpendingValue.CurrencyName);
		LifetimeSpendingObject->SetNumberField(TEXT("val"), Details.LifetimeSpendingValue.Value);
		LifetimeSpendingObject->SetNumberField(TEXT("d"), Details.LifetimeSpendingValue.DecimalPointDigitFromRight);
		LifetimeSpendingObject->SetNumberField(TEXT("t"), Details.LifetimeSpendingValue.CurrencyType);

		DetailsObject->SetObjectField(TEXT("lsv"), LifetimeSpendingObject);
	}

	if (!Details.PlayerFirstPlayedDate.IsEmpty())
	{
		DetailsObject->SetStringField(TEXT("psd"), Details.PlayerFirstPlayedDate);
	}
	
	DetailsObject->SetNumberField(TEXT("gs"), Details.GameServer);

	FString ContentString;
	TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&ContentString);
	if (FJsonSerializer::Serialize(DetailsObject.ToSharedRef(), JsonWriter))
	{
		Request->SetContentAsString(ContentString);
		Request->ProcessRequest();
		return;
	}

	if (TelemetryComponent)
	{
		TelemetryComponent->CatchError(TEXT("PlayerWONBridge::Session - SessionDetails could not be serialized to Json."));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("PlayerWONBridge::Session - SessionDetails could not be serialized to Json."));
}

