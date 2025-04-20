cmake_minimum_required(VERSION 3.16)

# Project name and version
project(maroon VERSION 1.0)
project(sandbox VERSION 1.0) 

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Force x64 architecture
set(CMAKE_GENERATOR_PLATFORM x64)

# Specify build configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "Available build types" FORCE)

add_subdirectory("maroon/thirdparty/spdlog")
 
# Add source files  
file(GLOB_RECURSE MR_SANDBOX_SOURCES  
   "${CMAKE_SOURCE_DIR}/sandbox/src/*.cpp"
   "${CMAKE_SOURCE_DIR}/sandbox/src/*.h"  
)
 
# Define source files for the maroon library
file(GLOB_RECURSE MR_MAROON_SOURCES
   "${CMAKE_SOURCE_DIR}/maroon/src/*.cpp"
   "${CMAKE_SOURCE_DIR}/maroon/src/*.h"
)

add_executable(sandbox ${MR_SANDBOX_SOURCES})
add_library(maroon SHARED ${MR_MAROON_SOURCES})

# Include directories
target_include_directories(maroon PRIVATE "${CMAKE_SOURCE_DIR}/maroon/thirdparty/spdlog/include")
target_include_directories(sandbox PRIVATE "${CMAKE_SOURCE_DIR}/maroon/thirdparty/spdlog/include")
target_include_directories(sandbox PRIVATE "${CMAKE_SOURCE_DIR}/maroon/src")


# Set preprocessor definitions
if(WIN32)
   target_compile_definitions(maroon PRIVATE  
      MR_PLATFORM_WINDOWS 
      MR_BUILD_DLL
   )
   target_compile_definitions(sandbox PRIVATE  
      MR_PLATFORM_WINDOWS 
   )

   # This is for fixing the spdlog/fmt error C2338: static_assert failed: 
   # 'Unicode support requires compiling with /utf-8
   target_compile_options(maroon PRIVATE /utf-8)
   target_compile_options(sandbox PRIVATE /utf-8)
endif()

target_link_libraries(maroon PRIVATE 
    spdlog::spdlog_header_only
)

target_link_libraries(sandbox PRIVATE 
    maroon
)