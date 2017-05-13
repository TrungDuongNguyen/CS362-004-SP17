#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*The objectives of this assignment was to satisfy the requirements to exit the while loop.  

The first part was the inputCharFunction

	Upon initial inspection of the testme code, the characters to be inspected were examined. 
	The characters were examined wiht the ASCII tables to determine the range of values the generator would requirements
	The 32nd character was space and the 125th character was }
	All the required characters were in this range
	With this in mind, the input character used the random function to return a character between these ranges

The second part was the inputString Function
	
	Through examination of this function, only the string "reset" would allow the function to exit the loop.
	An array with all the required character was created.
	the random function would then generate the characters within this array to build a string of length of 6(the length of the word reset)
	This would allow the function to exit the loop and satisfy the assignment's requirements


*/

char inputChar()
{
	char c = (rand()%(126-32))+32;
	return c;
}

char *inputString()
{
	char strarray[5] = { 'r','s','t','e','\0' };

	char* s = malloc(6);
	int i;
	for (i = 0; i< 6; i++)
	{
		s[i] = strarray[rand() % 5];
	}
	return s;

}

void testme()
{
	int tcCount = 0;
	char *s;
	char c;
	int state = 0;
	while (1)
	{
		tcCount++;
		c = inputChar();
		s = inputString();
		printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

		if (c == '[' && state == 0) state = 1;
		if (c == '(' && state == 1) state = 2;
		if (c == '{' && state == 2) state = 3;
		if (c == ' '&& state == 3) state = 4;
		if (c == 'a' && state == 4) state = 5;
		if (c == 'x' && state == 5) state = 6;
		if (c == '}' && state == 6) state = 7;
		if (c == ')' && state == 7) state = 8;
		if (c == ']' && state == 8) state = 9;
		if (s[0] == 'r' && s[1] == 'e'
			&& s[2] == 's' && s[3] == 'e'
			&& s[4] == 't' && s[5] == '\0'
			&& state == 9)
		{
			printf("error ");
			exit(200);
		}
	}
}


int main(int argc, char *argv[])
{
	srand(time(NULL));
	testme();
	system("pause");
	return 0;
}
