/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:06:06 by pchennia          #+#    #+#             */
/*   Updated: 2024/02/29 10:57:32 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		arg_index;
	char	**args;

	arg_index = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		capacity_checking(argv);
		args = ft_split(argv[1], ' ');
	}
	else
	{
		args = argv;
		arg_index = 1;
	}
	validate_args(args, arg_index);
	sorting(argc, args, arg_index);
	return (0);
}
