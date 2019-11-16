#include "kp-lib.h"

/// This function calls fgets with the given input buffer
/// and then flushes stdin.
/// size should include space for the null terminator.
void input_line(char * input_buffer, size_t size)
{
	if (fgets(input_buffer, size, stdin))
	{
		if (!strchr(input_buffer, '\n'))
		{
			for (int ch; (ch =getchar()) != '\n' && ch != EOF;);
		}
	} else
	{
		input_buffer[0] = '\0';
	}
}

bool yn_prompt(char * prompt)
{
	const char * error_message = "";
	char input = '\0';
	bool play_again = false;
	bool valid_input = false;
	do
	{
		
		CLEAR_SCREEN;
		printf("%s (y/n)\n\n* %s\n\n >> ", prompt, error_message);
		input = (char)getchar();
		if (input == 'y') 
		{
			play_again = true;
			valid_input = true;
		}
		else if (input == 'n')
		{
			play_again = false;
			valid_input = true;
		} while (!valid_input);

		error_message = "Please input y or n.";
	}
	while ((input = (char)getchar()) != '\n') ;
	return play_again;
}