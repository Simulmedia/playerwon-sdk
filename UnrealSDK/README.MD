# Unreal SDK

NOTE:  Unreal Engine 5 has a bug that prevents the Media Player from working correctly, when using DirectX 12.

### Packaging Unreal SDK:
- Ensure Unreal Engine 4.27 is installed with Visual Studio
- Open the command line
- Enter `cd "<Path to Unreal Engine's Build/BatchFiles folder>"`
- Enter `RunUAT.bat BuildPlugin -plugin="<Path to plugin \PlayerWONSDK.uplugin>" -package="<Destination folder>" -VS2019`

### Packaging Unreal SDK for Unreal Engine 5:
- Ensure UE5 is installed with Visual Studio
- Open the command line
- Enter `cd "<Path to Unreal Engine's Build/BatchFiles folder>"`
- Enter `RunUAT.bat BuildPlugin -plugin="<Path to plugin \PlayerWONSDK.uplugin>" -package="<Destination folder>"`
