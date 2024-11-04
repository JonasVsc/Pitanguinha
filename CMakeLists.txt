cmake_minimum_required(VERSION 3.10)
project(Pitanguinha)

# ================= Pitanguinha ====================== #

add_library(Pitanguinha SHARED 
    "Pitanguinha/src/Log.h"
    "Pitanguinha/src/Teste.cpp"
    "Pitanguinha/src/Teste.h"
)

# ================== Sandbox ========================= #

add_executable(Sandbox "Sandbox/src/SandboxApp.cpp") 

target_link_libraries(Sandbox PRIVATE Pitanguinha)
target_include_directories(Sandbox PRIVATE Pitanguinha/src)


# Configurações para Modo Debug

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_CONFIGURATION_TYPES MATCHES Debug)
    target_compile_definitions(Sandbox PRIVATE PITANGUINHA_DEBUG)
    target_compile_definitions(Pitanguinha PRIVATE PITANGUINHA_DEBUG)
endif()