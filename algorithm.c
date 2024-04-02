/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:05:59 by pchennia          #+#    #+#             */
/*   Updated: 2024/02/13 13:45:27 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_count_using_rarb(t_stack *a, t_stack *b, int num, char s)
{
	int	i;

	if (s == 'a')
	{
		i = find_normal_rotate_count_a(a, num);
		if (i < find_index(b, num))
			i = find_index(b, num);
	}
	else
	{
		i = find_normal_rotate_count_b(b, num);
		if (i < find_index(a, num))
			i = find_index(a, num);
	}
	return (i);
}

int	rotate_count_using_rrarb(t_stack *a, t_stack *b, int num, char s)
{
	int	i;

	i = 0;
	if (s == 'a')
	{
		if (find_normal_rotate_count_a(a, num))
			i = (a->top + 1) - find_normal_rotate_count_a(a, num);
		i = find_index(b, num) + i;
	}
	else
	{
		if (find_index(a, num))
			i = (a->top + 1) - find_index(a, num);
		i = find_normal_rotate_count_b(b, num) + i;
	}
	return (i);
}

int	rotate_count_using_rarrb(t_stack *a, t_stack *b, int num, char s)
{
	int	i;

	i = 0;
	if (s == 'a')
	{
		if (find_index(b, num))
			i = (b->top + 1) - find_index(b, num);
		i = find_normal_rotate_count_a(a, num) + i;
	}
	else
	{
		if (find_normal_rotate_count_b(b, num))
			i = (b->top + 1) - find_normal_rotate_count_b(b, num);
		i = find_index(a, num) + i;
	}
	return (i);
}

int	rotate_count_using_rrarrb(t_stack *a, t_stack *b, int num, char s)
{
	int	i;

	i = 0;
	if (s == 'a')
	{
		if (find_normal_rotate_count_a(a, num))
			i = (a->top + 1) - find_normal_rotate_count_a(a, num);
		if ((i < ((b->top + 1) - find_index(b, num))) && find_index(b, num))
			i = (b->top + 1) - find_index(b, num);
	}
	else
	{
		if (find_normal_rotate_count_b(b, num))
			i = (b->top + 1) - find_normal_rotate_count_b(b, num);
		if ((i < ((a->top + 1) - find_index(a, num))) && find_index(a, num))
			i = (a->top + 1) - find_index(a, num);
	}
	return (i);
}
