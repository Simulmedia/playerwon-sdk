// Copyright of PlayerWON 2022


#include "SDK/PlayerWONFunctionLibrary.h"

FClientDetails UPlayerWONFunctionLibrary::k2_CreateClientDetails(ESupportedCountries InCountry, FString InIDFA, ESupportedPlatform InPlatform, ESupportedLanguages InLanguage, FString InIP, int32 InWidth, int32 InHeight, FString InPlayerID,
    EPlayerIDType InPlayerIDType, FString InDevice, int32 InCOPPA, int32 InUnderAge, int32 InAge, FString InSlotID, int32 InLifetimeSpending, FCurrency InLifetimeSpendingValue,
    TArray<FCurrency> InRewardValues, int32 InGameServer)
{
    return FClientDetails(InCountry, InIDFA, InPlatform, InLanguage, InIP, InWidth, InHeight, InPlayerID, InPlayerIDType, InDevice, InCOPPA, InUnderAge, InAge, InSlotID, InLifetimeSpending, InLifetimeSpendingValue, InRewardValues, InGameServer);
}

FSessionDetails UPlayerWONFunctionLibrary::k2_CreateSessionDetails(ESupportedCountries InCountry, ESupportedPlatform InPlatform, ESupportedLanguages InLanguage, FString InPlayerID, EPlayerIDType InPlayerIDType, FString InDevice, int32 InCOPPA, int32 InUnderAge, int32 InAge, int32 InMinAge, int32 InMaxAge, EPlayerGender InGender, int32 InLifetimeSpending, FCurrency InLifetimeSpendingValue, FString InPlayerFirstPlayedDate, int32 InGameServer)
{
    return FSessionDetails(InCountry, InPlatform, InLanguage, InPlayerID, InPlayerIDType, InDevice, InCOPPA, InUnderAge, InAge, InMinAge, InMaxAge, InGender, InLifetimeSpending, InLifetimeSpendingValue, InPlayerFirstPlayedDate, InGameServer);
}

FCurrency UPlayerWONFunctionLibrary::k2_CreateCurrency(ESupportedCurrencies InCurrencyName, int32 InValue, int32 InDecimalPointDigitFromRight, ECurrencyType InCurrencyType, FString InCustomName)
{
    return FCurrency(InCurrencyName, InValue, InDecimalPointDigitFromRight, InCurrencyType, InCustomName);
}
