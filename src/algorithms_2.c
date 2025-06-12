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
	write(1, "\nAfter value found I got:\nA:", 28); 
	ft_lstprnt(*stack_factory('a'));
	write(1, "\nB:\n", 4);
	ft_lstprnt(*stack_factory('b'));
	write(1, "\n", 1);
}

static void	push_back(void)
{
	int	min;

	min = get_min_index('b');
	if (min == 1)
		rotate_b();
	if (min == 2)
		rrb();
	if (min == 2 || min == 3)
		rrb();
	push_a();
	min = get_min_index('b');
	if (min == 1)
		rotate_b();
	if (min == 2)
		rrb();
	push_a();
	min = get_min_index('b');
	if(min == 1)
		rotate_b();
	push_a();
	push_a();
	write(1, "\nAfter push_back I got:\nA:", 28); 
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
				free(normalized);
				normalized = NULL;
				normalized = normalize_input();
				i = 0;
			}
			i++;
		}
		push_back();
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

	write(1, "\nIN NORM:\nA:", 12);
	stack_a = *stack_factory('a');
	ft_lstprnt(stack_a);
	bubble_sort_cpy();
	stack_a_cpy = *stack_factory('c');
	write(1, "\nC:", 4);
	ft_lstprnt(stack_a_cpy);
	lst_size = ft_lstsize(stack_a) + 1;
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
	write(1, "\nN[ ", 8);
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

