using System.Collections.Generic;

namespace PlayerWON
{
    internal static class DataLibrary
    {
        /// <summary>
        /// Dictionary of supported countries
        /// </summary>
        public static Dictionary<SupportedCountries, string> CountryDictionary = new Dictionary<SupportedCountries, string>()
        {
            { SupportedCountries.Andorra, "AD" },
            { SupportedCountries.United_Arab_Emirates, "AE" },
            { SupportedCountries.Afghanistan, "AF" },
            { SupportedCountries.Antigua_and_Barbuda, "AG" },
            { SupportedCountries.Anguilla, "AI" },
            { SupportedCountries.Albania, "AL" },
            { SupportedCountries.Armenia, "AM" },
            { SupportedCountries.Netherlands_Antilles, "AN" },
            { SupportedCountries.Angola, "AO" },
            { SupportedCountries.Antarctica, "AQ" },
            { SupportedCountries.Argentina, "AR" },
            { SupportedCountries.American_Somoa, "AS" },
            { SupportedCountries.Austria, "AT" },
            { SupportedCountries.Australia, "AU" },
            { SupportedCountries.Aruba, "AW" },
            { SupportedCountries.Aland_Islands, "AX" },
            { SupportedCountries.Azerbaijan, "AZ" },
            { SupportedCountries.Bosnia_and_Herzegovina, "BA" },
            { SupportedCountries.Barbados, "BB" },
            { SupportedCountries.Bangladesh, "BD" },
            { SupportedCountries.Belgium, "BE" },
            { SupportedCountries.Burkina_Faso, "BF" },
            { SupportedCountries.Bulgaria, "BG" },
            { SupportedCountries.Bahrain, "BH" },
            { SupportedCountries.Burundi, "BI" },
            { SupportedCountries.Benin, "BJ" },
            { SupportedCountries.Saint_Barthelemy, "BL" },
            { SupportedCountries.Bermuda, "BM" },
            { SupportedCountries.Brunei_Darussalam, "BN" },
            { SupportedCountries.Bolivia, "BO" },
            { SupportedCountries.Bonaire_Sint_Eustatius_and_Saba, "BQ" },
            { SupportedCountries.Brazil, "BR" },
            { SupportedCountries.Bahamas, "BS" },
            { SupportedCountries.Bhutan, "BT" },
            { SupportedCountries.Bouvet_Island, "BV" },
            { SupportedCountries.Botswana, "BW" },
            { SupportedCountries.Belarus, "BY" },
            { SupportedCountries.Belize, "BZ" },
            { SupportedCountries.Canada, "CA" },
            { SupportedCountries.Cocos_Keeling_Islands, "CC" },
            { SupportedCountries.Democratic_Republic_of_the_Congo, "CD" },
            { SupportedCountries.Central_African_Republic, "CF" },
            { SupportedCountries.Congo, "CG" },
            { SupportedCountries.Switzerland, "CH" },
            { SupportedCountries.Cote_dIvoire, "CI" },
            { SupportedCountries.Cook_Islands, "CK" },
            { SupportedCountries.Chile, "CL" },
            { SupportedCountries.Cameroon, "CM" },
            { SupportedCountries.China, "CN" },
            { SupportedCountries.Colombia, "CO" },
            { SupportedCountries.Costa_Rica, "CR" },
            { SupportedCountries.Cuba, "CU" },
            { SupportedCountries.Cape_Verde, "CV" },
            { SupportedCountries.Curacao, "CW" },
            { SupportedCountries.Christmas_Island, "CX" },
            { SupportedCountries.Cyprus, "CY" },
            { SupportedCountries.Czech_Republic, "CZ" },
            { SupportedCountries.Germany, "DE" },
            { SupportedCountries.Djibouti, "DJ" },
            { SupportedCountries.Denmark, "DK" },
            { SupportedCountries.Dominica, "DM" },
            { SupportedCountries.Dominican_Republic, "DO" },
            { SupportedCountries.Algeria, "DZ" },
            { SupportedCountries.Ecuador, "EC" },
            { SupportedCountries.Estonia, "EE" },
            { SupportedCountries.Egypt, "EG" },
            { SupportedCountries.Western_Sahara, "EH" },
            { SupportedCountries.Eritrea, "ER" },
            { SupportedCountries.Spain, "ES" },
            { SupportedCountries.Ethiopia, "ET" },
            { SupportedCountries.Finland, "FI" },
            { SupportedCountries.Fiji, "FJ" },
            { SupportedCountries.Falkland_Islands_Malvinas, "FK" },
            { SupportedCountries.Micronesia, "FM" },
            { SupportedCountries.Faroe_Islands, "FO" },
            { SupportedCountries.France, "FR" },
            { SupportedCountries.Gabon, "GA" },
            { SupportedCountries.United_Kingdom, "GB" },
            { SupportedCountries.Grenada, "GD" },
            { SupportedCountries.Georgia, "GE" },
            { SupportedCountries.French_Guiana, "GF" },
            { SupportedCountries.Guernsey, "GG" },
            { SupportedCountries.Ghana, "GH" },
            { SupportedCountries.Gibraltar, "GI" },
            { SupportedCountries.Greenland, "GL" },
            { SupportedCountries.Gambia, "GM" },
            { SupportedCountries.Guinea, "GN" },
            { SupportedCountries.Guadeloupe, "GP" },
            { SupportedCountries.Equatorial_Guinea, "GQ" },
            { SupportedCountries.Greece, "GR" },
            { SupportedCountries.South_Georgia_and_the_South_Sandwich_Islands, "GS" },
            { SupportedCountries.Guatemala, "GT" },
            { SupportedCountries.Guam, "GU" },
            { SupportedCountries.Guinea_Bissau, "GW" },
            { SupportedCountries.Guyana, "GY" },
            { SupportedCountries.Hong_Kong, "HK" },
            { SupportedCountries.Heard_Island_and_McDonald_Islands, "HM" },
            { SupportedCountries.Honduras, "HN" },
            { SupportedCountries.Croatia, "HR" },
            { SupportedCountries.Haiti, "HT" },
            { SupportedCountries.Hungary, "HU" },
            { SupportedCountries.Indonesia, "ID" },
            { SupportedCountries.Ireland, "IE" },
            { SupportedCountries.Israel, "IL" },
            { SupportedCountries.Isle_of_Man, "IM" },
            { SupportedCountries.India, "IN" },
            { SupportedCountries.British_Indian_Ocean_Territory, "IO" },
            { SupportedCountries.Iraq, "IQ" },
            { SupportedCountries.Iran, "IR" },
            { SupportedCountries.Iceland, "IS" },
            { SupportedCountries.Italy, "IT" },
            { SupportedCountries.Jersey, "JE" },
            { SupportedCountries.Jamaica, "JM" },
            { SupportedCountries.Jordan, "JO" },
            { SupportedCountries.Japan, "JP" },
            { SupportedCountries.Kenya, "KE" },
            { SupportedCountries.Kyrgyzstan, "KG" },
            { SupportedCountries.Cambodia, "KH" },
            { SupportedCountries.Kiribati, "KI" },
            { SupportedCountries.Comoros, "KM" },
            { SupportedCountries.Saint_Kitts_and_Nevis, "KN" },
            { SupportedCountries.Democratic_Peoples_Republic_of_Korea, "KP" },
            { SupportedCountries.Republic_of_Korea, "KR" },
            { SupportedCountries.Kuwait, "KW" },
            { SupportedCountries.Cayman_Islands, "KY" },
            { SupportedCountries.Kazakhstan, "KZ" },
            { SupportedCountries.Lao_Peoples_Democratic_Republic, "LA" },
            { SupportedCountries.Lebanon, "LB" },
            { SupportedCountries.Saint_Lucia, "LC" },
            { SupportedCountries.Liechtenstein, "LI" },
            { SupportedCountries.Sri_Lanka, "LK" },
            { SupportedCountries.Liberia, "LR" },
            { SupportedCountries.Lesotho, "LS" },
            { SupportedCountries.Lithuania, "LT" },
            { SupportedCountries.Luxembourg, "LU" },
            { SupportedCountries.Latvia, "LV" },
            { SupportedCountries.Libyan_Arab_Jamahiriya, "LY" },
            { SupportedCountries.Morocco, "MA" },
            { SupportedCountries.Monaco, "MC" },
            { SupportedCountries.Moldova, "MD" },
            { SupportedCountries.Montenegro, "ME" },
            { SupportedCountries.Saint_Martin_French, "MF" },
            { SupportedCountries.Madagascar, "MG" },
            { SupportedCountries.Marshall_Islands, "MH" },
            { SupportedCountries.North_Macedonia, "MK" },
            { SupportedCountries.Mali, "ML" },
            { SupportedCountries.Myanmar, "MM" },
            { SupportedCountries.Mongolia, "MN" },
            { SupportedCountries.Macau, "MO" },
            { SupportedCountries.Northern_Mariana_Islands, "MP" },
            { SupportedCountries.Martinique, "MQ" },
            { SupportedCountries.Mauritania, "MR" },
            { SupportedCountries.Montserrat, "MS" },
            { SupportedCountries.Malta, "MT" },
            { SupportedCountries.Mauritius, "MU" },
            { SupportedCountries.Maldives, "MV" },
            { SupportedCountries.Malawi, "MW" },
            { SupportedCountries.Mexico, "MX" },
            { SupportedCountries.Malaysia, "MY" },
            { SupportedCountries.Mozambique, "MZ" },
            { SupportedCountries.Namibia, "NA" },
            { SupportedCountries.New_Caledonia, "NC" },
            { SupportedCountries.Niger, "NE" },
            { SupportedCountries.Norfolk_Island, "NF" },
            { SupportedCountries.Nigeria, "NG" },
            { SupportedCountries.Nicaragua, "NI" },
            { SupportedCountries.Netherlands, "NL" },
            { SupportedCountries.Norway, "NO" },
            { SupportedCountries.Nepal, "NP" },
            { SupportedCountries.Nauru, "NR" },
            { SupportedCountries.Niue, "NU" },
            { SupportedCountries.New_Zealand, "NZ" },
            { SupportedCountries.Oman, "OM" },
            { SupportedCountries.Panama, "PA" },
            { SupportedCountries.Peru, "PE" },
            { SupportedCountries.French_Polynesia, "PF" },
            { SupportedCountries.Papua_New_Guinea, "PG" },
            { SupportedCountries.Philippines, "PH" },
            { SupportedCountries.Pakistan, "PK" },
            { SupportedCountries.Poland, "PL" },
            { SupportedCountries.Saint_Pierre_and_Miquelon, "PM" },
            { SupportedCountries.Pitcairn, "PN" },
            { SupportedCountries.Puerto_Rico, "PR" },
            { SupportedCountries.Palestinian_Territory, "PS" },
            { SupportedCountries.Portugal, "PT" },
            { SupportedCountries.Palau, "PW" },
            { SupportedCountries.Paraguay, "PY" },
            { SupportedCountries.Qatar, "QA" },
            { SupportedCountries.Reunion, "RE" },
            { SupportedCountries.Romania, "RO" },
            { SupportedCountries.Serbia, "RS" },
            { SupportedCountries.Russian_Federation, "RU" },
            { SupportedCountries.Rwanda, "RW" },
            { SupportedCountries.Saudi_Arabia, "SA" },
            { SupportedCountries.Solomon_Islands, "SB" },
            { SupportedCountries.Seychelles, "SC" },
            { SupportedCountries.Sudan, "SD" },
            { SupportedCountries.Sweden, "SE" },
            { SupportedCountries.Singapore, "SG" },
            { SupportedCountries.Saint_Helena, "SH" },
            { SupportedCountries.Slovenia, "SI" },
            { SupportedCountries.Svalbard_and_Jan_Mayen_Islands, "SJ" },
            { SupportedCountries.Slovakia, "SK" },
            { SupportedCountries.Sierra_Leone, "SL" },
            { SupportedCountries.San_Marino, "SM" },
            { SupportedCountries.Senegal, "SN" },
            { SupportedCountries.Somalia, "SO" },
            { SupportedCountries.Suriname, "SR" },
            { SupportedCountries.South_Sudan, "SS" },
            { SupportedCountries.Sao_Tome_and_Principe, "ST" },
            { SupportedCountries.El_Salvador, "SV" },
            { SupportedCountries.Sint_Maarten_Dutch, "SX" },
            { SupportedCountries.Syrian_Arab_Republic, "SY" },
            { SupportedCountries.Swaziland, "SZ" },
            { SupportedCountries.Turks_and_Caicos_Islands, "TC" },
            { SupportedCountries.Chad, "TD" },
            { SupportedCountries.French_Southern_Territories, "TF" },
            { SupportedCountries.Togo, "TG" },
            { SupportedCountries.Thailand, "TH" },
            { SupportedCountries.Tajikistan, "TJ" },
            { SupportedCountries.Tokelau, "TK" },
            { SupportedCountries.Timor_Leste, "TL" },
            { SupportedCountries.Turkmenistan, "TM" },
            { SupportedCountries.Tunisia, "TN" },
            { SupportedCountries.Tonga, "TO" },
            { SupportedCountries.Turkey, "TR" },
            { SupportedCountries.Trinidad_and_Tobago, "TT" },
            { SupportedCountries.Tuvalu, "TV" },
            { SupportedCountries.Taiwan, "TW" },
            { SupportedCountries.Tanzania, "TZ" },
            { SupportedCountries.Ukraine, "UA" },
            { SupportedCountries.Uganda, "UG" },
            { SupportedCountries.United_States_Minor_Outlying_Islands, "UM" },
            { SupportedCountries.United_States, "US" },
            { SupportedCountries.Uruguay, "UY" },
            { SupportedCountries.Uzbekistan, "UZ" },
            { SupportedCountries.Holy_See, "VA" },
            { SupportedCountries.Saint_Vincent_and_the_Grenadines, "VC" },
            { SupportedCountries.Venezuela, "VE" },
            { SupportedCountries.Virgin_Islands_British, "VG" },
            { SupportedCountries.Virgin_Islands_US, "VI" },
            { SupportedCountries.Vietnam, "VN" },
            { SupportedCountries.Vanuatu, "VU" },
            { SupportedCountries.Wallis_and_Futuna_Islands, "WF" },
            { SupportedCountries.Samoa, "WS" },
            { SupportedCountries.Kosovo, "XK" },
            { SupportedCountries.Unknown, "XX" },
            { SupportedCountries.Yemen, "YE" },
            { SupportedCountries.Mayotte, "YT" },
            { SupportedCountries.Yugoslavia, "YU" },
            { SupportedCountries.South_Africa, "ZA" },
            { SupportedCountries.Zambia, "ZM" },
            { SupportedCountries.Zimbabwe, "ZW" }
        };

