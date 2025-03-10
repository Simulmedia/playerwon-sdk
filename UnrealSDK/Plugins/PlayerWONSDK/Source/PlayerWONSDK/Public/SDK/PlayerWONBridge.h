// Copyright of PlayerWON 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "SDK/DataLibrary.h"
#include "Misc/Guid.h"
#include "PlayerWONBridge.generated.h"

#define SDK_VERSION "1.0"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAuthorizationSuccessful, FString, AuthorizationToken);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOpportunityRetrieved, FOpportunity, OpportunityStruct);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpportunityStarted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpportunityStopped);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpportunityCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOpportunityProgress, int32, PercentOfOpportunityReached);

UCLASS()
class PLAYERWONSDK_API APlayerWONBridge : public AActor
{
	GENERATED_BODY()

//Epic Boilerplate

public:	
	APlayerWONBridge();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;


//Bridge

public:

	/* Called to initialize the bridge with some telemetry data
	* @param IDFA - the identifier (not gamertag) of the client/player
	*/
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	void InitBridge(FString InIDFA);

	/* Function for blueprints that allows blueprint developers to authorize the clients/players.
	*  This is done because HTTP requests are not supported in blueprints.
	* @param ServerURL - The URL to the server that the HTTP request will call
	*/
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	void AuthorizeClient(FString ServerURL, FString ClientID, FString ClientSecret, FString TID);

	/* Called to set the ClientDetails so that you do not have to pass new ClientDetails into every method
	* @param InClientDetails - A struct containing the client/player's details used to pick out the perfect Ad for them
	*/
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	void SetClientDetails(FClientDetails InClientDetails);

//HTTP Requests

	/* Native Method that requests an Ad using ClientDetails if Authorization has been given 
	* @param Token - If for some reason AuthorizeClient() has not been called, this FAuthrozationToken will be used instead
	* @param Details - If SetClientDetails has not been called, this will set the Client/Player's details
	*/
	void RetrieveOpportunity(FString Token = "", FClientDetails Details = FClientDetails());
	
	/* Blueprint Method that requests an Ad using ClientDetails if Authorization has been given
	* @param Token - If for some reason AuthorizeClient() has not been called, this FAuthrozationToken will be used instead
	* @param Details - If SetClientDetails has not been called, this will set the Client/Player's details
	*/
	UFUNCTION(BlueprintCallable, Category = PLAYERWON, meta = (DisplayName = "RetrieveOpportunity", AutoCreateRefTerm = "Token, Details"))
	void k2_RetrieveOpportunity(FString Token, FClientDetails Details);

	/* Native Method that provides session details
	* @param Details - A struct containing session specific details
	* @param Token - If for some reason AuthorizeClient() has not been called, this FAuthrozationToken will be used instead
	*/
	void CallSession(FSessionDetails Details, FString Token = "");

	/* Blueprint Method that provides session details
	* @param Details - A struct containing session specific details
	* @param Token - If for some reason AuthorizeClient() has not been called, this FAuthrozationToken will be used instead
	*/
	UFUNCTION(BlueprintCallable, Category = PLAYERWON, meta = (DisplayName = "CallSession", AutoCreateRefTerm = "Token"))
	void k2_CallSession(FSessionDetails Details, FString Token);

//HTTP Request Responses

	/* Method that is called when the blueprint only AuthorizeClient is called */
	void OnAuthorizationResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	/* Method that is called when the Opportunity request is finished */
	void OnOpportunityResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	/* Method that is called when the Session request is finished */
	void OnSessionResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	/* Method that is called when the Abort request is finished */
	void OnAbortResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	/* Method that is called when the Complete request is finished */
	void OnCompleteResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	/* Method that is called when the Progress request is finished */
	void OnProgressResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	/* Method that is called when the Start request is finished */
	void OnStartResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);


//Bridge Events

	/* Event that is broadcast when Authorization of the client/player has been successful */
	UPROPERTY(BlueprintAssignable, Category = PLAYERWON)
	FAuthorizationSuccessful AuthorizationSuccessfulEvent;

	/* Event that is broadcast when an Ad has been successfully retrieved from the PlayerWON API */
	UPROPERTY(BlueprintAssignable, Category = PLAYERWON)
	FOpportunityRetrieved OpportunityRetrievedEvent;

	/* Event that is broadcast when the Ad has started playing */
	UPROPERTY(BlueprintAssignable, Category = PLAYERWON)
	FOpportunityStarted OpportunityStartedEvent;

	/* Event that is broadcast when the Ad has been stopped */
	UPROPERTY(BlueprintAssignable, Category = PLAYERWON)
	FOpportunityStopped OpportunityStoppedEvent;

	/* Event that is broadcast when the Ad has completed its playback */
	UPROPERTY(BlueprintAssignable, Category = PLAYERWON)
	FOpportunityCompleted OpportunityCompletedEvent;

	/* Event that is broadcast when the Ad has reached 25%, 50%, and 75% of its playback */
	UPROPERTY(BlueprintAssignable, Category = PLAYERWON)
	FOpportunityProgress OpportunityProgressEvent;


