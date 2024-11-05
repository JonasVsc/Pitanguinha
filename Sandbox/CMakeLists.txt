# CMakeList.txt : CMake project for Pitanguinha_, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable(Sandbox "src/SandboxApp.cpp") 

target_link_libraries(Sandbox PRIVATE Pitanguinha)
target_include_directories(Sandbox PRIVATE "../Pitanguinha/src")


if(WIN32)
    target_compile_definitions(Sandbox PRIVATE PTG_PLATFORM_WINDOWS)
endif()

# Copy Pitanhguinha.dll to Sandbox directory
add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:Pitanguinha>"
        $<TARGET_FILE_DIR:Sandbox>)