        /// <summary>
        /// Dictionary of supported platforms
        /// </summary>
        public static Dictionary<PlatformType, string> PlatformDictionary = new Dictionary<PlatformType, string>()
        {
            { PlatformType.Unknown, "unknown" },
            { PlatformType.PC, "pc"},
            { PlatformType.Playstation, "ps" },
            { PlatformType.Xbox, "xbox" },
            { PlatformType.Android, "android" },
            { PlatformType.MacOS, "mac" },
            { PlatformType.IOS, "ios" },
            { PlatformType.Wildcard, "*" }
        };

        public static Dictionary<PlayerIDType, string> IDTypeDictionary = new Dictionary<PlayerIDType, string>()
        {
            { PlayerIDType.Apple, "apple" },
            { PlayerIDType.Epic, "epic" },
            { PlayerIDType.Google, "google" },
            { PlayerIDType.Microsoft, "microsoft" },
            { PlayerIDType.Nintendo, "nintendo" },
            { PlayerIDType.Sony, "sony" },
            { PlayerIDType.Steam, "steam" },
            { PlayerIDType.Twitch, "twitch" }
        };

        /// <summary>
        /// Dictionary of supported languages
        /// </summary>
        public static Dictionary<SupportedLanguages, string> LanguageDictionary = new Dictionary<SupportedLanguages, string>()
        {
            { SupportedLanguages.Arabic, "ara" },
            { SupportedLanguages.Chinese_Mandarin, "zho" },
            { SupportedLanguages.English, "eng" },
            { SupportedLanguages.French, "fra" },
            { SupportedLanguages.German, "deu" },
            { SupportedLanguages.Italian, "ita" },
            { SupportedLanguages.Japanese, "jpn" },
            { SupportedLanguages.Korean, "kor" },
            { SupportedLanguages.Polish, "pol" },
            { SupportedLanguages.Portuguese, "por" },
            { SupportedLanguages.Russian, "rus" },
            { SupportedLanguages.Spanish, "spa" },
            { SupportedLanguages.Thai, "tha" },
            { SupportedLanguages.Turkish, "tur" }
        };

