#include<stdio.h>
#include<unistd.h>

int	ft_strlen(char *s)
{
	int i = 0;

	while(s[i])
		i++;
	return(i);
}
void printnumber(int	k)
{
	char convert;
	if( k < 10)
	{
		convert = k+'0';
		write(1,&convert,1);
	}
	else
	{
		printnumber( k / 10);
		printnumber(k % 10);
	}
}


int main(int c,char **v)
{
	int i=1;
	int	count=1;
	if(c==2)
	{
		while(i < ft_strlen(v[1]) +1 )
		{
			if(v[1][i] == v[1][i-1])
			{
				count++;
			}
			else{
				printnumber(count);
				write(1,&v[1][i-1],1);
				if(i != ft_strlen(v[1]) )
					write(1," ",1);
				count=1;
			}
			i++;
		}
	}
}

		
