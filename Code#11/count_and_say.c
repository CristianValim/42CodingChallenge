#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	int rep;

	if (argc != 2)
		return(0);
	i = 0;
	while(argv[1][i] != '\0')
	{
		rep = 1;
		while((argv[1][i+1] != '\0') && (argv[1][i] == argv[1][i+1]))
		{
			rep++;
			i++;
		}
		printf("%d%c ", rep, argv[1][i]);
		i++;
	}
}