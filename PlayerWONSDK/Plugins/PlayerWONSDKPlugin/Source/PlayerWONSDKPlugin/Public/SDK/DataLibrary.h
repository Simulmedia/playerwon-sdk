// Copyright of PlayerWON 2022

#pragma once

//Epic
#include "CoreMinimal.h"

//Generated
#include "DataLibrary.generated.h"


#define PLAYERWON "PlayerWON"

/*************************** Enums ***************************/

UENUM(BlueprintType)
enum ESupportedPlatform
{
    Wildcard,
    Android,
    MacOS,
    IOS,
    PC,
    Playstation,
    Switch,
    PlatformUnknown UMETA(DisplayName = "Platform Unknown"),
    Xbox
};

UENUM(BlueprintType)
enum EPlayerIDType
{
    Apple,
    Epic,
    Google,
    Microsoft,
    Nintendo,
    Sony,
    Steam,
    Twitch,
    UnknownPIDType
};

UENUM(BlueprintType)
enum ESupportedLanguages
{
    Arabic,
    Chinese_Mandarin UMETA(DisplayName = "Chinese Mandarin"),
    English,
    French,
    German,
    Italian,
    Japanese,
    Korean,
    Polish,
    Portuguese,
    Russian,
    Spanish,
    Thai,
    Turkish
};

UENUM(BlueprintType)
enum ESupportedCurrencies
{
    Australian_Dollar UMETA(DisplayName = "Australian Dollar"),
    Brazilian_Real UMETA(DisplayName = "Brazilian Real"),
    Canadian_Dollar UMETA(DisplayName = "Canadian Dollar"),
    Chinese_Yuan UMETA(DisplayName = "Chinese Yuan"),
    Euro,
    Hong_Kong_Dollar UMETA(DisplayName = "Hong Kong Dollar"),
    Indian_Rupee UMETA(DisplayName = "Indian Rupee"),
    Japanese_Yen UMETA(DisplayName = "Japanese Yen"),
    Mexican_Peso UMETA(DisplayName = "Mexican Peso"),
    New_Zealand_Dollar UMETA(DisplayName = "New Zealand Dollar"),
    Norwegian_Krone UMETA(DisplayName = "Norwegian Krone"),
    Pound_Sterling UMETA(DisplayName = "Pound Sterling"),
    Romanian_Leu UMETA(DisplayName = "Romanian Leu"),
    Russian_Ruble UMETA(DisplayName = "Russian Ruble"),
    Singapore_Dollar UMETA(DisplayName = "Singapore Dollar"),
    South_African_Rand UMETA(DisplayName = "South African Rand"),
    South_Korean_Won UMETA(DisplayName = "South Korean Won"),
    Swedish_Krona UMETA(DisplayName = "Swedish Krona"),
    Swiss_Franc UMETA(DisplayName = "Swiss Franc"),
    Turkish_Lira UMETA(DisplayName = "Turkish Lira"),
    United_States_Dollar UMETA(DisplayName = "United States Dollar"),
    CurrencyUnknown,
    In_Game UMETA(DisplayName = "In Game")
};

UENUM(BlueprintType)
enum ECurrencyType
{
    Real = 0,
    Virtual = 1,
    Crypto = 2
};

