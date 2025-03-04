// Copyright of PlayerWON 2022


#include "SDK/TelemetryComponent.h"
#include "Json.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "UObject/Stack.h"

DEFINE_LOG_CATEGORY(LogPlayerWON);

// Sets default values for this component's properties
UTelemetryComponent::UTelemetryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	bSendTelemetryData = true;
	bSendStackTraceWithTelemetry = false;
}

void UTelemetryComponent::InitializeTelemetry(FInitializeMessage InitMessage)
{
	InitializeMessage = InitMessage;

	if (bSendTelemetryData)
	{
		FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
		Request->OnProcessRequestComplete().BindUObject(this, &UTelemetryComponent::OnTelemetryResponse);
		Request->SetVerb(TEXT("POST"));
		Request->SetURL(TelemetryURL);
		Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

		TSharedPtr<FJsonObject> TelemetryMessage = MakeShareable(new FJsonObject);
		TelemetryMessage->SetStringField(TEXT("type"), InitMessage.Type);
		TelemetryMessage->SetStringField(TEXT("idfa"), InitMessage.IDFA);
		TelemetryMessage->SetStringField(TEXT("pw_sdk_ver"), InitMessage.SDKVersion);
		TelemetryMessage->SetStringField(TEXT("engine_ver"), InitMessage.UnrealVersion);
		TelemetryMessage->SetStringField(TEXT("gametitle_id"), InitMessage.GameTitle);
		TelemetryMessage->SetStringField(TEXT("sdk_id"), InitMessage.SDK_ID);
		TelemetryMessage->SetStringField(TEXT("message"), InitMessage.Message);

		FString ContentString;
		TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&ContentString);
		if (FJsonSerializer::Serialize(TelemetryMessage.ToSharedRef(), JsonWriter))
		{
			Request->SetContentAsString(ContentString);
			Request->ProcessRequest();
			return;
		}

		CatchError(TEXT("TelemetryComponent::InitializeTelemetry - TelemetryMessage failed to serialize to Json."));
	}
}

void UTelemetryComponent::SetSendTelemetryData(bool bSend)
{
	bSendTelemetryData = bSend;
}

void UTelemetryComponent::CatchError(FString Message)
{
	ErrorCaughtEvent.Broadcast(Message);
	UE_LOG(LogPlayerWON, Error, TEXT("%s"), *Message);

	if (bSendTelemetryData)
	{
		FGeneralMessage GenMessage = FGeneralMessage(InitializeMessage.SDK_ID, Message, "");
		if (bSendStackTraceWithTelemetry)
		{
			FString Stack = FFrame::GetScriptCallstack(true);
			GenMessage.Stack = Stack;
		}

		SendTelemetry(GenMessage);
	}
}

void UTelemetryComponent::SendTelemetry(FGeneralMessage GenMessage)
{
	if (bSendTelemetryData)
	{
		FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
		Request->OnProcessRequestComplete().BindUObject(this, &UTelemetryComponent::OnTelemetryResponse);
		Request->SetVerb(TEXT("POST"));
		Request->SetURL(TelemetryURL);
		Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

		TSharedPtr<FJsonObject> TelemetryMessage = MakeShareable(new FJsonObject);
		TelemetryMessage->SetStringField(TEXT("type"), GenMessage.Type);
		TelemetryMessage->SetStringField(TEXT("sdk_id"), GenMessage.SDK_ID);
		TelemetryMessage->SetStringField(TEXT("message"), GenMessage.Message);
		if (!GenMessage.Stack.IsEmpty())
		{
			TelemetryMessage->SetStringField(TEXT("stack_trace"), GenMessage.Stack);
		}

		FString ContentString;
		TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&ContentString);
		if (FJsonSerializer::Serialize(TelemetryMessage.ToSharedRef(), JsonWriter))
		{
			Request->SetContentAsString(ContentString);
			Request->ProcessRequest();
			return;
		}

		ErrorCaughtEvent.Broadcast(TEXT("TelemetryComponent::SendTelemetry - TelemetryMessage can't be serialized to Json."));
	}
}

void UTelemetryComponent::OnTelemetryResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		return;
	}

	FString FailedResponseString = TEXT("PlayerWON: Telemetry request failed");
	ErrorCaughtEvent.Broadcast(FailedResponseString);
}
