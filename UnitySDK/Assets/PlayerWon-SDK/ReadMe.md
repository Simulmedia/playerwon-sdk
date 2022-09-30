# PlayerWON-SDK

# Installation Instructions:
    
### From Unity Package:
        
1. Open the Unity Editor
2. Click Assets->Import Package->Custom Package
3. Browse to the PlayerWON-SDK.unitypackage and select it
4. Make sure everything in the PlayerWON-SDK folder is selected
5. Click import

### From Unity Asset Store:

1. Open the Unity Editor
2. Clicked Window->Package Manager
3. Make sure the selection is set to "My Assets"
4. Find the PlayerWON-SDK and select it
5. Click Download
6. Click Import


## Integration Instructions:

#### The PlayerWON-SDK provides an example scene with events and methods set up for reference.

1. Make sure the object you wish to display ads on is using the PlayerWONRenderTexture
2. Drag the PlayerWON.prefab into a scene
3. Create an empty GameObject with a script to "drive" the PlayerWON Bridge
4. Make sure to use the PlayerWON namespace in the new script
5. Access the Bridge by using Bridge.Instance

### Important Methods:

Init() - This provides initial telemetry data to PlayerWON if you have allowed sending of such data in the PlayerWON.Bridge inspector

CallSession() - This should be called at least once per play session

SetAuthorization() - This attempts to authorize the client to be able to retrieve ads

SetClientDetails() - This sets the internal reference to the client details

RetrieveOpportunityFromAPI() - This requests an opportunity (ad) from PlayerWON

PlayOpportunity() - This plays the opportunity if an opportunity has been retrieved

StopOpportunity() - This stops the playback of the opportunity if it is playing

###Events:

AuthorizationSuccessful - Invoked when the client has successfully be authorized

OpportunityEvent - Invoked when an opportunity has been successfully retrieved

VideoPrepared - Invoked when the VideoPlayer the Bridge uses is prepared with the ad and ready to play

StartEvent - Invoked when the ad has started to play

ProgressEvent - Invoked at the 25%, 50%, and 75% marks of playback while an ad is playing

CompleteEvent - Invoked when the ad has completed the playback

AbortEvent - Invoked when the ad has been aborted



