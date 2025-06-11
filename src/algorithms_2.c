/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:39:58 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/11 16:39:59 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	chunked_insertion_sort(void)
{
	int	*normalized;

	normalized = normalize_input();
	normalized++;
	return;
}

int	*normalize_input(void)
{
	int	*normalized;
	int	i;
	int	j;
	t_list	*stack_a;
	t_list	*stack_a_cpy;
	int	lst_size;

	stack_a = *stack_factory('a');
	ft_lstprnt(*stack_factory('c'));
	bubble_sort_cpy();
	ft_lstprnt(*stack_factory('c'));
	stack_a_cpy = *stack_factory('c');
	lst_size = ft_lstsize(stack_a);
	normalized = malloc(sizeof(int) * lst_size);
	if (!normalized)
		return (NULL);
	j = 0;
	while (stack_a_cpy)
	{
		i = 0;
		stack_a = *stack_factory('a');
		while (stack_a)
		{
			if ((*(int *)stack_a_cpy->content) == (*(int *)stack_a->content))
				break;
			i++;
			stack_a = stack_a->next;
		}
		normalized[i] = j;
		j++;
		stack_a_cpy = stack_a_cpy->next;
	}
}