UENUM(BlueprintType)
enum ESupportedCountries
{
    CountryUnknown,
    Andorra,
    United_Arab_Emirates UMETA(DisplayName = "United Arab Emirates"),
    Afghanistan,
    Antigua_and_Barbuda UMETA(DisplayName = "Antigua and Barbuda"),
    Anguilla,
    Albania,
    Armenia,
    Netherlands_Antilles UMETA(DisplayName = "Netherlands Antilles"),
    Angola,
    Antarctica,
    Argentina,
    American_Somoa UMETA(DisplayName = "American Somoa"),
    Austria,
    Australia,
    Aruba,
    Aland_Islands UMETA(DisplayName = "Aland Islands"),
    Azerbaijan,
    Bosnia_and_Herzegovina UMETA(DisplayName = "Bosnia and Herzegovina"),
    Barbados,
    Bangladesh,
    Belgium,
    Burkina_Faso UMETA(DisplayName = "Burkina Faso"),
    Bulgaria,
    Bahrain,
    Burundi,
    Benin,
    Saint_Barthelemy UMETA(DisplayName = "Saint Barthelemy"),
    Bermuda,
    Brunei_Darussalam UMETA(DisplayName = "Brunei Darussalam"),
    Bolivia,
    Bonaire_Sint_Eustatius_and_Saba UMETA(DisplayName = "Bonaire Sint Eustatius and Saba"),
    Brazil,
    Bahamas,
    Bhutan,
    Bouvet_Island UMETA(DisplayName = "Bouvet Island"),
    Botswana,
    Belarus,
    Belize,
    Canada,
    Cocos_Keeling_Islands UMETA(DisplayName = "Cocos Keeling Islands"),
    Democratic_Republic_of_the_Congo UMETA(DisplayName = "Democratic Republic of the Congo"),
    Central_African_Republic UMETA(DisplayName = "Central African Republic"),
    Congo,
    Switzerland,
    Cote_dIvoire UMETA(DisplayName = "Cote dIvoire"),
    Cook_Islands UMETA(DisplayName = "Cook Islands"),
    Chile,
    Cameroon,
    China,
    Colombia,
    Costa_Rica UMETA(DisplayName = "Costa Rica"),
    Cuba,
    Cape_Verde UMETA(DisplayName = "Cape Verde"),
    Curacao,
    Christmas_Island UMETA(DisplayName = "Christmas Island"),
    Cyprus,
    Czech_Republic UMETA(DisplayName = "Czech Republic"),
    Germany,
    Djibouti,
    Denmark,
    Dominica,
    Dominican_Republic UMETA(DisplayName = "Dominican Republic"),
    Algeria,
    Ecuador,
    Estonia,
    Egypt,
    Western_Sahara UMETA(DisplayName = "Western Sahara"),
    Eritrea,
    Spain,
    Ethiopia,
    Finland,
    Fiji,
    Falkland_Islands_Malvinas UMETA(DisplayName = "Falkland Islands Malvinas"),
    Micronesia,
    Faroe_Islands UMETA(DisplayName = "Faroe Islands"),
    France,
    Gabon,
    United_Kingdom UMETA(DisplayName = "United Kingdom"),
    Grenada,
    Georgia,
    French_Guiana UMETA(DisplayName = "French Guiana"),
    Guernsey,
    Ghana,
    Gibraltar,
    Greenland,
    Gambia,
    Guinea,
    Guadeloupe,
    Equatorial_Guinea UMETA(DisplayName = "Equatorial Guinea"),
    Greece,
    South_Georgia_and_the_South_Sandwich_Islands UMETA(DisplayName = "South Georgia and the South Sandwich Islands"),
    Guatemala,
    Guam,
    Guinea_Bissau UMETA(DisplayName = "Guinea Bissau"),
    Guyana,
    Hong_Kong UMETA(DisplayName = "Hong Kong"),
    Heard_Island_and_McDonald_Islands UMETA(DisplayName = "Heard Island and McDonald Islands"),
    Honduras,
    Croatia,
    Haiti,
    Hungary,
    Indonesia,
    Ireland,
    Israel,
    Isle_of_Man UMETA(DisplayName = "Isle of Man"),
    India,
    British_Indian_Ocean_Territory UMETA(DisplayName = "British Indian Ocean Territory"),
    Iraq,
    Iran,
    Iceland,
    Italy,
    Jersey,
    Jamaica,
    Jordan,
    Japan,
    Kenya,
    Kyrgyzstan,
    Cambodia,
    Kiribati,
    Comoros,
    Saint_Kitts_and_Nevis UMETA(DisplayName = "Saint Kitts and Nevis"),
    Democratic_Peoples_Republic_of_Korea UMETA(DisplayName = "Democratic Peoples Republic of Korea"),
    Republic_of_Korea UMETA(DisplayName = "Republic of Korea"),
    Kuwait,
    Cayman_Islands UMETA(DisplayName = "Cayman Islands"),
    Kazakhstan,
    Lao_Peoples_Democratic_Republic UMETA(DisplayName = "Lao Peoples Democratic Republic"),
    Lebanon,
    Saint_Lucia UMETA(DisplayName = "Saint Lucia"),
    Liechtenstein,
    Sri_Lanka UMETA(DisplayName = "Sri Lanka"),
    Liberia,
    Lesotho,
    Lithuania,
    Luxembourg,
    Latvia,
    Libyan_Arab_Jamahiriya UMETA(DisplayName = "Libyan Arab Jamahiriya"),
    Morocco,
    Monaco,
    Moldova,
    Montenegro,
    Saint_Martin_French UMETA(DisplayName = "Saint Martin French"),
    Madagascar,
    Marshall_Islands UMETA(DisplayName = "Marshall Islands"),
    North_Macedonia UMETA(DisplayName = "North Macedonia"),
    Mali,
    Myanmar,
    Mongolia,
    Macau,
    Northern_Mariana_Islands UMETA(DisplayName = "Northern Mariana Islands"),
    Martinique,
    Mauritania,
    Montserrat,
    Malta,
    Mauritius,
    Maldives,
    Malawi,
    Mexico,
    Malaysia,
    Mozambique,
    Namibia,
    New_Caledonia UMETA(DisplayName = "New Caledonia"),
    Niger,
    Norfolk_Island UMETA(DisplayName = "Norflok Island"),
    Nigeria,
    Nicaragua,
    Netherlands,
    Norway,
    Nepal,
    Nauru,
    Niue,
    New_Zealand,
    Oman,
    Panama,
    Peru,
    French_Polynesia UMETA(DisplayName = "French Polynesia"),
    Papua_New_Guinea UMETA(DisplayName = "Papua New Guinea"),
    Philippines,
    Pakistan,
    Poland,
    Saint_Pierre_and_Miquelon UMETA(DisplayName = "Saint Pierre and Miquelon"),
    Pitcairn,
    Puerto_Rico UMETA(DisplayName = "Puerto Rico"),
    Palestinian_Territory UMETA(DisplayName = "Palestinian Territory"),
    Portugal,
    Palau,
    Paraguay,
    Qatar,
    Reunion,
    Romania,
    Serbia,
    Russian_Federation UMETA(DisplayName = "Russian Federation"),
    Rwanda,
    Saudi_Arabia UMETA(DisplayName = "Saudi Arabia"),
    Solomon_Islands UMETA(DisplayName = "Solomon Islands"),
    Seychelles,
    Sudan,
    Sweden,
    Singapore,
    Saint_Helena UMETA(DisplayName = "Saint Helena"),
    Slovenia,
    Svalbard_and_Jan_Mayen_Islands UMETA(DisplayName = "Svalbard and Jan Mayen Islands"),
    Slovakia,
    Sierra_Leone UMETA(DisplayName = "Sierra Leone"),
    San_Marino UMETA(DisplayName = "San Marino"),
    Senegal,
    Somalia,
    Suriname,
    South_Sudan UMETA(DisplayName = "South Sudan"),
    Sao_Tome_and_Principe UMETA(DisplayName = "Sao Tome and Principe"),
    El_Salvador UMETA(DisplayName = "El Salvador"),
    Sint_Maarten_Dutch UMETA(DisplayName = "Dutch Sint Maarten"),
    Syrian_Arab_Republic UMETA(DisplayName = "Syrian Arab Republic"),
    Swaziland,
    Turks_and_Caicos_Islands UMETA(DisplayName = "Turks and Caicos Islands"),
    Chad,
    French_Southern_Territories UMETA(DisplayName = "French Southern Territories"),
    Togo,
    Thailand,
    Tajikistan,
    Tokelau,
    Timor_Leste UMETA(DisplayName = "Timor Leste"),
    Turkmenistan,
    Tunisia,
    Tonga,
    Turkey,
    Trinidad_and_Tobago UMETA(DisplayName = "Trinidad and Tobago"),
    Tuvalu,
    Taiwan,
    Tanzania,
    Ukraine,
    Uganda,
    United_States_Minor_Outlying_Islands UMETA(DisplayName = "United States Minor Outlying Islands"),
    United_States UMETA(DisplayName = "United States"),
    Uruguay,
    Uzbekistan,
    Holy_See UMETA(DisplayName = "Holy See"),
    Saint_Vincent_and_the_Grenadines UMETA(DisplayName = "Saint Vincent and the Grenadines"),
    Venezuela,
    Virgin_Islands_British UMETA(DisplayName = "British Virgin Islands"),
    Virgin_Islands_US UMETA(DisplayName = "US Virgin Islands"),
    Vietnam,
    Vanuatu,
    Wallis_and_Futuna_Islands UMETA(DisplayName = "Wallis and Futuna Islands"),
    Samoa,
    Kosovo,
    Yemen,
    Mayotte,
    Yugoslavia,
    South_Africa UMETA(DisplayName = "South Africa"),
    Zambia,
    Zimbabwe
};

