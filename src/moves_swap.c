/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:20:59 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/08 12:21:00 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	swap(char c)
{
	t_list	**stack;
	t_list	*this;
	t_list	*next;
	t_list	*next_next;

	stack = stack_factory(c);
	if (*stack && (*stack)->next)
	{
		this = *stack;
		next = (*stack)->next;
		next_next = ((*stack)->next)->next;
		*stack = next;
		(*stack)->next = this;
		(*stack)->next->next = next_next;
		return (1);
	}
	return (0);
}

int	swap_a()
{
	char	*move;

	move = malloc(4);
	if (!move)
		return (0);
	*move = 's';
	*(move + 1) = 'a';
	*(move + 2) = '\n';
	*(move + 3) = '\0';
	add_move(move);
	return (swap('a'));
}

int	swap_b()
{
	char	*move;

	move = malloc(4);
	if (!move)
		return (0);
	*move = 's';
	*(move + 1) = 'b';
	*(move + 2) = '\n';
	*(move + 3) = '\0';
	add_move(move);
	return (swap('b'));
}

int	ss()
{
	char	*move;

	move = malloc(4);
	if (!move)
		return (0);
	*move = 's';
	*(move + 1) = 's';
	*(move + 2) = '\n';
	*(move + 3) = '\0';
	add_move(move);
	return (swap('a') & swap('b'));
}
