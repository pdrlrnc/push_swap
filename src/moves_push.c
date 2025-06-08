/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:44:46 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/08 13:44:47 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_a()
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = stack_factory('a');
	stack_b = stack_factory('b');
	
	if (*stack_b)
	{
		ft_lstadd_front(stack_a, *stack_b);
		*stack_b = (*stack_b)->next;
		return (1);
	}
	return (0);
}

int	push_b()
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = stack_factory('a');
	stack_b = stack_factory('b');
	
	if (*stack_a)
	{
		if (!*stack_b)
			*stack_b = ft_lstnew(((*stack_a)->content));
		else
			ft_lstadd_front(stack_b, *stack_a);
		*stack_a = (*stack_a)->next;
		return (1);
	}
	return (0);
}
