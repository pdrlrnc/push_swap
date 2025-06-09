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
	write(1, "rr\n", 3);
	return (rotate_generic('a') & rotate_generic('b'));
}

int	rotate_b()
{
	write(1, "rb\n", 3);
	return (rotate_generic('b'));
}

int	rotate_a()
{
	write(1, "ra\n", 3);
	return (rotate_generic('a'));
}