UENUM(BlueprintType)
enum EPlayerGender
{
    m UMETA(DisplayName = "Male"),
    f UMETA(DisplayName = "Female"),
    n UMETA(DisplayName = "Non-Binary/Unknown")
};

UENUM(BlueprintType)
enum EReasonForAbort
{
    Cancel,
    Other
};


/*************************** TMaps ***************************/

const TMap<EReasonForAbort, FString> AbortReasonsMap = {
    { EReasonForAbort::Other, "Other" },
    { EReasonForAbort::Cancel, "Cancel" }
};

const TMap<EPlayerGender, FString> GenderMap = {
    { EPlayerGender::m, "m" },
    { EPlayerGender::f, "f" },
    { EPlayerGender::n, "n" }
};

const TMap<ESupportedPlatform, FString> PlatformMap = {
    { ESupportedPlatform::PlatformUnknown, "unknown" },
    { ESupportedPlatform::PC, "pc"},
    { ESupportedPlatform::Playstation, "ps" },
    { ESupportedPlatform::Xbox, "xbox" },
    { ESupportedPlatform::Android, "android" },
    { ESupportedPlatform::MacOS, "mac" },
    { ESupportedPlatform::IOS, "ios" },
    { ESupportedPlatform::Wildcard, "*" }
};

const TMap<EPlayerIDType, FString> PlayerIDTypeMap = {
    { EPlayerIDType::Apple, "apple" },
    { EPlayerIDType::Epic, "epic" },
    { EPlayerIDType::Google, "google" },
    { EPlayerIDType::Microsoft, "microsoft" },
    { EPlayerIDType::Nintendo, "nintendo" },
    { EPlayerIDType::Sony, "sony" },
    { EPlayerIDType::Steam, "steam" },
    { EPlayerIDType::Twitch, "twitch" }
};

const TMap<ESupportedLanguages, FString> LanguagesMap = {
    { ESupportedLanguages::Arabic, "ara" },
    { ESupportedLanguages::Chinese_Mandarin, "zho" },
    { ESupportedLanguages::English, "eng" },
    { ESupportedLanguages::French, "fra" },
    { ESupportedLanguages::German, "deu" },
    { ESupportedLanguages::Italian, "ita" },
    { ESupportedLanguages::Japanese, "jpn" },
    { ESupportedLanguages::Korean, "kor" },
    { ESupportedLanguages::Polish, "pol" },
    { ESupportedLanguages::Portuguese, "por" },
    { ESupportedLanguages::Russian, "rus" },
    { ESupportedLanguages::Spanish, "spa" },
    { ESupportedLanguages::Thai, "tha" },
    { ESupportedLanguages::Turkish, "tur" }
};

