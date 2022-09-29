# PlayerWON Unity SDK Documentation


## PlayerWON.ClientDetails


### Description

Class used to store the client details which are generated via the developer and passed into the API call to retrieve an opportunity.  


### Declaration


```
public ClientDetails(SupportedCountries _country, string _idfa, PlatformType _plat, SupportedLanguages _lang, string _ip = null, int _w = 0, int _h = 0, string _pid = null, PlayerIDType _pidType = PlayerIDType.Unknown, string _device = null, int _coppa = 0, int _underage = 0, int _age = 0, string _slot_id = null, int _ls = 0, Currency _lsv = null, CurrencyArray _rv = null, int _gs = 0
)
```



### Parameters


<table>
  <tr>
   <td>SupportedCountries
   </td>
   <td>_country
   </td>
   <td>The player/client’s country
   </td>
  </tr>
  <tr>
   <td>string
   </td>
   <td>_idfa
   </td>
   <td>Unique Identifier of the Player/Client (Not Gamertag)
   </td>
  </tr>
  <tr>
   <td>PlatformType
   </td>
   <td>_plat
   </td>
   <td>The platform the player/client is on
   </td>
  </tr>
  <tr>
   <td>SupportedLanguages
   </td>
   <td>_lang
   </td>
   <td>The language the player/client is using
   </td>
  </tr>
  <tr>
   <td>string
   </td>
   <td>_ip
   </td>
   <td>Client/Player’s IP address
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_w
   </td>
   <td>Width of the screen in pixels
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_h
   </td>
   <td>Height of the screen in pixels
   </td>
  </tr>
  <tr>
   <td>string
   </td>
   <td>_pid
   </td>
   <td>The Gamertag of the player/client
   </td>
  </tr>
  <tr>
   <td>PlayerIDType
   </td>
   <td>_pid_type
   </td>
   <td>The type of gamertag (e.g. Microsoft, Steam, Epic)
   </td>
  </tr>
  <tr>
   <td>string
   </td>
   <td>_device
   </td>
   <td>The player/client’s device name
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_coppa
   </td>
   <td>0 means the player is 13 and above in age, 1 means the player is under the age of 13
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_underage
   </td>
   <td>0 means the player is not underage, 1 means the player is underage
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_age
   </td>
   <td>The player’s age in years
   </td>
  </tr>
  <tr>
   <td>string
   </td>
   <td>_slot_id
   </td>
   <td>Game specific value provided by PlayerWON
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_ls
   </td>
   <td>Lifetime spending. 1 means the player/client has made in-game purchases with real currency
   </td>
  </tr>
  <tr>
   <td>Currency
   </td>
   <td>_lsv
   </td>
   <td>Lifetime spending value. The currency value amount the player/client has spent in-game
   </td>
  </tr>
  <tr>
   <td>CurrencyArray
   </td>
   <td>_rv
   </td>
   <td>An array of in-game rewards the player will receive for watching an ad
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_gs
   </td>
   <td>0 means the calls are not made on a game server, 1 means the calls are made on a game server
   </td>
  </tr>
</table>



## PlayerWON.SupportedCountries


### Description

Enumeration used as a key internally that allows developers to now have to worry about country codes, abbreviations, or specific formatting for API calls.


### Declaration


```
public enum SupportedCountries
```



## PlayerWON.PlatformType


### Description

Enumeration is used as a key internally that allows developers to specify what platform the client is using without having to worry about specific formatting for API calls.


### Declaration


```
public enum PlatformType
```



## PlayerWON.SupportedLanguages


### Description

Enumeration used as a key internally that allows developers to specify what language the client is using without having to worry about specific formatting for API calls.


### Declaration


```
public enum SupportedLanguages
```



## PlayerWON.Gender


### Description

Enumeration used to determine the player/client’s gender


### Declaration


```
public enum Gender
```



## PlayerWON.CurrencyType


### Description

Enumeration used to determine the type of currency


### Declaration


```
public enum CurrencyType
```



## PlayerWON.SupportedCurrencies


### Description

Enumeration used as a key internally that allows developers to safely specify what the name of the currency being used is.


### Declaration


```
public enum SupportedCurrencies
```



## PlayerWON.PlayerIDType


### Description

Enumeration used as a key internally to allow developers to safely specify what kind of ID the player is using.


### Declaration


```
public enum PlayerIDType
```



## PlayerWON.OpportunityAbortReasons


### Description

Enumeration of reasons for aborting/canceling an opportunity playback.


### Declaration


```
public enum OpportunityAbortReasons
```



