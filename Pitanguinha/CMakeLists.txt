add_library(Pitanguinha SHARED 
    "src/Pitanguinha/Log.h"
    
    "src/Pitanguinha/Core.h" 

    "src/Pitanguinha/Application.h"
    "src/Pitanguinha/Application.cpp"
     
    "src/Pitanguinha/EntryPoint.h"

    "src/Pitanguinha/Window.h"
    "src/Pitanguinha/Window.cpp"

    "src/Pitanguinha.h"
    "src/pch.h"
)

target_precompile_headers(Pitanguinha PRIVATE "src/pch.h")
target_include_directories(Pitanguinha PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(3rdparty/glfw)

# glfw
target_include_directories(Pitanguinha PRIVATE 3rdparty/glfw/include)
target_link_libraries(Pitanguinha PRIVATE glfw)

if(WIN32)
    target_compile_definitions(Pitanguinha PRIVATE 
        PTG_PLATFORM_WINDOWS 
        PTG_BUILD_DLL)
endif()


