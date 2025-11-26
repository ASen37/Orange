workspace "Orange"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "OrangeEngine"
    location "OrangeEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "oepch.h"
    pchsource "OrangeEngine/src/oepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ORANGE_PLATFORM_WINDOWS",
            "ORANGE_BUILD_DLL",
            "FMT_HEADER_ONLY"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "ORANGE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ORANGE_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "ORANGE_DIST"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "OrangeEngine/vendor/spdlog/include",
        "OrangeEngine/src"
    }

    links
    {
        "OrangeEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ORANGE_PLATFORM_WINDOWS",
            "FMT_HEADER_ONLY"
        }

    filter "configurations:Debug"
        defines "ORANGE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ORANGE_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "ORANGE_DIST"
        optimize "On"
