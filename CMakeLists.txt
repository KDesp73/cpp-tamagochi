cmake_minimum_required(VERSION 3.5)
project(Tamagochi)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(include)

add_subdirectory(Cli-Kit)
include_directories(Cli-Kit)


# Add your source files
set(SOURCES
    src/main.cpp
    src/tamagochi.cpp
    src/utils.cpp
    src/ui.cpp
)

# Add your header files
set(HEADERS
    include/tamagochi.h
    include/burger.h
    include/cake.h
    include/food.h
    include/status.h
    include/utils.h
    include/ui.h
)

set(TESTS
    tests/test.cpp
)

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${TESTS})

target_link_libraries(${PROJECT_NAME} CliKit)

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