        /// <summary>
        /// Dictionary of supported currencies
        /// </summary>
        public static Dictionary<SupportedCurrencies, string> CurrencyDictionary = new Dictionary<SupportedCurrencies, string>()
        {
            { SupportedCurrencies.Australian_Dollar, "AUD" },
            { SupportedCurrencies.Brazilian_Real, "BRL" },
            { SupportedCurrencies.Canadian_Dollar, "CAD" },
            { SupportedCurrencies.Chinese_Yuan, "CNY" },
            { SupportedCurrencies.Euro, "EUR" },
            { SupportedCurrencies.Hong_Kong_Dollar, "HKD" },
            { SupportedCurrencies.Indian_Rupee, "INR" },
            { SupportedCurrencies.Japanese_Yen, "JPY" },
            { SupportedCurrencies.Mexican_Peso, "MXN" },
            { SupportedCurrencies.New_Zealand_Dollar, "NZD" },
            { SupportedCurrencies.Norwegian_Krone, "NOK" },
            { SupportedCurrencies.Pound_Sterling, "GBP" },
            { SupportedCurrencies.Romanian_Leu, "RON" },
            { SupportedCurrencies.Russian_Ruble, "RUB" },
            { SupportedCurrencies.Singapore_Dollar, "SGD" },
            { SupportedCurrencies.South_African_Rand, "ZAR" },
            { SupportedCurrencies.South_Korean_Won, "KRW" },
            { SupportedCurrencies.Swedish_Krona, "SEK" },
            { SupportedCurrencies.Swiss_Franc, "CHF" },
            { SupportedCurrencies.Turkish_Lira, "TRY" },
            { SupportedCurrencies.United_States_Dollar, "USD" },
            { SupportedCurrencies.Unknown, "XXX" }
        };
    }
    public enum PlatformType
    {
        Wildcard,
        Android,
        MacOS,
        IOS,
        PC,
        Playstation,
        Switch,
        Unknown,
        Xbox
    }

