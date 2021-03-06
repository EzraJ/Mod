function os.winSdkVersion()
    local reg_arch = iif( os.is64bit(), "\\Wow6432Node\\", "\\" )
    local sdk_version = os.getWindowsRegistry( "HKLM:SOFTWARE" .. reg_arch .."Microsoft\\Microsoft SDKs\\Windows\\v10.0\\ProductVersion" )
    if sdk_version ~= nil then return sdk_version end
end

workspace "Mod"
    configurations {"Debug", "Release"}
    filter {"system:windows", "action:vs"}
    systemversion(os.winSdkVersion() .. ".0")
project "Mod"
    kind "ConsoleApp"
    language "C++"
    files {"src/**.cpp", "src/**.h", "src/**.hpp", "src/**.c"}
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"src/", "src/ModDLL/include"}

    filter "configurations:Debug"
        libdirs {"src/ModDLL/lib/MDebug"}
		links   {"ModDLL.lib"}
        defines {"DEBUG"}
        symbols "On"
    filter "configurations:Release"
		libdirs {"src/ModDLL/lib/MRelease"}
		links {"ModDLL.lib"}
        defines {"NDEBUG"}
        optimize "On"

        
    