workspace "TouhouClone"
    configurations { "Debug", "Release" }
    platforms { "Linux", "Win32", "Win64" }
    location "."

    -- Architecture
    filter "platforms:Win32"
        architecture "x86"
        linkoptions {"-fno-pie"}
    filter "platforms:Win64"
        architecture "x86_64"
    
    -- Toolset (Visual Studio or MinGW)
    filter "action:vs*"
        includedirs "./deps/VS/*/include"
        libdirs "./deps/VS/*/lib/%{cfg.architecture}"
        local dllFiles = os.matchfiles("./deps/VS/DLLS/x86_64/*.dll")
        for key, dllPath in pairs(dllFiles) do
            postbuildcommands({ "{COPYFILE} ".."%{wks.location}/"..dllFiles[key].." ./%{cfg.targetdir}" })
        end
    filter { "action:gmake*", "platforms:Win32" }
        gccprefix "i686-w64-mingw32-"
        includedirs { "./deps/MinGW/*/i686-w64-mingw32/include", "./deps/MinGW/*/i686-w64-mingw32/include/*" }
        libdirs { "./deps/MinGW/*/i686-w64-mingw32/lib" }
        links "mingw32"
        local dllFiles = os.matchfiles("./deps/MinGW/DLLS/x86/*.dll")
        for key, dllPath in pairs(dllFiles) do
            postbuildcommands({ "{COPYFILE} ".."%{wks.location}/"..dllFiles[key].." ./%{cfg.targetdir}" })
        end

    filter { "action:gmake*", "platforms:Win64" }
        gccprefix "x86_64-w64-mingw32-"
        includedirs { "./deps/MinGW/*/x86_64-w64-mingw32/include", "./deps/MinGW/*/x86_64-w64-mingw32/include/*" }
        libdirs { "./deps/MinGW/*/x86_64-w64-mingw32/lib" }
        links "mingw32"
        local dllFiles = os.matchfiles("./deps/MinGW/DLLS/x86_64/*.dll")
        for key, dllPath in pairs(dllFiles) do
            postbuildcommands({ "{COPYFILE} ".."%{wks.location}/"..dllFiles[key].." ./%{cfg.targetdir}" })
        end

    filter "platforms:Win*"
        links "SDL2main"

    project "Game"
    	location "%{prj.name}"
        kind "WindowedApp"
        language "C++"
        targetname "%{wks.name}"
        targetdir "build/%{cfg.buildcfg}/%{cfg.platform}/bin"
        objdir "build/%{cfg.buildcfg}/%{cfg.platform}/obj"

        postbuildcommands({ "{COPYDIR} %{wks.location}/assets %{cfg.targetdir}" })
        postbuildmessage "Copying Assets and DLLs..."

        links { "SDL2", "SDL2_image", "SDL2_ttf", "SDL2_mixer" }

        files { "**.h", "**.cpp" }
        includedirs { "./%{prj.location}/**" }

        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"

        filter "configurations:Release"
            defines { "NDEBUG" }
            optimize "On"