const TMap<ESupportedCurrencies, FString> CurrenciesMap = {
    { ESupportedCurrencies::Australian_Dollar, "AUD" },
    { ESupportedCurrencies::Brazilian_Real, "BRL" },
    { ESupportedCurrencies::Canadian_Dollar, "CAD" },
    { ESupportedCurrencies::Chinese_Yuan, "CNY" },
    { ESupportedCurrencies::Euro, "EUR" },
    { ESupportedCurrencies::Hong_Kong_Dollar, "HKD" },
    { ESupportedCurrencies::Indian_Rupee, "INR" },
    { ESupportedCurrencies::Japanese_Yen, "JPY" },
    { ESupportedCurrencies::Mexican_Peso, "MXN" },
    { ESupportedCurrencies::New_Zealand_Dollar, "NZD" },
    { ESupportedCurrencies::Norwegian_Krone, "NOK" },
    { ESupportedCurrencies::Pound_Sterling, "GBP" },
    { ESupportedCurrencies::Romanian_Leu, "RON" },
    { ESupportedCurrencies::Russian_Ruble, "RUB" },
    { ESupportedCurrencies::Singapore_Dollar, "SGD" },
    { ESupportedCurrencies::South_African_Rand, "ZAR" },
    { ESupportedCurrencies::South_Korean_Won, "KRW" },
    { ESupportedCurrencies::Swedish_Krona, "SEK" },
    { ESupportedCurrencies::Swiss_Franc, "CHF" },
    { ESupportedCurrencies::Turkish_Lira, "TRY" },
    { ESupportedCurrencies::United_States_Dollar, "USD" },
    { ESupportedCurrencies::CurrencyUnknown, "XXX" }
};

