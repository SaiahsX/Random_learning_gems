/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:31:07 by pchennia          #+#    #+#             */
/*   Updated: 2024/02/26 10:17:52 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_rarb(t_stack *a, t_stack *b, int num, char s)
{
	if (s == 'a')
	{
		while (a->elts[a->top] != num && find_normal_rotate_count_b(b, num) > 0)
			rr(a, b, 0);
		while (a->elts[a->top] != num)
			ra(a, 0);
		while (find_normal_rotate_count_b(b, num) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (b->elts[b->top] != num && find_normal_rotate_count_a(a, num) > 0)
			rr(a, b, 0);
		while (b->elts[b->top] != num)
			rb(b, 0);
		while (find_normal_rotate_count_a(a, num) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarrb(t_stack *a, t_stack *b, int num, char s)
{
	if (s == 'a')
	{
		while (a->elts[a->top] != num && find_normal_rotate_count_b(b, num) > 0)
			rrr(a, b, 0);
		while (a->elts[a->top] != num)
			rra(a, 0);
		while (find_normal_rotate_count_b(b, num) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (b->elts[b->top] != num && find_normal_rotate_count_a(a, num) > 0)
			rrr(a, b, 0);
		while (b->elts[b->top] != num)
			rrb(b, 0);
		while (find_normal_rotate_count_a(a, num) > 0)
			rra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rarrb(t_stack *a, t_stack *b, int num, char s)
{
	if (s == 'a')
	{
		while (a->elts[a->top] != num)
			ra(a, 0);
		while (find_normal_rotate_count_b(b, num) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_normal_rotate_count_b(b, num) > 0)
			ra(a, 0);
		while (b->elts[b->top] != num)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarb(t_stack *a, t_stack *b, int num, char s)
{
	if (s == 'a')
	{
		while (a->elts[a->top] != num)
			rra(a, 0);
		while (find_normal_rotate_count_b(b, num) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_normal_rotate_count_b(b, num) > 0)
			rra(a, 0);
		while (b->elts[b->top] != num)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}
