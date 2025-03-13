REM Make sure to change the address for the variables.  The first string in UnrealAutoBuilder points to the specific Unreal version's AutoBuilder.bat.
REM The second string in the UnrealAutoBuilder is where the plugin is located
REM PackagedPluginDestination is the destination you would like to have for the plugin once it is built and packaged
REM NOTE: THESE WILL NEED TO CHANGE PER VERSION OF UNREAL

set UnrealAutoBuilder="D:\Epic Games\UE_5.5\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin="D:\GitHub\PlayerWONSDK\Plugins\PlayerWONSDKPlugin\PlayerWONSDKPlugin.uplugin"
set PackagedPluginDestination="C:\Users\mgagn\OneDrive\Desktop\PlayerWONBuilder\PackagedBuilds\PlayerWONSDK 5.5"


%UnrealAutoBuilder% -NoHostPlatform -Package=%PackagedPluginDestination%