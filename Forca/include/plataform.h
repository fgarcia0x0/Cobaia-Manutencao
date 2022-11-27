#pragma once

#if defined(__GNUC__) && !defined(__clang__)
	#define HANGMAN_COMPILER_GCC 1
#elif defined(_MSC_VER)
	#define HANGMAN_COMPILER_MSVC 1
#elif defined(__GNUC__) && defined(__clang__)
	#define HANGMAN_COMPILER_CLANG 1
#else
	#error "Please add support for your compiler"
#endif

#ifdef HANGMAN_COMPILER_MSVC
	#define HANGMAN_API __declspec(dllexport)
#elif (HANGMAN_COMPILER_GCC || HANGMAN_COMPILER_CLANG)
	// -fvisibility=hidden
	#define HANGMAN_API __attribute__((visibility("default")))
#else
    #define HANGMAN_API
#endif