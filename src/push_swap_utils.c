/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:18:37 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/28 15:18:38 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

int	is_ordered(char c)
{
	t_list	*head;

	head = *stack_factory(c);
	while (head->next)
	{
		if (*(int *)head->content > *(int *)(head->next)->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	add_move(char *move)
{
	if (!stack_factory('m'))
		*stack_factory('m') = ft_lstnew(move);
	else
		ft_lstadd_back(stack_factory('m'), ft_lstnew(move));
}

int	get_min_index(char c)
{
	t_list	*curr;
	int		min;
	int		min_index;
	int		i;

	curr = *(stack_factory(c));
	min = *((int *)(curr)->content);
	min_index = 0;
	i = 0;
	while (curr)
	{
		if (*((int *)curr->content) < min)
		{
			min_index = i;
			min = *((int *)curr->content);
		}
		curr = curr->next;
		i++;
	}
	return (min_index);
}
