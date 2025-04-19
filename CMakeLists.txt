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
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Set preprocessor definitions
if(WIN32)
   target_compile_definitions(maroon PRIVATE  
      MR_PLATFORM_WINDOWS 
      MR_BUILD_DLL
   )
   target_compile_definitions(sandbox PRIVATE  
      MR_PLATFORM_WINDOWS 
   )
endif()


# Set output directories
#set_target_properties(${PROJECT_NAME} PROPERTIES
#    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug
#    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release
#)

# Optional: Link additional libraries if needed
# target_link_libraries(${PROJECT_NAME} PRIVATE some_library)