## PlayerWON.Opportunity


### Description

Class that holds the data retrieved from the API in the /opportunity call which includes the creative URL and receipt.


### Declaration


```
public class Opportunity
```



### Properties


<table>
  <tr>
   <td>public
   </td>
   <td>CreativeURL
   </td>
   <td>URL to the creative that will be displayed
   </td>
  </tr>
  <tr>
   <td>public
   </td>
   <td>Length
   </td>
   <td>Length of the creative (in seconds)
   </td>
  </tr>
  <tr>
   <td>public
   </td>
   <td>Receipt
   </td>
   <td>The receipt for the creative
   </td>
  </tr>
</table>



## PlayerWON.Currency


### Description

A class used to describe currency


### Declaration


```
public Currency(SupportedCurrencies currency, int value, int digits, CurrencyType type, string currencyName = null)
```



### Parameters


<table>
  <tr>
   <td>SupportedCurrencies
   </td>
   <td>currency
   </td>
   <td>The name of the currency
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>value
   </td>
   <td>The integer value without decimals of the currency. E.g. $100.00 would be 10000.
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>digits
   </td>
   <td>The amount of digits to the left the decimal should be placed. E.g. 2 would make 10000 into 100.00
   </td>
  </tr>
  <tr>
   <td>CurrencyType
   </td>
   <td>type
   </td>
   <td>The type of currency
   </td>
  </tr>
  <tr>
   <td>(<strong>Optional)</strong>string
   </td>
   <td>currencyName
   </td>
   <td>An optional string that will be used if currency is set to InGame.
   </td>
  </tr>
</table>



## PlayerWON.CurrencyArray


### Description

A class used to hold a list of currencies.


### Properties


<table>
  <tr>
   <td>List&lt;Currency>
   </td>
   <td>Currencies
   </td>
   <td>The list of Currency the CurrencyArray holds
   </td>
  </tr>
</table>



### Declaration


```
public CurrencyArray(List<Currency> cur)
```



```
public CurrencyArray()
```



## PlayerWON.SessionDetails


### Description

A class used to hold and organize details about the player/client’s session


### Declaration


```
public SessionDetails(SupportedCountries _country, PlatformType _plat, SupportedLanguages _lang, string _pid = null, PlayerIDType _pid_type = PlayerIDType.Unknown, string _device = null, int _coppa = 0, int _underage = 0, int _age = 0, int _min_age = 0, int _max_age = 0, Gender _gg = Gender.n, int _ls = 0, Currency _lsv = null, string _psd = null, int _gs = 0)
```



### Parameters


<table>
  <tr>
   <td>SupportedCountries
   </td>
   <td>_country
   </td>
   <td>The player/client’s country
   </td>
  </tr>
  <tr>
   <td>PlatformType
   </td>
   <td>_plat
   </td>
   <td>The platform he player/client is playing on
   </td>
  </tr>
  <tr>
   <td>SupportedLanguages
   </td>
   <td>_lang
   </td>
   <td>The language the player/client is using
   </td>
  </tr>
  <tr>
   <td>string
   </td>
   <td>_pid
   </td>
   <td>The Gamertag of the player/client
   </td>
  </tr>
  <tr>
   <td>PlayerIDType
   </td>
   <td>_pid_type
   </td>
   <td>The type of Gamertag the player/client is using
   </td>
  </tr>
  <tr>
   <td>string
   </td>
   <td>_device
   </td>
   <td>The device the player/client is using
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_coppa
   </td>
   <td>0 indicates the player is 13 and above, 1 indicates the player is under the age of 13
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_underage
   </td>
   <td>0 indicates the player is underage
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_age
   </td>
   <td>The player’s age in years
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_min_age
   </td>
   <td>The minimum age the player can be
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_max_age
   </td>
   <td>The maximum age the player can be
   </td>
  </tr>
  <tr>
   <td>Gender
   </td>
   <td>_gg
   </td>
   <td>The player/client’s gender
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_ls
   </td>
   <td>Lifetime Spending.  1 indicates the player has spent real money in-game in their lifetime.  0 indicates they have not.
   </td>
  </tr>
  <tr>
   <td>Currency
   </td>
   <td>_lsv
   </td>
   <td>Lifetime Spending Value.  The value the player/client has spent in-game
   </td>
  </tr>
  <tr>
   <td>string
   </td>
   <td>_psd
   </td>
   <td>The date the player played the game, written as “yyyy-mm-dd”
   </td>
  </tr>
  <tr>
   <td>int
   </td>
   <td>_gs
   </td>
   <td>1 indicates the calls are being made from a game server, 0 indicates they are not being made from a game server
   </td>
  </tr>
