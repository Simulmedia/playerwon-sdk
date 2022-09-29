using UnityEngine;
using UnityEditor;

public static class Builder
{
    [MenuItem("Build/PackageSDK")]
    public static void BuildSDK()
    {
        string sdkPath = "Assets/PlayerWon-SDK";
        
        //This will export a file named PlayerWON-SDK.unitypackage into the project folder
        //TODO:  If there needs to be a specific folder we need to export the package to, we need to change this string
        //       MenuItems cannot take parameters such as strings.  This class can be edited via notepad++ or any other text editor without opening Unity.
        string exportPath = "PlayerWON-SDK.unitypackage";

        AssetDatabase.ExportPackage(sdkPath, exportPath, ExportPackageOptions.Recurse | ExportPackageOptions.IncludeDependencies);
    }
}