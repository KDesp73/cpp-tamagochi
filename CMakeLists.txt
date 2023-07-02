cmake_minimum_required(VERSION 3.5)
project(YourProjectName)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add your source files
set(SOURCES
    src/main.cpp

)

# Add your header files
set(HEADERS
    include/header.h
)

set(TESTS
    tests/test.cpp
)

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${TESTS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Add any additional libraries or dependencies
# Example:
# find_package(OpenCV REQUIRED)
# target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# Set compiler flags (optional)
# Example:
# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

# Set output directory (optional)
# Example:
# set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

