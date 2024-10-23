#include<stdio.h>
#include<unistd.h>

void count_and_say(char *input)
{
    int count = 0;
	int sp = 0;
	char cchar = 32;

	while(input[count] != '\0')
	{
		if(input[count] != cchar)
		{
			printf("%d",sp);
			printf("%c", cchar);
			printf("%c", 32);
			sp = 0;
		}
		count++;
		sp++;
		cchar = input[count]; 
	}


}

int main (int argc, char **argv)
{ 
	if(argc == 1)
 		count_and_say(argv[1]);
	return 0;
}