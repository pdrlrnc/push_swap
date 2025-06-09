/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:56:34 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/09 12:56:35 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	rotate_reverse_generic(char c)
{
	t_list	**stack;
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	stack = stack_factory(c);
	curr = *stack;
	next = (*stack)->next;
	if (curr && next)
	{
		while (next)
		{
			prev = curr;
			curr = prev->next;
			next = curr->next;
		}
		prev->next = NULL;
		curr->next = *stack;
		*stack = curr;
		return (1);
	}
	return (0);
}

int	rra()
{
	write(1, "rra\n", 4);
	return (rotate_reverse_generic('a'));
}

int	rrb()
{
	write(1, "rrb\n", 4);
	return (rotate_reverse_generic('b'));
}

int	rrr()
{
	write(1, "rrr\n", 4);
	return (rotate_reverse_generic('a') & rotate_reverse_generic('b'));
}
