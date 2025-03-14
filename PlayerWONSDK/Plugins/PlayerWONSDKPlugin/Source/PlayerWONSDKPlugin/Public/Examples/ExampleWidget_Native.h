// Copyright of PlayerWON 2022

#pragma once

//Epic
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

//SDK
#include "SDK/DataLibrary.h"

//Generated
#include "ExampleWidget_Native.generated.h"

class UOverlay;
class UButton;
class USlider;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayButtonPressed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStopButtonPressed);

/**
 * An example UserWidget that will play an example ad when prompted to in C++
 */
UCLASS()
class PLAYERWONSDKPLUGIN_API UExampleWidget_Native : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;


protected:

	UPROPERTY(meta=(BindWidget))
	UOverlay* AdDisplayOverlay;

	UPROPERTY(meta=(BindWidget))
	UButton* PlayAdButton;

	UPROPERTY(meta=(BindWidget))
	UButton* StopAdButton;

	UPROPERTY(meta=(BindWidget))
	USlider* AdTimeSlider;

public:

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "PlayerWON")
	FPlayButtonPressed PlayButtonEvent;

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "PlayerWON")
	FStopButtonPressed StopButtonEvent;

	UFUNCTION(BlueprintCallable, Category = "PlayerWON")
	void SetPlayButtonVisibility(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintCallable, Category = "PlayerWON")
	void SetStopButtonVisibility(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintCallable, Category = "PlayerWON")
	void SetAdVisibility(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintCallable, Category = "PlayerWON")
	void SetVisibilityAll(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintCallable, Category = "PlayerWON")
	void SetAdTime(float InTime);

	UFUNCTION(BlueprintCallable, Category = "PlayerWON")
	float GetAdTime();

protected:
	UFUNCTION(BlueprintCallable, Category = "PlayerWON")
	void PlayButton();

	UFUNCTION(BlueprintCallable, Category = "PlayerWON")
	void StopButton();

	UPROPERTY(BlueprintReadOnly, Category = "PlayerWON")
	float AdTime;
};
