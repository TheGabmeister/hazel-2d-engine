cmake_minimum_required(VERSION 3.16)

project(hazel VERSION 1.0)
project(sandbox VERSION 1.0) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_GENERATOR_PLATFORM x64)

# Specify build configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "Available build types" FORCE)

# Define linker flags for custom 'Dist' configuration to avoid CMake missing variable errors
set(CMAKE_EXE_LINKER_FLAGS_DIST    "" CACHE STRING "Linker flags for Dist config" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_DIST "" CACHE STRING "Linker flags for Dist config" FORCE)
set(CMAKE_MODULE_LINKER_FLAGS_DIST "" CACHE STRING "Linker flags for Dist config" FORCE)


add_subdirectory("Hazel/vendor/spdlog")
  
file(GLOB_RECURSE MR_SANDBOX_SOURCES  
   "${CMAKE_SOURCE_DIR}/sandbox/src/*.cpp"
   "${CMAKE_SOURCE_DIR}/sandbox/src/*.h"  
)
 
file(GLOB_RECURSE HZ_HAZEL_SOURCES
   "${CMAKE_SOURCE_DIR}/Hazel/src/*.cpp"
   "${CMAKE_SOURCE_DIR}/Hazel/src/*.h"
)
 
add_executable(sandbox ${MR_SANDBOX_SOURCES})
add_library(hazel SHARED ${HZ_HAZEL_SOURCES})

target_include_directories(hazel PRIVATE "${CMAKE_SOURCE_DIR}/Hazel/vendor/spdlog/include")
target_include_directories(sandbox PRIVATE "${CMAKE_SOURCE_DIR}/Hazel/vendor/spdlog/include")
target_include_directories(sandbox PRIVATE "${CMAKE_SOURCE_DIR}/Hazel/src")


# Set preprocessor definitions
if(WIN32)
   target_compile_definitions(hazel PRIVATE  
      HZ_PLATFORM_WINDOWS 
      HZ_BUILD_DLL
   )
   target_compile_definitions(sandbox PRIVATE  
      HZ_PLATFORM_WINDOWS 
   )

   # This is for fixing the spdlog/fmt error C2338: static_assert failed: 
   # 'Unicode support requires compiling with /utf-8
   target_compile_options(hazel PRIVATE /utf-8)
   target_compile_options(sandbox PRIVATE /utf-8)
endif()

target_link_libraries(hazel PRIVATE 
    spdlog::spdlog_header_only
)

target_link_libraries(sandbox PRIVATE 
    hazel
)