/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stackA.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:06:33 by pchennia          #+#    #+#             */
/*   Updated: 2024/02/13 15:40:54 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	t_stack	t;

	j = b->top;
	while (j >= 0)
	{
		t = *b;
		i = find_best_rotate_count_a(a, b);
		while (i >= 0)
		{
			if (i == rotate_count_using_rarb(a, b, t.elts[t.top], 'a'))
				i = apply_rarb(a, b, t.elts[t.top], 'b');
			else if (i == rotate_count_using_rarrb(a, b, t.elts[t.top], 'a'))
				i = apply_rarrb(a, b, t.elts[t.top], 'b');
			else if (i == rotate_count_using_rrarrb(a, b, t.elts[t.top], 'a'))
				i = apply_rrarrb(a, b, t.elts[t.top], 'b');
			else if (i == rotate_count_using_rrarb(a, b, t.elts[t.top], 'a'))
				i = apply_rrarb(a, b, t.elts[t.top], 'b');
			else
				t.top--;
		}
		j--;
	}
}

int	find_best_rotate_count_a(t_stack *a, t_stack *b)
{
	int		count;
	int		num;
	t_stack	temp;

	temp = *b;
	count = find_normal_rotate_count_ab(a, b, b->elts[b->top], 'a');
	while (temp.top >= 0)
	{
		num = temp.elts[temp.top];
		if (count > rotate_count_using_rarb(a, b, num, 'a'))
			count = rotate_count_using_rarb(a, b, num, 'a');
		if (count > rotate_count_using_rrarrb(a, b, num, 'a'))
			count = rotate_count_using_rrarrb(a, b, num, 'a');
		if (count > rotate_count_using_rarrb(a, b, num, 'a'))
			count = rotate_count_using_rarrb(a, b, num, 'a');
		if (count > rotate_count_using_rrarb(a, b, num, 'a'))
			count = rotate_count_using_rrarb(a, b, num, 'a');
		temp.top--;
	}
	return (count);
}

int	find_normal_rotate_count_ab(t_stack *a, t_stack *b, int num, char s)
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

int	find_normal_rotate_count_a(t_stack *a, int num)
{
	int	i;
	int	j;

	i = 1;
	if (num < a->elts[a->top] && num > a->elts[0])
		i = 0;
	else if (num > find_max(a) || num < find_min(a))
		i = find_index(a, find_min(a));
	else
	{
		j = a->top;
		while ((a->elts[j] > num || a->elts[j - 1] < num) && j - 1 > 0)
		{
			j = j - 1;
			i++;
		}
	}
	return (i);
}
