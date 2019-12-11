workspace "Moonlight"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}

IncludeDir = {}
IncludeDir["Glad"] = "Moonlight/vendor/Glad/include"
IncludeDir["glm"] = "Moonlight/vendor/glm"
IncludeDir["GLFW"] = "Moonlight/vendor/GLFW/include"
IncludeDir["imgui"] = "Moonlight/vendor/imgui/"

group "Dependencies"
	include "Moonlight/vendor/Glad/"
	include "Moonlight/vendor/GLFW/"
	include "Moonlight/vendor/imgui/"
group ""

project "Moonlight"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	location "%{prj.name}"

	targetdir ("$(SolutionDir)/$(Platform)/$(Configuration)")
	objdir ("$(SolutionDir)/$(Platform)/$(Configuration)/obj")

	pchheader "mlpch.h"
	pchsource "%{prj.name}/src/mlpch.cpp"

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
		"%{prj.location}/vendor/glm/glm/**.hpp",
		"%{prj.location}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.imgui}"
	}

	links 
	{ 
		"Glad",
		"GLFW",
		"imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ML_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "ML_DEBUG"
		runtime "Debug"
		symbols "off"

	filter "configurations:Release"
		defines "ML_RELEASE"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("$(SolutionDir)/$(Platform)/$(Configuration)")
	objdir ("$(SolutionDir)/$(Platform)/$(Configuration)/obj")

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
		"%{prj.location}/**.cpp",
		"%{prj.location}/**.h"
	}

	includedirs
	{
		"Moonlight/vendor/spdlog/include",
		"Moonlight/src",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Moonlight"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "ML_DEBUG"
		runtime "Debug"
		symbols "off"

	filter "configurations:Release"
		defines "ML_RELEASE"
		runtime "Release"
		optimize "on"