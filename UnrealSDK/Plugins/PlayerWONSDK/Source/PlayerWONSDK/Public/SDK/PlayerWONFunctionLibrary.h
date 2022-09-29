// Copyright of PlayerWON 2022

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SDK/DataLibrary.h"
#include "PlayerWONFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERWONSDK_API UPlayerWONFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/* Blueprint specific version of CreateClientDetails with defaulted values 
	* @param InCountry - The Player's Country
	* @param InIDFA - The Player's unique identifier (not gamertag)
	* @param InPlatform - The Platform the Player is playing the game on
	* @param InLanguage - The Player's language
	* @param InIP - The Player's IP
	* @param InWidth - The width of the player's resolution
	* @param InHeight - the height of the player's resolution
	* @param InPlayerID - The player's gamertag/ID
	* @param InPlayerIDTYpe - the type of gamertag/ID the player has
	* @param InDevice - The name of the device the player is using
	* @param InCOPPA - Does the game fall under COPPA, 0 means no, 1 means yes
	* @param InUnderAge - Is the player underage? 0 means no, 1 means yes
	* @param InSlotID - A specific ID provided by PlayerWON
	* @param InLifetimeSpending - Has the player ever spent currency while playing the game?  0 means no, 1 means yes
	* @param InLifetimeSpendingValue - The Currency value that the player has spent while playing the game
	* @param InRewardValues - The rewards the player will recieve upon watching an Ad
	* @param InGameServer - Is this being called by the game server?  0 means no, 1 means yes
	*/
	UFUNCTION(BlueprintCallable, Category = PLAYERWON, meta = (DisplayName = "CreateClientDetails", AutoCreateRefTerm = "InWidth, InHeight, InPlayerID, InPlayerIDType, InDevice, InCOPPA, InUnderAge, InAge, InSlotID, InLifetimeSpending, InLifetimeSpendingValue, InRewardValues, InGameServer", AdvancedDisplay=5))
	static FClientDetails k2_CreateClientDetails(ESupportedCountries InCountry, FString InIDFA, ESupportedPlatform InPlatform, ESupportedLanguages InLanguage, FString InIP, int32 InWidth, int32 InHeight, FString InPlayerID,
		EPlayerIDType InPlayerIDType, FString InDevice, int32 InCOPPA, int32 InUnderAge, int32 InAge, FString InSlotID, int32 InLifetimeSpending, FCurrency InLifetimeSpendingValue,
		TArray<FCurrency> InRewardValues, int32 InGameServer);

	/* Blueprint specific version of CreateSessionDetails with defaulted values 
	* @param InCountry - The player's country
	* @param InPlatform - The platform the player is playing the game on
	* @param InLanguage - The player's language
	* @param InPlayerID - The player's gamertag/ID
	* @param InPlayerIDType - The  type of gamertag/ID the player has
	* @param InDevice - The name of the device the player is using
	* @param InCOPPA - Does the game fall under COPPA? 0 means no, 1 means yes
	* @param InUnderAge - Is the player underage? 0 means no, 1 means yes
	* @param InAge - The players age
	* @param InMinAge - The minimum age the player can be
	* @param InMaxAge - the maximum age the player can be
	* @param InGender - The player's gender
	* @param InLifetimeSpending - Has the player ever spent currency in the game? 0 means no, 1 means yes
	* @param InLifetimeSpendingValue - The Currency value the player has spent in the game
	* @param InPlayerFirstPlayerDate - The date formatted yyyy-mm-dd that the player started playing the game
	* @param InGameServer - is this called on a game server? 0 means no, 1 means yes
	*/
	UFUNCTION(BlueprintCallable, Category = PLAYERWON, meta = (DisplayName = "CreateSessionDetails", AutoCreateRefTerm = "InPlayerID, InPlayerIDType, InDevice, InCOPPA, InUnderAge, InMinAge, InMaxAge, InGender, InLifetimeSpending, InLifetimeSpendingValue, InPlayerFirstPlayedDate, InGameServer", AdvancedDisplay=3))
	static FSessionDetails k2_CreateSessionDetails(ESupportedCountries InCountry, ESupportedPlatform InPlatform, ESupportedLanguages InLanguage, FString InPlayerID, EPlayerIDType InPlayerIDType,
		FString InDevice, int32 InCOPPA, int32 InUnderAge, int32 InAge, int32 InMinAge, int32 InMaxAge, EPlayerGender InGender, int32 InLifetimeSpending, FCurrency InLifetimeSpendingValue,
		FString InPlayerFirstPlayedDate, int32 InGameServer);

	/* Blueprint specific version of CreateCurrency with defaulted values
	* @param InCurrencyName - The name of the Currency.  If in-game currency, use in-game
	* @param InValue - The value of the reward.  e.g. 25.5 gems = 255
	* @param InDecimalPointDigitFromRight - The digit placement of the decimal point in the value.  e.g. 1 turns 255 into 25.5
	* @param InCurrencyType - The type of currency
	* @param InCustomName - If the currency is not listed, use the custom name
	*/
	UFUNCTION(BlueprintCallable, Category = PLAYERWON, meta = (DisplayName = "CreateCurrency", AutoCreateRefTerm = "InCustomName", AdvancedDisplay = 4))
	static FCurrency k2_CreateCurrency(ESupportedCurrencies InCurrencyName, int32 InValue, int32 InDecimalPointDigitFromRight, ECurrencyType InCurrencyType, FString InCustomName);
};
