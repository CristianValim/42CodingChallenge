#include<stdio.h>
#include<unistd.h>

int	count(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == str[i + 1]) && (str[i] != '\0'))
	{
		i++;
	}
	printf("%d", i);
	printf("%c", str[i]);
	return(i);
}

int	main(int argc, char *argv[])
{
	int	j;

	j = 0;
	if (argc > 0) 
	{
		while (argv[j] != '\0')
		{
			count(argv[j]);
			printf(" ");
			j++;
		}
	}
	return(0);
}
	
