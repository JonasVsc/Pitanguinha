#pragma once

#ifdef PTG_PLATFORM_WINDOWS
	#ifdef PTG_BUILD_DLL
		#define PTG_API _declspec(dllexport)
	#else	
		#define PTG_API _declspec(dllimport)
	#endif
#else
	#error Pitanguinha only support windows for now
#endif