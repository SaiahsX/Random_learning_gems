/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:06:45 by pchennia          #+#    #+#             */
/*   Updated: 2024/02/26 10:16:31 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_b(t_stack *a, t_stack *b)
{
	if (a->top == 1 && !is_sorted(a))
		sa(a, 0);
	else
	{
		if (a->top > 2 && !is_sorted(a))
			pb(a, b, 0);
		if (a->top > 2 && !is_sorted(a))
			pb(a, b, 0);
		if (a->top > 2 && !is_sorted(a))
			sort_b_till_3(a, b);
		if (!is_sorted(a))
			sorting_three_numbers(a);
	}
}

void	sort_b_till_3(t_stack *a, t_stack *b)
{
	int		count;
	int		num;
	t_stack	temp;

	while (a->top > 2 && !is_sorted(a))
	{
		temp = *a;
		count = find_best_rotate_count_b(a, b);
		while (count >= 0)
		{
			num = temp.elts[temp.top];
			if (count == rotate_count_using_rarb(a, b, num, 'b'))
				count = apply_rarb(a, b, num, 'a');
			else if (count == rotate_count_using_rrarrb(a, b, num, 'b'))
				count = apply_rrarrb(a, b, num, 'a');
			else if (count == rotate_count_using_rarrb(a, b, num, 'b'))
				count = apply_rarrb(a, b, num, 'a');
			else if (count == rotate_count_using_rrarb(a, b, num, 'b'))
				count = apply_rrarb(a, b, num, 'a');
			else
				temp.top--;
		}
	}
}

int	find_best_rotate_count_b(t_stack *a, t_stack *b)
{
	int		count;
	int		num;
	t_stack	temp;

	temp = *a;
	count = find_normal_rotate_count_ab(a, b, a->elts[a->top], 'b');
	while (temp.top >= 0)
	{
		num = temp.elts[temp.top];
		if (count > rotate_count_using_rarb(a, b, num, 'b'))
			count = rotate_count_using_rarb(a, b, num, 'b');
		if (count > rotate_count_using_rrarrb(a, b, num, 'b'))
			count = rotate_count_using_rrarrb(a, b, num, 'b');
		if (count > rotate_count_using_rarrb(a, b, num, 'b'))
			count = rotate_count_using_rarrb(a, b, num, 'b');
		if (count > rotate_count_using_rrarb(a, b, num, 'b'))
			count = rotate_count_using_rrarb(a, b, num, 'b');
		temp.top--;
	}
	return (count);
}

int	find_normal_rotate_count_b(t_stack *b, int num)
{
	int	i;
	int	j;

	i = 1;
	if (num > b->elts[b->top] && num < b->elts[0])
		i = 0;
	else if (num > find_max(b) || num < find_min(b))
		i = find_index(b, find_max(b));
	else
	{
		j = b->top;
		while ((b->elts[j] < num || b->elts[j - 1] > num) && j - 1 > 0)
		{
			j = j - 1;
			i++;
		}
	}
	return (i);
}

void	sorting_three_numbers(t_stack *a)
{
	int	max;
	int	min;

	min = find_min(a);
	max = find_max(a);
	if (min == a->elts[a->top])
	{
		rra(a, 0);
		sa(a, 0);
	}
	else if (max == a->elts[a->top])
	{
		ra(a, 0);
		if (!is_sorted(a))
			sa(a, 0);
	}
	else
	{
		if (max == a->elts[a->top - 1])
			rra(a, 0);
		else
			sa(a, 0);
	}
}
