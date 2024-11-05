# CMakeList.txt : CMake project for Pitanguinha, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library(Pitanguinha SHARED 
    "src/Pitanguinha/Log.h"
    
    "src/Pitanguinha/Core.h" 

    "src/Pitanguinha/Application.h"
    "src/Pitanguinha/Application.cpp"
     
    "src/Pitanguinha/EntryPoint.h"

    "src/Pitanguinha.h"
    "src/pch.h"
)

target_precompile_headers(Pitanguinha PRIVATE "src/pch.h")

target_include_directories(Pitanguinha PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
if(WIN32)
    target_compile_definitions(Pitanguinha PRIVATE 
        PTG_PLATFORM_WINDOWS 
        PTG_BUILD_DLL)
endif()

