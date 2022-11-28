cmake_minimum_required(VERSION 3.12)
project(hangman VERSION 0.0.1 LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
string(TOLOWER ${CMAKE_BUILD_TYPE} HGM_BUILD_TYPE)
set(HGM_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${HGM_BASE_DIR}/bin/${HGM_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${HGM_BASE_DIR}/bin/${HGM_BUILD_TYPE})

set(HGM_LIB_SRCS ${HGM_BASE_DIR}/src/hangman_core.c)
set(HGM_GAME_SRCS ${HGM_BASE_DIR}/src/main.c)

add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter -Wno-unused-function -Wdouble-promotion -Wformat-overflow -Wformat-security -Wnull-dereference -Wmisleading-indentation -Wconversion -Wshadow -Wcast-qual -Wcast-align -Waddress)

add_library(hangman_core SHARED ${HGM_LIB_SRCS})
set_target_properties(hangman_core PROPERTIES PREFIX "")

add_executable(hangman_game ${HGM_GAME_SRCS})
target_link_libraries(hangman_game PUBLIC hangman_core)

target_include_directories(hangman_game PUBLIC ${HGM_BASE_DIR}/include)
target_include_directories(hangman_core PUBLIC ${HGM_BASE_DIR}/include)

set_target_properties(hangman_game
PROPERTIES
	C_STANDARD 17
	C_STANDARD_REQUIRED ON
	C_EXTENSIONS OFF
)