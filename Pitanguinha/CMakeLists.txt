# CMakeList.txt : CMake project for Pitanguinha, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library(Pitanguinha SHARED 
    
    "src/Pitanguinha/Log.h"
    
    "src/Pitanguinha/Core.h" 

     
     

 "src/Pitanguinha.h")

target_precompile_headers(Pitanguinha PRIVATE "src/pch.h")

if(WIN32)
    target_compile_definitions(Pitanguinha PRIVATE 
        PTG_PLATFORM_WINDOWS 
        PTG_BUILD_DLL)
endif()