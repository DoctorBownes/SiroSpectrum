# CMake entry point
cmake_minimum_required (VERSION 3.12)
project (SiroSpectrum)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

# Compile external dependencies
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")
	# -Wall -Werror -pedantic 
	# For leak-checking and profiling, add '-pg' to CXX flags
	# set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11 -O2")
	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
endif(UNIX)

if(WIN32)
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)

add_definitions( # g++ -Dxxx
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-D_CRT_SECURE_NO_WARNINGS
)

# Compile external dependencies
add_subdirectory (external)

include_directories( # g++ -Ipath/to/headerfiles
	external/glfw-3.3.8/include/
	external/glad-3.3/include/
	.
)

link_directories( # g++ -Lpath/to/library
)

set(ALL_GRAPHICS_LIBS
	glfw
	SiroSpectrum
)

# SiroSpectrum (libSiroSpectrum.a)
add_library(SiroSpectrum # ar rcs libSiroSpectrum.a
	external/glad-3.3/src/glad.c
	SiroSpectrum/core.c
	SiroSpectrum/core.h
	SiroSpectrum/game.c
	SiroSpectrum/game.h
	SiroSpectrum/renderer.c
	SiroSpectrum/renderer.h
	SiroSpectrum/sprite.h
	SiroSpectrum/input.c
	SiroSpectrum/input.h
)

# TEMPTARE
add_executable(TEMPTARE # g++ TEMPTARE/main.c -o TEMPTARE
	TEMPTARE/main.c
	TEMPTARE/entity.c
	TEMPTARE/entity.h
	TEMPTARE/checkpoint.h
)
target_link_libraries(TEMPTARE # g++ -lSiroSpectrum
	${ALL_GRAPHICS_LIBS}
)
	target_link_libraries(TEMPTARE
		${ALL_GRAPHICS_LIBS}
	)