const TMap<ESupportedCountries, FString> CountriesMap = {
    { ESupportedCountries::Andorra, "AD" },
    { ESupportedCountries::United_Arab_Emirates, "AE" },
    { ESupportedCountries::Afghanistan, "AF" },
    { ESupportedCountries::Antigua_and_Barbuda, "AG" },
    { ESupportedCountries::Anguilla, "AI" },
    { ESupportedCountries::Albania, "AL" },
    { ESupportedCountries::Armenia, "AM" },
    { ESupportedCountries::Netherlands_Antilles, "AN" },
    { ESupportedCountries::Angola, "AO" },
    { ESupportedCountries::Antarctica, "AQ" },
    { ESupportedCountries::Argentina, "AR" },
    { ESupportedCountries::American_Somoa, "AS" },
    { ESupportedCountries::Austria, "AT" },
    { ESupportedCountries::Australia, "AU" },
    { ESupportedCountries::Aruba, "AW" },
    { ESupportedCountries::Aland_Islands, "AX" },
    { ESupportedCountries::Azerbaijan, "AZ" },
    { ESupportedCountries::Bosnia_and_Herzegovina, "BA" },
    { ESupportedCountries::Barbados, "BB" },
    { ESupportedCountries::Bangladesh, "BD" },
    { ESupportedCountries::Belgium, "BE" },
    { ESupportedCountries::Burkina_Faso, "BF" },
    { ESupportedCountries::Bulgaria, "BG" },
    { ESupportedCountries::Bahrain, "BH" },
    { ESupportedCountries::Burundi, "BI" },
    { ESupportedCountries::Benin, "BJ" },
    { ESupportedCountries::Saint_Barthelemy, "BL" },
    { ESupportedCountries::Bermuda, "BM" },
    { ESupportedCountries::Brunei_Darussalam, "BN" },
    { ESupportedCountries::Bolivia, "BO" },
    { ESupportedCountries::Bonaire_Sint_Eustatius_and_Saba, "BQ" },
    { ESupportedCountries::Brazil, "BR" },
    { ESupportedCountries::Bahamas, "BS" },
    { ESupportedCountries::Bhutan, "BT" },
    { ESupportedCountries::Bouvet_Island, "BV" },
    { ESupportedCountries::Botswana, "BW" },
    { ESupportedCountries::Belarus, "BY" },
    { ESupportedCountries::Belize, "BZ" },
    { ESupportedCountries::Canada, "CA" },
    { ESupportedCountries::Cocos_Keeling_Islands, "CC" },
    { ESupportedCountries::Democratic_Republic_of_the_Congo, "CD" },
    { ESupportedCountries::Central_African_Republic, "CF" },
    { ESupportedCountries::Congo, "CG" },
    { ESupportedCountries::Switzerland, "CH" },
    { ESupportedCountries::Cote_dIvoire, "CI" },
    { ESupportedCountries::Cook_Islands, "CK" },
    { ESupportedCountries::Chile, "CL" },
    { ESupportedCountries::Cameroon, "CM" },
    { ESupportedCountries::China, "CN" },
    { ESupportedCountries::Colombia, "CO" },
    { ESupportedCountries::Costa_Rica, "CR" },
    { ESupportedCountries::Cuba, "CU" },
    { ESupportedCountries::Cape_Verde, "CV" },
    { ESupportedCountries::Curacao, "CW" },
    { ESupportedCountries::Christmas_Island, "CX" },
    { ESupportedCountries::Cyprus, "CY" },
    { ESupportedCountries::Czech_Republic, "CZ" },
    { ESupportedCountries::Germany, "DE" },
    { ESupportedCountries::Djibouti, "DJ" },
    { ESupportedCountries::Denmark, "DK" },
    { ESupportedCountries::Dominica, "DM" },
    { ESupportedCountries::Dominican_Republic, "DO" },
    { ESupportedCountries::Algeria, "DZ" },
    { ESupportedCountries::Ecuador, "EC" },
    { ESupportedCountries::Estonia, "EE" },
    { ESupportedCountries::Egypt, "EG" },
    { ESupportedCountries::Western_Sahara, "EH" },
    { ESupportedCountries::Eritrea, "ER" },
    { ESupportedCountries::Spain, "ES" },
    { ESupportedCountries::Ethiopia, "ET" },
    { ESupportedCountries::Finland, "FI" },
    { ESupportedCountries::Fiji, "FJ" },
    { ESupportedCountries::Falkland_Islands_Malvinas, "FK" },
    { ESupportedCountries::Micronesia, "FM" },
    { ESupportedCountries::Faroe_Islands, "FO" },
    { ESupportedCountries::France, "FR" },
    { ESupportedCountries::Gabon, "GA" },
    { ESupportedCountries::United_Kingdom, "GB" },
    { ESupportedCountries::Grenada, "GD" },
    { ESupportedCountries::Georgia, "GE" },
    { ESupportedCountries::French_Guiana, "GF" },
    { ESupportedCountries::Guernsey, "GG" },
    { ESupportedCountries::Ghana, "GH" },
    { ESupportedCountries::Gibraltar, "GI" },
    { ESupportedCountries::Greenland, "GL" },
    { ESupportedCountries::Gambia, "GM" },
    { ESupportedCountries::Guinea, "GN" },
    { ESupportedCountries::Guadeloupe, "GP" },
    { ESupportedCountries::Equatorial_Guinea, "GQ" },
    { ESupportedCountries::Greece, "GR" },
    { ESupportedCountries::South_Georgia_and_the_South_Sandwich_Islands, "GS" },
    { ESupportedCountries::Guatemala, "GT" },
    { ESupportedCountries::Guam, "GU" },
    { ESupportedCountries::Guinea_Bissau, "GW" },
    { ESupportedCountries::Guyana, "GY" },
    { ESupportedCountries::Hong_Kong, "HK" },
    { ESupportedCountries::Heard_Island_and_McDonald_Islands, "HM" },
    { ESupportedCountries::Honduras, "HN" },
    { ESupportedCountries::Croatia, "HR" },
    { ESupportedCountries::Haiti, "HT" },
    { ESupportedCountries::Hungary, "HU" },
    { ESupportedCountries::Indonesia, "ID" },
    { ESupportedCountries::Ireland, "IE" },
    { ESupportedCountries::Israel, "IL" },
    { ESupportedCountries::Isle_of_Man, "IM" },
    { ESupportedCountries::India, "IN" },
    { ESupportedCountries::British_Indian_Ocean_Territory, "IO" },
    { ESupportedCountries::Iraq, "IQ" },
    { ESupportedCountries::Iran, "IR" },
    { ESupportedCountries::Iceland, "IS" },
    { ESupportedCountries::Italy, "IT" },
    { ESupportedCountries::Jersey, "JE" },
    { ESupportedCountries::Jamaica, "JM" },
    { ESupportedCountries::Jordan, "JO" },
    { ESupportedCountries::Japan, "JP" },
    { ESupportedCountries::Kenya, "KE" },
    { ESupportedCountries::Kyrgyzstan, "KG" },
    { ESupportedCountries::Cambodia, "KH" },
    { ESupportedCountries::Kiribati, "KI" },
    { ESupportedCountries::Comoros, "KM" },
    { ESupportedCountries::Saint_Kitts_and_Nevis, "KN" },
    { ESupportedCountries::Democratic_Peoples_Republic_of_Korea, "KP" },
    { ESupportedCountries::Republic_of_Korea, "KR" },
    { ESupportedCountries::Kuwait, "KW" },
    { ESupportedCountries::Cayman_Islands, "KY" },
    { ESupportedCountries::Kazakhstan, "KZ" },
    { ESupportedCountries::Lao_Peoples_Democratic_Republic, "LA" },
    { ESupportedCountries::Lebanon, "LB" },
    { ESupportedCountries::Saint_Lucia, "LC" },
    { ESupportedCountries::Liechtenstein, "LI" },
    { ESupportedCountries::Sri_Lanka, "LK" },
    { ESupportedCountries::Liberia, "LR" },
    { ESupportedCountries::Lesotho, "LS" },
    { ESupportedCountries::Lithuania, "LT" },
    { ESupportedCountries::Luxembourg, "LU" },
    { ESupportedCountries::Latvia, "LV" },
    { ESupportedCountries::Libyan_Arab_Jamahiriya, "LY" },
    { ESupportedCountries::Morocco, "MA" },
    { ESupportedCountries::Monaco, "MC" },
    { ESupportedCountries::Moldova, "MD" },
    { ESupportedCountries::Montenegro, "ME" },
    { ESupportedCountries::Saint_Martin_French, "MF" },
    { ESupportedCountries::Madagascar, "MG" },
    { ESupportedCountries::Marshall_Islands, "MH" },
    { ESupportedCountries::North_Macedonia, "MK" },
    { ESupportedCountries::Mali, "ML" },
    { ESupportedCountries::Myanmar, "MM" },
    { ESupportedCountries::Mongolia, "MN" },
    { ESupportedCountries::Macau, "MO" },
    { ESupportedCountries::Northern_Mariana_Islands, "MP" },
    { ESupportedCountries::Martinique, "MQ" },
    { ESupportedCountries::Mauritania, "MR" },
    { ESupportedCountries::Montserrat, "MS" },
    { ESupportedCountries::Malta, "MT" },
    { ESupportedCountries::Mauritius, "MU" },
    { ESupportedCountries::Maldives, "MV" },
    { ESupportedCountries::Malawi, "MW" },
    { ESupportedCountries::Mexico, "MX" },
    { ESupportedCountries::Malaysia, "MY" },
    { ESupportedCountries::Mozambique, "MZ" },
    { ESupportedCountries::Namibia, "NA" },
    { ESupportedCountries::New_Caledonia, "NC" },
    { ESupportedCountries::Niger, "NE" },
    { ESupportedCountries::Norfolk_Island, "NF" },
    { ESupportedCountries::Nigeria, "NG" },
    { ESupportedCountries::Nicaragua, "NI" },
    { ESupportedCountries::Netherlands, "NL" },
    { ESupportedCountries::Norway, "NO" },
    { ESupportedCountries::Nepal, "NP" },
    { ESupportedCountries::Nauru, "NR" },
    { ESupportedCountries::Niue, "NU" },
    { ESupportedCountries::New_Zealand, "NZ" },
    { ESupportedCountries::Oman, "OM" },
    { ESupportedCountries::Panama, "PA" },
    { ESupportedCountries::Peru, "PE" },
    { ESupportedCountries::French_Polynesia, "PF" },
    { ESupportedCountries::Papua_New_Guinea, "PG" },
    { ESupportedCountries::Philippines, "PH" },
    { ESupportedCountries::Pakistan, "PK" },
    { ESupportedCountries::Poland, "PL" },
    { ESupportedCountries::Saint_Pierre_and_Miquelon, "PM" },
    { ESupportedCountries::Pitcairn, "PN" },
    { ESupportedCountries::Puerto_Rico, "PR" },
    { ESupportedCountries::Palestinian_Territory, "PS" },
    { ESupportedCountries::Portugal, "PT" },
    { ESupportedCountries::Palau, "PW" },
    { ESupportedCountries::Paraguay, "PY" },
    { ESupportedCountries::Qatar, "QA" },
    { ESupportedCountries::Reunion, "RE" },
    { ESupportedCountries::Romania, "RO" },
    { ESupportedCountries::Serbia, "RS" },
    { ESupportedCountries::Russian_Federation, "RU" },
    { ESupportedCountries::Rwanda, "RW" },
    { ESupportedCountries::Saudi_Arabia, "SA" },
    { ESupportedCountries::Solomon_Islands, "SB" },
    { ESupportedCountries::Seychelles, "SC" },
    { ESupportedCountries::Sudan, "SD" },
    { ESupportedCountries::Sweden, "SE" },
    { ESupportedCountries::Singapore, "SG" },
    { ESupportedCountries::Saint_Helena, "SH" },
    { ESupportedCountries::Slovenia, "SI" },
    { ESupportedCountries::Svalbard_and_Jan_Mayen_Islands, "SJ" },
    { ESupportedCountries::Slovakia, "SK" },
    { ESupportedCountries::Sierra_Leone, "SL" },
    { ESupportedCountries::San_Marino, "SM" },
    { ESupportedCountries::Senegal, "SN" },
    { ESupportedCountries::Somalia, "SO" },
    { ESupportedCountries::Suriname, "SR" },
    { ESupportedCountries::South_Sudan, "SS" },
    { ESupportedCountries::Sao_Tome_and_Principe, "ST" },
    { ESupportedCountries::El_Salvador, "SV" },
    { ESupportedCountries::Sint_Maarten_Dutch, "SX" },
    { ESupportedCountries::Syrian_Arab_Republic, "SY" },
    { ESupportedCountries::Swaziland, "SZ" },
    { ESupportedCountries::Turks_and_Caicos_Islands, "TC" },
    { ESupportedCountries::Chad, "TD" },
    { ESupportedCountries::French_Southern_Territories, "TF" },
    { ESupportedCountries::Togo, "TG" },
    { ESupportedCountries::Thailand, "TH" },
    { ESupportedCountries::Tajikistan, "TJ" },
    { ESupportedCountries::Tokelau, "TK" },
    { ESupportedCountries::Timor_Leste, "TL" },
    { ESupportedCountries::Turkmenistan, "TM" },
    { ESupportedCountries::Tunisia, "TN" },
    { ESupportedCountries::Tonga, "TO" },
    { ESupportedCountries::Turkey, "TR" },
    { ESupportedCountries::Trinidad_and_Tobago, "TT" },
    { ESupportedCountries::Tuvalu, "TV" },
    { ESupportedCountries::Taiwan, "TW" },
    { ESupportedCountries::Tanzania, "TZ" },
    { ESupportedCountries::Ukraine, "UA" },
    { ESupportedCountries::Uganda, "UG" },
    { ESupportedCountries::United_States_Minor_Outlying_Islands, "UM" },
    { ESupportedCountries::United_States, "US" },
    { ESupportedCountries::Uruguay, "UY" },
    { ESupportedCountries::Uzbekistan, "UZ" },
    { ESupportedCountries::Holy_See, "VA" },
    { ESupportedCountries::Saint_Vincent_and_the_Grenadines, "VC" },
    { ESupportedCountries::Venezuela, "VE" },
    { ESupportedCountries::Virgin_Islands_British, "VG" },
    { ESupportedCountries::Virgin_Islands_US, "VI" },
    { ESupportedCountries::Vietnam, "VN" },
    { ESupportedCountries::Vanuatu, "VU" },
    { ESupportedCountries::Wallis_and_Futuna_Islands, "WF" },
    { ESupportedCountries::Samoa, "WS" },
    { ESupportedCountries::Kosovo, "XK" },
    { ESupportedCountries::CountryUnknown, "XX" },
    { ESupportedCountries::Yemen, "YE" },
    { ESupportedCountries::Mayotte, "YT" },
    { ESupportedCountries::Yugoslavia, "YU" },
    { ESupportedCountries::South_Africa, "ZA" },
    { ESupportedCountries::Zambia, "ZM" },
    { ESupportedCountries::Zimbabwe, "ZW" }
};

