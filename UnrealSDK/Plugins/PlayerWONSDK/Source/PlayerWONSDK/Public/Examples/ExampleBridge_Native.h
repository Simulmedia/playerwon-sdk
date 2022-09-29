// Copyright of PlayerWON 2022

#pragma once

#include "CoreMinimal.h"
#include "SDK/PlayerWONBridge.h"
#include "SDK/DataLibrary.h"
#include "Examples/ExampleWidget_Native.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "ExampleBridge_Native.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERWONSDK_API AExampleBridge_Native : public APlayerWONBridge
{
	GENERATED_BODY()
	
//Epic Boilerplate

public:
	AExampleBridge_Native();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PLAYERWON)
	TSubclassOf<UExampleWidget_Native> ExampleWidgetClass;

protected:
	virtual void BeginPlay() override;

//Example Bridge

private:

	UExampleWidget_Native* ExampleWidget;

	UFUNCTION()
	void OnSuccessfulAuthorization(FString Token);

	UFUNCTION()
	void OnOpportunityRetrieved(FOpportunity Opportunity);

	UFUNCTION()
	void OnOpportunityStarted();

	UFUNCTION()
	void OnOpportunityStopped();

	UFUNCTION()
	void OnOpportunityCompleted();

	UFUNCTION()
	void OnOpportunityProgress(int32 PercentageOfProgress);

	UFUNCTION()
	void PrintError(FString Message);

	UFUNCTION()
	void StopAd();
};
