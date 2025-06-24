/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:07:59 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/24 14:08:00 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix(void)
{
	int	*normalized;
	int	size;
	int	max;
	int	bits;
	int	i;

	normalized = normalize_input();
	size = ft_lstsize(*stack_factory('a'));
	max = get_max_index_normalized(normalized, size);
	bits = 0;
	while ((max >> bits) != 0)
	{
		i = 0;
		while (i < size)
		{
			if ((*((int *)(*stack_factory('a'))->content) >> bits & 1) == 0)
				push_b();
			else
				rotate_a();
			i++;
		}
		while (ft_lstsize(*(stack_factory('b'))))
			push_a();
		bits++;
		if (is_ordered('a'))
			return ;
	}
}

int	get_max_index_normalized(int *normalized, int size)
{
	int	i;
	int	max;
	t_list	*stack_a;

	i = 0;
	max = *normalized;
	while (i < size)
	{
		if (*(normalized + i) > max)
			max = *(normalized + i);
		i++;
	}
	i = 0;
	stack_a = *stack_factory('a');
	while (stack_a)
	{
		*(int *)(stack_a->content) = *(normalized + i);
		stack_a = stack_a->next;
		i++;
	}
	return (max);
}