/*************************** Structs ***************************/

USTRUCT(BlueprintType, Blueprintable)
struct FAuthorizationToken
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString AccessToken;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString TokenType;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 ExpiresIn;

    FAuthorizationToken()
    {
        AccessToken = FString(TEXT(""));
        TokenType = FString(TEXT(""));
        ExpiresIn = 0;
    }

    FAuthorizationToken(FString InToken, FString InType, int32 InExpires)
    {
        AccessToken = InToken;
        TokenType = InType;
        ExpiresIn = InExpires;
    }
};

USTRUCT(BlueprintType, Blueprintable)
struct FCurrency
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString CurrencyName;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 Value;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 DecimalPointDigitFromRight;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 CurrencyType;

    FCurrency()
    {
        CurrencyName = CurrenciesMap[ESupportedCurrencies::CurrencyUnknown];
        Value = 0;
        DecimalPointDigitFromRight = 0;
        CurrencyType = 0;
    }

    FCurrency(ESupportedCurrencies InName, int32 InValue, int32 DecimalPlace, int32 Type, FString CustomName = "")
    {
        CurrencyName = (InName == ESupportedCurrencies::In_Game) ? CustomName : CurrenciesMap[InName];
        Value = InValue;
        DecimalPointDigitFromRight = DecimalPlace;
        CurrencyType = Type;
    }
};