    public enum PlayerIDType
    {
        Apple,
        Epic,
        Google,
        Microsoft,
        Nintendo,
        Sony,
        Steam,
        Twitch
    }

    public enum SupportedCountries
    {
        Unknown,
        Andorra,
        United_Arab_Emirates,
        Afghanistan,
        Antigua_and_Barbuda,
        Anguilla,
        Albania,
        Armenia,
        Netherlands_Antilles,
        Angola,
        Antarctica,
        Argentina,
        American_Somoa,
        Austria,
        Australia,
        Aruba,
        Aland_Islands,
        Azerbaijan,
        Bosnia_and_Herzegovina,
        Barbados,
        Bangladesh,
        Belgium,
        Burkina_Faso,
        Bulgaria,
        Bahrain,
        Burundi,
        Benin,
        Saint_Barthelemy,
        Bermuda,
        Brunei_Darussalam,
        Bolivia,
        Bonaire_Sint_Eustatius_and_Saba,
        Brazil,
        Bahamas,
        Bhutan,
        Bouvet_Island,
        Botswana,
        Belarus,
        Belize,
        Canada,
        Cocos_Keeling_Islands,
        Democratic_Republic_of_the_Congo,
        Central_African_Republic,
        Congo,
        Switzerland,
        Cote_dIvoire,
        Cook_Islands,
        Chile,
        Cameroon,
        China,
        Colombia,
        Costa_Rica,
        Cuba,
        Cape_Verde,
        Curacao,
        Christmas_Island,
        Cyprus,
        Czech_Republic,
        Germany,
        Djibouti,
        Denmark,
        Dominica,
        Dominican_Republic,
        Algeria,
        Ecuador,
        Estonia,
        Egypt,
        Western_Sahara,
        Eritrea,
        Spain,
        Ethiopia,
        Finland,
        Fiji,
        Falkland_Islands_Malvinas,
        Micronesia,
        Faroe_Islands,
        France,
        Gabon,
        United_Kingdom,
        Grenada,
        Georgia,
        French_Guiana,
        Guernsey,
        Ghana,
        Gibraltar,
        Greenland,
        Gambia,
        Guinea,
        Guadeloupe,
        Equatorial_Guinea,
        Greece,
        South_Georgia_and_the_South_Sandwich_Islands,
        Guatemala,
        Guam,
        Guinea_Bissau,
        Guyana,
        Hong_Kong,
        Heard_Island_and_McDonald_Islands,
        Honduras,
        Croatia,
        Haiti,
        Hungary,
        Indonesia,
        Ireland,
        Israel,
        Isle_of_Man,
        India,
        British_Indian_Ocean_Territory,
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
        Saint_Kitts_and_Nevis,
        Democratic_Peoples_Republic_of_Korea,
        Republic_of_Korea,
        Kuwait,
        Cayman_Islands,
        Kazakhstan,
        Lao_Peoples_Democratic_Republic,
        Lebanon,
        Saint_Lucia,
        Liechtenstein,
        Sri_Lanka,
        Liberia,
        Lesotho,
        Lithuania,
        Luxembourg,
        Latvia,
        Libyan_Arab_Jamahiriya,
        Morocco,
        Monaco,
        Moldova,
        Montenegro,
        Saint_Martin_French,
        Madagascar,
        Marshall_Islands,
        North_Macedonia,
        Mali,
        Myanmar,
        Mongolia,
        Macau,
        Northern_Mariana_Islands,
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
        New_Caledonia,
        Niger,
        Norfolk_Island,
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
        French_Polynesia,
        Papua_New_Guinea,
        Philippines,
        Pakistan,
        Poland,
        Saint_Pierre_and_Miquelon,
        Pitcairn,
        Puerto_Rico,
        Palestinian_Territory,
        Portugal,
        Palau,
        Paraguay,
        Qatar,
        Reunion,
        Romania,
        Serbia,
        Russian_Federation,
        Rwanda,
        Saudi_Arabia,
        Solomon_Islands,
        Seychelles,
        Sudan,
        Sweden,
        Singapore,
        Saint_Helena,
        Slovenia,
        Svalbard_and_Jan_Mayen_Islands,
        Slovakia,
        Sierra_Leone,
        San_Marino,
        Senegal,
        Somalia,
        Suriname,
        South_Sudan,
        Sao_Tome_and_Principe,
        El_Salvador,
        Sint_Maarten_Dutch,
        Syrian_Arab_Republic,
        Swaziland,
        Turks_and_Caicos_Islands,
        Chad,
        French_Southern_Territories,
        Togo,
        Thailand,
        Tajikistan,
        Tokelau,
        Timor_Leste,
        Turkmenistan,
        Tunisia,
        Tonga,
        Turkey,
        Trinidad_and_Tobago,
        Tuvalu,
        Taiwan,
        Tanzania,
        Ukraine,
        Uganda,
        United_States_Minor_Outlying_Islands,
        United_States,
        Uruguay,
        Uzbekistan,
        Holy_See,
        Saint_Vincent_and_the_Grenadines,
        Venezuela,
        Virgin_Islands_British,
        Virgin_Islands_US,
        Vietnam,
        Vanuatu,
        Wallis_and_Futuna_Islands,
        Samoa,
        Kosovo,
        Yemen,
        Mayotte,
        Yugoslavia,
        South_Africa,
        Zambia,
        Zimbabwe
    }

