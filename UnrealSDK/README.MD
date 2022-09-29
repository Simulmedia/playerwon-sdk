# Unreal SDK


NOTE:  Unreal Engine 5 has a bug currently where the Media Player will not work correctly when using Direct X12.

### Packaging Unreal SDK:
- Make sure Unreal Engine 4.27 is installed with Visual Studio
- Open cmdline
- Enter cd "Path to Unreal Engine's Build/BatchFiles folder"
- Enter `RunUAT.bat BuildPlugin -plugin="Path to plugin \PlayerWONSDK.uplugin" -package="Destination folder" -VS2019`

### Packaging Unreal SDK for Unreal Engine 5:
- Make sure UE5 is installed with Visual Studio
- Open cmdline
- Enter `cd "Path to Unreal Engine's Build/BatchFiles folder"`
- Enter `RunUAT.bat BuildPlugin -plugin="Path to plugin \PlayerWONSDK.uplugin" -package="Destination folder"`
