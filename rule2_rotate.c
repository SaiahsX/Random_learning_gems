/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule2_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:47:38 by pchennia          #+#    #+#             */
/*   Updated: 2024/02/26 11:31:58 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	top_element;
	int	index;

	top_element = stack->elts[stack->top];
	index = stack->top;
	while (index > 0)
	{
		stack->elts[index] = stack->elts[index - 1];
		index--;
	}
	stack->elts[index] = top_element;
}

void	ra(t_stack *stackA, int n)
{
	rotate(stackA);
	if (n == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stackB, int n)
{
	rotate(stackB);
	if (n == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stackA, t_stack *stackB, int n)
{
	rotate(stackA);
	rotate(stackB);
	if (n == 0)
		write(1, "rr\n", 3);
}