//MediaPlayer Controls

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PLAYERWON)
	bool bUsePhysicalMedia;

	/* Plays the Ad retrieved from RetrieveOpportunity() */
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	void PlayOpportunity();

	/* Stops the Ad playback before it is finished
	* @param Reason - The reason for the abort
	*/
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	void StopOpportunity(EReasonForAbort Reason);

//Public Accessors

protected:
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	FString GetAuthToken();

public:
	/* Returns the MediaPlayer that is assigned in the Blueprint */
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	class UMediaPlayer* GetMediaPlayer();

	/* Returns the TelemetryComponent */
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	class UTelemetryComponent* GetTelemetryComponent();

	/* Returns the SDK GUID */
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	FGuid GetSDKGUID();

	/* Sets the bSendTelemetryData flag in the TelemetryComponent */
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	void SetSendTelemetryData(bool InSendTelemetryData);


//Components

protected:
	
	/* The TelemetryComponent that handles SDK internal errors and telemetry data */
	UPROPERTY(VisibleAnywhere, Category = PLAYERWON, meta = (AllowPrivateAccess = true))
	class UTelemetryComponent* TelemetryComponent;

	/* The MediaSoundComponent that allows for the MediaPlayer to emit sound when playing */
	UPROPERTY(EditDefaultsOnly, Category = PLAYERWON, meta = (AllowPrivateAccess = true))
	class UMediaSoundComponent* SoundComponent;


//References

protected:

	/* The MediaPlayer that is set via Blueprints */
	UPROPERTY(EditAnywhere, Category = PLAYERWON)
	class UMediaPlayer* MediaPlayer;

	UPROPERTY(EditAnywhere, Category = PLAYERWON)
	class UMediaSource* DefaultMediaSource;

//Internal Variables

private:

	/* The AuthorizationToken that is set and used for internal use */
	FString AuthToken;

	/* The ClientDetails that is set and used for internal use */
	FClientDetails ClientDetails;

	/* The Opportunity that holds the current Ad selected */
	FOpportunity Opportunity;
	
	/* The SDK GUID */
	const FGuid SDK_GUID;

	/* Boolean for when the Ad has reached 25% of its playback */
	bool bQuarterInvoked;

	/* Boolean for when the Ad has reached 50% of its playback */
	bool bHalfInvoked;

	/* Boolean for when the Ad has reached 75% of its playback */
	bool bThreeQuartersInvoked;


//Helpers

	/* Adds a given parameter and value to an FString representing a WWWForm
	* @param Param - The Parameter being set
	* @param Value - The Value of the parameter being set
	* @param Form - The FString representation of the WWWForm
	*/
	void AddToWWWForm(const FString Param, const FString Value, FString& Form);

	/* Checks the Ad playback progress and calls the Progress event and HTTP request when needed*/
	void CheckOpportunityProgress();

	/* Resets the progress of the current Ad */
	void ResetProgress();

public:

	/* Sets the AuthToken variable */
	void SetAuthorizationToken(FString Token);

	/* Gets the raw float value of the percentage (0 - 100) of the ad playback*/
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	float GetAdPercentageRaw();

	/* Gets a floored integer percentage (0 - 100) of the ad playback */
	UFUNCTION(BlueprintCallable, Category = PLAYERWON)
	int32 GetAdPercentageInt();

	

//Internal API Calls

private:


	/* Calls /Opportunity API call */
	void OpportunityAPI(FString Token, FClientDetails Details);

	/* Calls the /Session API call */
	void SessionAPI(FString Token, FSessionDetails Details);

	/* Calls the /Abort API call*/
	void AbortAPI(EReasonForAbort Reason, int32 SecondsIntoOpportunity);

	/* Calls the /Complete API call */
	void CompleteAPI();

	/* Calls the /Progress API call */
	void ProgressAPI(int32 PercentageOfProgress);

	/* Calls the /Start API call */
	void StartAPI();

	/* Method used for binding to the OnMediaPrepared delegate from the MediaPlayer */
	UFUNCTION()
	void OnMediaPrepared(FString Media);

	/* Method used for binding to the OnMediaClosed delegate from the MediaPlayer */
	UFUNCTION()
	void OnMediaClosed();

	/* Method used for binding to the OnMediaComplete delegate from the MediaPlayer */
	UFUNCTION()
	void OnMediaComplete();
};
