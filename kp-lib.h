/*********************************************************************************
* a bunch of things i've defined for my own convenience.
* I store this file in source control and link it from multiple projects
*********************************************************************************/

// ==========================================================================
// PA COMMENT TEMPLATE
// ==========================================================================

/*
* Programmer: 
* Class: CptS 121, Lab Section 17L
* Programming Assignment:
* Date:
* Description:
*/

// ==========================================================================
// FUNCTION COMMENT TEMPLATE
// ==========================================================================
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

	// ==========================================================================
	// CONSTANTS
	// ==========================================================================
	#define SUCCESS 0

	// ==========================================================================
	// OS DEPENDENT
	// ==========================================================================
	#if defined(_WIN32) || defined (_WIN64) // visual studio 2019
		#define CLEAR_SCREEN system("cls")
	#elif defined (__linux__)
		// TODO: change this to something more platform independent.
		#define CLEAR_SCREEN printf("\033[H\033[J")
	#elif defined (OS_OVERRIDE)

	#else
		#error Unrecognized OS. Please find out how to define for this system.
	#endif

	// ==========================================================================
	// COMPILER DEPENDENT
	// ==========================================================================
	#if defined (_MSC_VER)
	// visual studio
		#define FORCE_INLINE inline

	#elif defined(__GNUC__)
		// gcc
		#define FORCE_INLINE __attribute__((always_inline))

	#endif

	// ==========================================================================
	// GLOBAL MACROS
	// ==========================================================================
	#define ASSERT(e) (sizeof(struct { int:-!(e); })) // shamelessly stolen from the linux kernel

	#define DUMP_SCAN for (int c; (c = getchar()) != '\n' && c != EOF;) {}

	#define WAIT_FOR_ENTER for (int c; (c =getchar()) != '\n' && c != EOF;);

	#define PAUSE printf("Press enter to continue."); WAIT_FOR_ENTER

	#define UNIMPLEMENTED(S) CLEAR_SCREEN; printf(#S " is unimplemented.\n"); PAUSE

	#define LOOPING_INCREMENT(token, max_value) \
	if (token == max_value) { \
		token = 0; \
	} \
	else ++(token)

	#define RANDOM_RANGE(start, end) ASSERT(end > start); ((rand() % end)+start) // this is inclusive

	#define STRINGIFY(n) #n

	#define COUNT_DIGITS(n) (sizeof(STRINGIFY(n)) -1)

#endif KP_LIB_H


