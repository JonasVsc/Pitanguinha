cmake_minimum_required(VERSION 3.10)
project(Pitanguinha)

# ================= Pitanguinha ====================== #

add_library(Pitanguinha SHARED 
    "Pitanguinha/src/Teste.cpp"
    "Pitanguinha/src/Teste.h")


# ================== Sandbox ========================= #

add_executable(Sandbox "Sandbox/src/SandboxApp.cpp") 

target_link_libraries(Sandbox PRIVATE Pitanguinha)
target_include_directories(Sandbox PRIVATE Pitanguinha/src)


