#pragma once

#ifdef MR_PLATFORM_WINDOWS
	#pragma message("MR_PLATFORM_WINDOWS is defined")
	#ifdef MR_BUILD_DLL
		#pragma message("MR_BUILD_DLL is defined")
		#define	MAROON_API __declspec(dllexport)
	#else
		#pragma message("MR_BUILD_DLL is NOT defined")
		#define	MAROON_API __declspec(dllimport)
	#endif
#else
	#error Maroon only supports Windows!
#endif