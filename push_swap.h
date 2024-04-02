/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:23:33 by pchennia          #+#    #+#             */
/*   Updated: 2024/02/28 09:34:15 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 1

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	capacity;
	int	top;
	int	*elts;
}	t_stack;

// Argument Checking
int		validate_args(char **args, int arg_index);
int		is_numeric_string(const char *string);
int		check_overflow(char *strnum);
int		is_duplicate(char *argv[]);
long	ft_atol(char *str);
void	capacity_checking(char *argv[]);
void	free_args(char **args);
int		wordcount(char const *s, char delimiter);

//Sorting
int		sorting(int argc, char **args, int argIndex);
void	initialize_stack(t_stack *stack, int capacity);
void	move_args_to_stack(int c, int argIndex, char *argv[], t_stack *stack);
void	sort_stack_a(t_stack *a, t_stack *b);
void	sort_stack_b(t_stack *a, t_stack *b);
void	final_move(t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);

// Sorting Stack A
int		find_normal_rotate_count_a(t_stack *a, int num);
int		find_normal_rotate_count_ab(t_stack *a, t_stack *b, int num, char s);
int		find_best_rotate_count_a(t_stack *a, t_stack *b);

// Sorting Stack B
void	sort_b_till_3(t_stack *a, t_stack *b);
void	sorting_three_numbers(t_stack *a);
// Sorting Stack B until three numbers in Stack A
int		find_normal_rotate_count_b(t_stack *b, int num);
int		find_best_rotate_count_b(t_stack *a, t_stack *b);

// Algorithm to check the best rotate combination
int		rotate_count_using_rarb(t_stack *a, t_stack *b, int num, char s);
int		rotate_count_using_rrarb(t_stack *a, t_stack *b, int num, char s);
int		rotate_count_using_rarrb(t_stack *a, t_stack *b, int num, char s);
int		rotate_count_using_rrarrb(t_stack *a, t_stack *b, int num, char s);

// Apply algorithm to Stack A and stack B
int		apply_rarb(t_stack *a, t_stack *b, int num, char s);
int		apply_rrarrb(t_stack *a, t_stack *b, int num, char s);
int		apply_rarrb(t_stack *a, t_stack *b, int num, char s);
int		apply_rrarb(t_stack *a, t_stack *b, int num, char s);

// Sorting Helper Functions
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		find_index(t_stack *stack, int num);
int		is_sorted(t_stack *stack);

// Rules
// 1. Swap
void	sa(t_stack *stackA, int n);
void	sb(t_stack *stackB, int n);
void	ss(t_stack *stackA, t_stack *stackB, int n);
void	swap(t_stack *stack);

// 2. Rotate
void	ra(t_stack *stackA, int n);
void	rb(t_stack *stackB, int n);
void	rr(t_stack *stackA, t_stack *stackB, int n);
void	rotate(t_stack *stack);

// 3. Reverse rotate
void	rra(t_stack *stackA, int n);
void	rrb(t_stack *stackB, int n);
void	rrr(t_stack *stackA, t_stack *stackB, int n);
void	reverse_rotate(t_stack *stack);

// 4. Push to another stack
void	pa(t_stack *stackA, t_stack *stackB, int n);
void	pb(t_stack *stackA, t_stack *stackB, int n);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);

#endif
