// Copyright of PlayerWON 2022

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SDK/DataLibrary.h"
#include "TelemetryComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FErrorCaught, FString, ErrorMessage);

/* Struct for General TelemetryMessages such as general information and errors */
USTRUCT(Blueprintable)
struct FGeneralMessage
{
	GENERATED_BODY()

	/* The type of message */
	UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
	FString Type;

	/* The SDK ID/GUID */
	UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
	FString SDK_ID;

	/* The Message being sent to PlayerWON */
	UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
	FString Message;

	/* The callstack */
	UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
	FString Stack;

	FGeneralMessage()
	{
		Type = "error";
		SDK_ID = "";
		Message = "";
		Stack = "";
	}

	FGeneralMessage(FString InSDK_ID, FString InMessage, FString InStack)
	{
		Type = "error";
		SDK_ID = InSDK_ID;
		Message = InMessage;
		Stack = InStack;
	}
};

/* A struct for Initialization Messages */
USTRUCT(Blueprintable)
struct FInitializeMessage
{
	GENERATED_BODY()

	/* The Type of message */
	UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
	FString Type;

	/* The client/player IDFA */
	UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
	FString IDFA;

	/* The SDK version */
	UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
	FString SDKVersion;

	/* Unreal Version */
	UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
	FString UnrealVersion;

	/* The game title */
	UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
	FString GameTitle;

	/* The SDK ID/GUID */
	UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
	FString SDK_ID;

	/* The Message being sent */
	UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
	FString Message;

	FInitializeMessage()
	{
		Type = "init";
		IDFA = "";
		SDKVersion = "";
		UnrealVersion = "";
		GameTitle = "";
		SDK_ID = "";
		Message = "";
	}

	FInitializeMessage(FString InIDFA, FString InSDKVersion, FString InUnrealVersion, FString InGameTitle, FString InSDK_ID, FString InMessage)
	{
		Type = "init";
		IDFA = InIDFA;
		SDKVersion = InSDKVersion;
		UnrealVersion = InUnrealVersion;
		GameTitle = InGameTitle;
		SDK_ID = InSDK_ID;
		Message = InMessage;
	}
};

/* Telemetry Component used for catching internal errors and sending telemetry data */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLAYERWONSDK_API UTelemetryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTelemetryComponent();

	/* Event that is broadcast when an internal error has been caught */
	UPROPERTY(BlueprintAssignable, Category = PLAYERWON)
	FErrorCaught ErrorCaughtEvent;

	/* Method that sends initial telemetry data to PlayerWON */
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	void InitializeTelemetry(FInitializeMessage InitMessage);

	/* Method that sends telemetry data to PlayerWON */
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	void SetSendTelemetryData(bool bSendTelemetry);

	/* Called when errors are caught within the SDK */
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	void CatchError(FString Message);



private:

	/* The HTTP URL the telemetry requests will be sent to */
	const FString TelemetryURL = "https://game.simulmedia-apis.com/sdk/telemetry";
	
	/* Saved InitializeMessage for access to data */
	FInitializeMessage InitializeMessage;

	/* Boolean that determines if the TelemetryComponent will send telemetry data or not. Use Blueprint inspector window to turn on or off */
	UPROPERTY(EditDefaultsOnly, Category = PLAYERWON, meta = (AllowPrivateAccess = true))
	bool bSendTelemetryData;

	/* Boolean that determines if the call stack will be included in the telemetry data sent.  Use Blueprint inspector window to turn on or off */
	UPROPERTY(EditDefaultsOnly, Category = PLAYERWON, meta = (AllowPrivateAccess = true))
	bool bSendStackTraceWithTelemetry;

	/* Sends general telemetry data */
	void SendTelemetry(FGeneralMessage GenMessage);

	/* Method that is called whent eh telemetry request has finished */
	void OnTelemetryResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