    public enum SupportedCurrencies
    {
        Australian_Dollar,
        Brazilian_Real,
        Canadian_Dollar,
        Chinese_Yuan,
        Euro,
        Hong_Kong_Dollar,
        Indian_Rupee,
        Japanese_Yen,
        Mexican_Peso,
        New_Zealand_Dollar,
        Norwegian_Krone,
        Pound_Sterling,
        Romanian_Leu,
        Russian_Ruble,
        Singapore_Dollar,
        South_African_Rand,
        South_Korean_Won,
        Swedish_Krona,
        Swiss_Franc,
        Turkish_Lira,
        United_States_Dollar,
        Unknown,
        In_Game
    }

    public enum CurrencyType
    {
        /// <summary>
        /// e.g. USD
        /// </summary>
        Real = 0,

        /// <summary>
        /// e.g. Gems
        /// </summary>
        Virtual = 1,

        /// <summary>
        /// e.g. ETH
        /// </summary>
        Crypto = 2
    }

    public enum SupportedLanguages
    {
        Arabic,
        Chinese_Mandarin,
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
    }
    public enum OpportunityAbortReasons
    {
        Cancel = 0,
        Other = 1
    }

    public enum Gender
    {
        /// <summary>
        /// Male
        /// </summary>
        m,

        /// <summary>
        /// Female
        /// </summary>
        f,

        /// <summary>
        /// Unknown/Non-Binary
        /// </summary>
        n
    }
}
