cmake_minimum_required(VERSION 3.10)
project(bitwise_proj C)

# Use Clang
set(CMAKE_C_COMPILER clang)

# Set C standard
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add compile warnings
add_compile_options(-Wall -Wextra -pedantic)

# Define your sources
set(SOURCES
    bitwise.c
)

# Create executable
add_executable(bitwise ${SOURCES})

# Add 'run' custom target
add_custom_target(run
    COMMAND ./bitwise 
    DEPENDS bitwise 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Add 'valgrind' custom target
find_program(VALGRIND "valgrind")
if(VALGRIND)
    add_custom_target(valgrind
        COMMAND ${VALGRIND} --leak-check=full --track-origins=yes ./bitwise 
        DEPENDS bitwise 
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running with Valgrind"
    )
else()
    message(WARNING "Valgrind not found. 'make valgrind' won't work.")
endif()
