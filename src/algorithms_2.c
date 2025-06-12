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

static	void value_found(int i, int size)
{
	if ((size / 2) > i)
	{
		while (i--)
			rotate_a();
		push_b();
	}
	else
	{
		while (i++ < size)
			rra();

		push_b();
	}
	write(1, "After value found I got:\nA:", 27); 
	ft_lstprnt(*stack_factory('a'));
	write(1, "\nB:\n", 4);
	ft_lstprnt(*stack_factory('b'));
	write(1, "\n", 1);
}

void	chunked_insertion_sort(void)
{
	int	*normalized;
	int	chunk_min;
	int	chunk_max;
	int	i;
	int	k;
	int	size;

	normalized = normalize_input();
	chunk_min = 0;
	chunk_max = 3;
	i = 0;
	k = 0;
	size = ft_lstsize(*stack_factory('a'));
	while (chunk_max < size)
	{
		while (k <= chunk_max)
		{
			if ((*(normalized + i) >= chunk_min) && (*(normalized + i) <= chunk_max))
			{	
				k++;
				value_found(i, size);
				i = 0;
			}
			i++;
		}
		chunk_min += 4;
		chunk_max += 4;	
		if (chunk_max >= size)
			chunk_max = size - 1;
	}
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

	i = 0;
	write(1, "\nNorm: [ ", 8);
	while (i < lst_size)
	{
		ft_putnbr_fd(*(normalized + i), 1);
		i++;
		if (i < lst_size)
			write(1, ", ", 2);
	}
	write(1, "]\n", 2);

	return (normalized);
}

