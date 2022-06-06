workspace "CodeJam"
	configurations { "Debugx64", "Releasex64", "Debugx86", "Releasex86" }

project "Jamcoins"
	location "Jamcoins"
	kind "ConsoleApp"
	language "C++"

	files { "Jamcoins/src/Jamcoins.cpp" }

	filter {"configurations:Debugx64"}
		targetdir "bin/Debug/x64"
		objdir "bin-obj/Debug/x64"

	filter {"configurations:Debugx86"}
		targetdir "bin/Debug/x86"
		objdir "bin-obj/Debug/x86"

	filter {"configurations:Releasex64"}
		optimize "On"
		targetdir "bin/Release/x64"
		objdir "bin-obj/Release/x64"

	filter {"configurations:Releasex86"}
		optimize "On"
		targetdir "bin/Release/x86"
		objdir "bin-obj/Release/x86"