#include "kp-lib.h"

void input_string_and_flush(char input[], size_t size)
{
	if (fgets(input, size, stdin))
	{
		if (!strchr(input, '\n'))
		{
			DUMP_STDIN;
		}
	} else
	{
		input[0] = '\0';
	}
}

bool yn_prompt(char * prompt)
{
	const char * error_message = "";
	char input = '\0';
	bool play_again = false;
	while (true)
	{
		
		CLEAR_SCREEN;
		printf("%s (y/n)\n\n* %s\n\n >> ", prompt, error_message);
		input = getchar();
		if (input == 'y') 
		{
			play_again = true;
			break;
		}
		else if (input == 'n')
		{
			play_again = false;
			break;
		}

		error_message = "Please input y or n.";
	}
	while ((input = getchar()) != '\n') ;
	return play_again;
}