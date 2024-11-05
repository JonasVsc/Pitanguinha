#pragma once

#include<iostream>

#ifdef PITANGUINHA_DEBUG
	#define PTG_DEBUG(...) std::cout << "[Pitanguinha] " << __VA_ARGS__ << '\n'
#else
	#define PTG_DEBUG(...)
#endif