USTRUCT(BlueprintType, Blueprintable)
struct FClientDetails
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString Country;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString IDFA;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString Platform;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString Language;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString IP;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 WidthInPixels;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 HeightInPixels;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString PlayerID;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString PlayerIDType;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString Device;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 COPPA;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 UnderAge;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 Age;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString SlotID;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 LifetimeSpending;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FCurrency LifetimeSpendingValue;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    TArray<FCurrency> RewardValues;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 GameServer;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 LimitTracking;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 GDPR;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 GDPRConsent;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    bool MediaFiles;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 MaxLength;

    FClientDetails()
    {
        Country = CountriesMap[ESupportedCountries::CountryUnknown];
        IDFA = "Unknown";
        Platform = PlatformMap[ESupportedPlatform::PlatformUnknown];
        Language = LanguagesMap[ESupportedLanguages::English];
        IP = "";
        WidthInPixels = 0;
        HeightInPixels = 0;
        PlayerID = "";
        PlayerIDType = "";
        Device = "";
        COPPA = 0;
        UnderAge = 0;
        Age = 0;
        SlotID = "";
        LifetimeSpending = 0;
        LifetimeSpendingValue = FCurrency();
        GameServer = 0;
        LimitTracking = 0;
        GDPR = 0;
        GDPRConsent = 0;
        MediaFiles = false;
        MaxLength = 0;
    }

    FClientDetails(ESupportedCountries InCountry, FString InIDFA, ESupportedPlatform InPlatform, ESupportedLanguages InLanguage, FString InIP = "", int32 InWidth = 0, int32 InHeight = 0, FString InPlayerID = "",
        EPlayerIDType InPlayerIDType = EPlayerIDType::UnknownPIDType, FString InDevice = "", int32 InCOPPA = 0, int32 InUnderAge = 0, int32 InAge = 0, FString InSlotID = "", int32 InLifetimeSpending = 0, FCurrency InLifetimeSpendingValue = FCurrency(),
        TArray<FCurrency> InRewardValues = TArray<FCurrency>(), int32 InGameServer = 0, int32 InLimitTracking = 0, int32 InGDPR = 0, int32 InGDPRConsent = 0, bool InMediaFiles = false, int32 InMaxLength = 0)
    {
        Country = CountriesMap[InCountry];
        IDFA = InIDFA;
        Platform = PlatformMap[InPlatform];
        Language = LanguagesMap[InLanguage];
        IP = InIP;
        WidthInPixels = InWidth;
        HeightInPixels = InHeight;
        PlayerID = InPlayerID;
        (InPlayerIDType == EPlayerIDType::UnknownPIDType) ? PlayerIDType = "" : PlayerIDType = PlayerIDTypeMap[InPlayerIDType];
        Device = InDevice;
        COPPA = InCOPPA;
        UnderAge = InUnderAge;
        Age = InAge;
        SlotID = InSlotID;
        LifetimeSpending = InLifetimeSpending;
        LifetimeSpendingValue = InLifetimeSpendingValue;
        RewardValues = InRewardValues;
        LimitTracking = InLimitTracking;
        GDPR = InGDPR;
        GDPRConsent = InGDPRConsent;
        MediaFiles = InMediaFiles;
        MaxLength = InMaxLength;
    }

    bool IsValid()
    {
        if (Country.IsEmpty() || IDFA.IsEmpty() || Platform.IsEmpty() || Language.IsEmpty())
        {
            return false;
        }
        return true;
    }
};

