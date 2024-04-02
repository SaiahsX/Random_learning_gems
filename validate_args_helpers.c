/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:11:28 by pchennia          #+#    #+#             */
/*   Updated: 2024/02/26 10:25:46 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 12) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	wordcount(char const *s, char delimiter)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (*s != '\0')
	{
		if (*s != delimiter && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*s == delimiter)
			i = 0;
		s++;
	}
	return (count);
}

void	capacity_checking(char *argv[])
{
	int	capacity;

	capacity = wordcount(argv[1], ' ');
	if (capacity == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
