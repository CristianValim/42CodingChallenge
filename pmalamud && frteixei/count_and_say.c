/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_say.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalamud <pmalamud@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:03:19 by pmalamud          #+#    #+#             */
/*   Updated: 2024/10/23 13:24:06 by pmalamud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	encode_char(char *str)
{
	int		count;
	char	repeated_char;

	count = 0;
	repeated_char = str[0];
	while (str[count] == repeated_char)
		count++;
	printf("%i%c", count, repeated_char);
	if (str[count] != '\0')
		printf(" ");
	return (count);
}

int	main(int argc, char *argv[])
{
	int	index;

	if (argc != 2)
		return (1);
	index = 0;
	while (argv[1][index])
		index += encode_char(&argv[1][index]);
}
