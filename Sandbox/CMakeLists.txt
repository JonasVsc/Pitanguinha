add_executable(Sandbox "src/SandboxApp.cpp") 

target_link_libraries(Sandbox PRIVATE Pitanguinha)
target_link_libraries(Sandbox PRIVATE glfw glad)
target_include_directories(Sandbox PRIVATE "../Pitanguinha/src")

add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Pitanguinha>       # Path to Pitanguinha.dll
        $<TARGET_FILE_DIR:Sandbox>       # Output directory of Sandbox.exe
    COMMENT "Copying Pitanguinha.dll to Sandbox output directory"
)

if(WIN32)
    target_compile_definitions(Sandbox PRIVATE PTG_PLATFORM_WINDOWS)
endif()