</table>



## PlayerWON.Bridge


### Description

A monobehaviour that acts as the main driver for the PlayerWON SDK.  All API calls, functionality, and error handling are handled by the Bridge.  


### Declaration


```
public class Bridge : MonoBehaviour
```



### Properties


<table>
  <tr>
   <td>PlayerWON.Bridge
   </td>
   <td>Instance
   </td>
   <td>Gets the singleton instance of the PlayerWON.Bridge
   </td>
  </tr>
  <tr>
   <td>bool
   </td>
   <td>dontDestroyOnLoad
   </td>
   <td>If set to true, the Bridge will exist between scenes until it is manually destroyed or the game instance has stopped running.  <strong>Only editable via inspector.</strong>
   </td>
  </tr>
  <tr>
   <td>bool
   </td>
   <td>sendPlayerWONTelemetry
   </td>
   <td>If set to true, the Bridge will send error reports, initialization reports, and general data reports to PlayerWON.  <strong>Only editable via inspector.</strong>
   </td>
  </tr>
  <tr>
   <td>RenderTexture
   </td>
   <td>renderTexture
   </td>
   <td>The render texture the VideoPlayer will use to display the ads.  <strong>Only editable via inspector.</strong>
   </td>
  </tr>
</table>



## Inspector Driven Events


### Description

These are events that are only accessible via the inspector on the Bridge


<table>
  <tr>
   <td>AuthorizationToken
   </td>
   <td>AuthorizationSuccessful
   </td>
   <td>Event that is invoked when authorization from the API has been achieved
   </td>
  </tr>
  <tr>
   <td>Opportunity
   </td>
   <td>OpportunityEvent
   </td>
   <td>Event that is invoked when an Opportunity has been successfully retrieved from the API
   </td>
  </tr>
  <tr>
   <td>AuthorizationToken,
<p>
Opportunity
   </td>
   <td>StartEvent
   </td>
   <td>Event that is invoked when the ad has started playing
   </td>
  </tr>
  <tr>
   <td>AuthorizationToken,
<p>
Opportunity
   </td>
   <td>ProgressEvent
   </td>
   <td>Event that is invoked when the ad has reached the 25%, 50%, and 75% marks of the it’s playback.
   </td>
  </tr>
  <tr>
   <td>AuthorizationToken,
<p>
Opportunity
   </td>
   <td>CompleteEvent
   </td>
   <td>Event that is invoked when the ad has completed it’s playback
   </td>
  </tr>
  <tr>
   <td>AuthorizationToken,
<p>
Opportunity,
<p>
String,
<p>
int
   </td>
   <td>AbortEvent
   </td>
   <td>Event that is invoked when the ad has been aborted
   </td>
  </tr>
  <tr>
   <td>void
   </td>
   <td>VideoPrepared
   </td>
   <td>Event that is invoked when the ad has been prepared in the VideoPlayer
   </td>
  </tr>
  <tr>
   <td>string
   </td>
   <td>Error
   </td>
   <td>Event that is invoked when an error has occurred within the SDK
   </td>
  </tr>
</table>



### Methods

Plays the ad


```
public void PlayOpportunity()
```


Stops the ad.  0 = Cancel, 1 = Other


```
public void StopOpportunity(int reason)
```


Method that provides PlayerWON with initial telemetry data


```
public void Init(string idfa, string unity_ver, string gametitle_id)
```


Makes the /session API call.  This should be called at least once per play session.


```
public void CallSession(SessionDetails details, AuthorizationToken token = null)
```


Uses the serverURL to authorize the client to be able to view ads (authorization details must be done on the server)


```
public void AuthorizeClient(string serverURL)
```


Sends a request to the API that retrieves an ad.


```
public void RetrieveOpportunityFromAPI(ClientDetails clientDetails)
```


Sets the internal reference for the ClientDetails.


```
public void SetClientDetails(ClientDetails details)
```




Gets the percentage of time left in the ad floored to an integer


```
public float TimeLeftInOpportunityFloored()
```


Gets the percentage of time left in the ad as a raw float (Not formatted)


```
public float TimeLeftInOpportunityRaw()
```


**PlayerWon.Telemetry**

Description

A class designed to collect PlayerWON errors and other telemetry data, powered by the sendTelemetryData boolean in the inspector of the Bridge.

**Methods**

A method that is used to invoke the error Unity event with a given error message.  Developers can catch the error message by subscribing to the error event.


```
public void InvokeError(string errorMessage)
```