USTRUCT(BlueprintType, Blueprintable)
struct FOpportunity
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString CreativeURL;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 Length;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString Receipt;

    FOpportunity()
    {
        CreativeURL = "";
        Length = 0;
        Receipt = "";
    }

    bool IsValid()
    {
        if (CreativeURL.IsEmpty() || Receipt.IsEmpty())
        {
            return false;
        }
        return true;
    }
};

USTRUCT(BlueprintType, Blueprintable)
struct FSessionDetails
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString Country;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString Platform;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString Language;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString PlayerID;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString PlayerIDType;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString Device;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 COPPA;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 UnderAge;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 Age;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 MinAge;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 MaxAge;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString Gender;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 LifetimeSpending;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FCurrency LifetimeSpendingValue;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    FString PlayerFirstPlayedDate;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 GameServer;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 LimitTracking;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 GDPR;

    UPROPERTY(BlueprintReadOnly, Category = PLAYERWON)
    int32 GDPRConsent;

    FSessionDetails()
    {
        Country = CountriesMap[ESupportedCountries::CountryUnknown];
        Platform = PlatformMap[ESupportedPlatform::PlatformUnknown];
        Language = LanguagesMap[ESupportedLanguages::English];
        PlayerID = "";
        PlayerIDType = "";
        Device = "";
        COPPA = 0;
        UnderAge = 0;
        Age = 0;
        MinAge = 0;
        MaxAge = 0;
        Gender = GenderMap[EPlayerGender::n];
        LifetimeSpending = 0;
        LifetimeSpendingValue = FCurrency();
        PlayerFirstPlayedDate = "";
        GameServer = 0;
        LimitTracking = 0;
        GDPR = 0;
        GDPRConsent = 0;
    }

    FSessionDetails(ESupportedCountries InCountry, ESupportedPlatform InPlatform, ESupportedLanguages InLanguage, FString InPlayerID = "", EPlayerIDType InPlayerIDType = EPlayerIDType::UnknownPIDType, FString InDevice = "", int32 InCOPPA = 0,
        int32 InUnderAge = 0, int32 InAge = 0, int32 InMinAge = 0, int32 InMaxAge = 0, TEnumAsByte<EPlayerGender> InGender = EPlayerGender::n, int32 InLifetimeSpending = 0, FCurrency InLifetimeSpendingValue = FCurrency(), FString InPlayerFirstPlayedDate = "", int32 InGameServer = 0,
        int32 InLimitTracking = 0, int32 InGDPR = 0, int32 InGDPRConsent = 0)
    {
        Country = CountriesMap[InCountry];
        Platform = PlatformMap[InPlatform];
        Language = LanguagesMap[InLanguage];
        PlayerID = InPlayerID;
        PlayerIDType = PlayerIDTypeMap[InPlayerIDType];
        Device = InDevice;
        COPPA = InCOPPA;
        UnderAge = InUnderAge;
        Age = InAge;
        MinAge = InMinAge;
        MaxAge = InMaxAge;
        Gender = GenderMap[InGender];
        LifetimeSpending = InLifetimeSpending;
        LifetimeSpendingValue = InLifetimeSpendingValue;
        PlayerFirstPlayedDate = InPlayerFirstPlayedDate;
        GameServer = InGameServer;
        LimitTracking = InLimitTracking;
        GDPR = InGDPR;
        GDPRConsent = InGDPRConsent;
    }

    bool IsValid()
    {
        if (Country.IsEmpty() || Platform.IsEmpty() || Language.IsEmpty())
        {
            return false;
        }
        return true;
    }
};

