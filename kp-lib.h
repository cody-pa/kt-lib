/*********************************************************************************
* a bunch of things i've defined for my own convenience.
*********************************************************************************/

// COMMENT TEMPLATES
// PROJECT HEADER
/*
* Programmer: 
* Class: CptS 121, Lab Section 17L
* Programming Assignment:
* Date:
* Description:
*/

// FUNCTION TEMPLATE
/*
Input parameters:
Output parameters:
Returns:
Preconditions:
Postconditions:
Date Last Modified:
Description:
Date Created:
*/

#ifndef KP_LIB_H
#define KP_LIB_H

// my defines
#define PLATFORM vs
#define SUCCESS 0

// platform-dependent code ==========================================================================
#ifdef PLATFORM
	#if (PLATFORM == vs) // visual studio 2019
		#define CLEAR_SCREEN system("cls")
		#define PAUSE system("PAUSE")
	#else
		#error Invalid value for PLATFORM
	#endif
#else
	#error PLATFORM must be defined
#endif


// Debug Stuff ======================================================================================
#ifdef DEBUG
#define ASSERT(e) (sizeof(struct { int:-!(e); })) // shamelessly stolen from the linux kernel
#else
#define ASSERT(e)
#endif

// Macros ===========================================================================================
#define DUMP_SCAN for (int c; (c = getchar()) != '\n' && c != EOF;) {}
#define UNIMPLEMENTED(S) CLEAR_SCREEN; printf_s(#S " is unimplemented.\n"); PAUSE

// C++ EXCLUSIVE
#ifdef __cplusplus

#endif

#endif