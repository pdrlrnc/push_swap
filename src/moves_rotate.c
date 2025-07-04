/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:01:42 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/09 12:01:43 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	rotate_generic(char c)
{
	t_list	**stack;
	t_list	*prev;
	t_list	*next;
	t_list	*temp;

	stack = stack_factory(c);
	prev = *stack;
	next = prev->next;
	if (prev && next)
	{
		while (next)
		{
			prev = prev->next;
			next = next->next;
		}
		temp = (*stack)->next;
		prev->next = *stack;
		(prev->next)->next = NULL;
		*stack = temp;
		return (1);
	}
	return (0);
}

int	rr()
{
	char	*move;

	move = malloc(4);
	if (!move)
		return (0);
	*move = 'r';
	*(move + 1) = 'r';
	*(move + 2) = '\n';
	*(move + 3) = '\0';
	add_move(move);
	return (rotate_generic('a') & rotate_generic('b'));
}

int	rotate_b()
{
	char	*move;

	move = malloc(4);
	if (!move)
		return (0);
	*move = 'r';
	*(move + 1) = 'b';
	*(move + 2) = '\n';
	*(move + 3) = '\0';
	add_move(move);
	return (rotate_generic('b'));
}

int	rotate_a()
{
	char	*move;

	move = malloc(4);
	if (!move)
		return (0);
	*move = 'r';
	*(move + 1) = 'a';
	*(move + 2) = '\n';
	*(move + 3) = '\0';
	add_move(move);
	return (rotate_generic('a'));
}
