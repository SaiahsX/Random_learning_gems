/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:40:14 by pchennia          #+#    #+#             */
/*   Updated: 2024/02/13 15:38:21 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int	max;
	int	i;

	i = 1;
	max = stack->elts[0];
	while (i <= stack->top)
	{
		if (stack->elts[i] > max)
			max = stack->elts[i];
		i++;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	min;
	int	i;

	i = 1;
	min = stack->elts[0];
	while (i <= stack->top)
	{
		if (stack->elts[i] < min)
			min = stack->elts[i];
		i++;
	}
	return (min);
}

int	find_index(t_stack *stack, int num)
{
	int	index;
	int	i;

	index = 0;
	i = stack->top;
	while (stack->elts[i] != num)
	{
		i--;
		index++;
	}
	return (index);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->elts[i] < stack->elts[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
