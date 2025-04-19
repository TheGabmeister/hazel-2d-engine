#pragma once

#ifdef MR_PLATFORM_WINDOWS
	#ifdef MR_BUILD_DLL
		#define	MAROON_API __declspec(dllexport)
	#else 
		#define	MAROON_API __declspec(dllimport)
	#endif
#else
	#error Maroon only supports Windows!
#endif