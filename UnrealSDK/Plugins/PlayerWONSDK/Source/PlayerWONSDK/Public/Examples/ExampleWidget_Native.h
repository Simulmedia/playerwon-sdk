// Copyright of PlayerWON 2022

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ExampleWidget_Native.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayButtonPressed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStopButtonPressed);

/**
 * 
 */
UCLASS()
class PLAYERWONSDK_API UExampleWidget_Native : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "PlayerWON")
	FPlayButtonPressed PlayButtonEvent;

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "PlayerWON")
	FStopButtonPressed StopButtonEvent;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PlayerWON")
	void SetPlayButtonVisibility(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PlayerWON")
	void SetStopButtonVisibility(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PlayerWON")
	void SetAdVisibility(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PlayerWON")
	void SetVisibilityAll(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintCallable, Category = "PlayerWON")
	void SetAdTime(float InTime);

protected:
	UFUNCTION(BlueprintCallable, Category = "PlayerWON")
	void PlayButton();

	UFUNCTION(BlueprintCallable, Category = "PlayerWON")
	void StopButton();

	UPROPERTY(BlueprintReadOnly, Category = "PlayerWON")
	float AdTime;
};
