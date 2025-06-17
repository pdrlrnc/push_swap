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
		if (head->content > (head->next)->content)
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_check_if_zero(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*(str + i))
	{
		if (ft_isspace(*(str + i)))
			i++;
		else if (*(str + i) == '0')
				return (1);
		else
			return (0);
	}
	return (0);
}

int	get_max_index(char c)
{
	t_list	*curr;
	int	max;
	int	max_index;
	int	i;

	curr = *(stack_factory(c));
	max = *((int *)(curr)->content);
	max_index = 0;
	i = 0;
	while (curr)
	{
		if (*((int *)curr->content) > max)
		{
			max_index = i;
			max = *((int *)curr->content);
		}
		curr = curr->next;
		i++;
	}
	return (max_index);
}

int	get_min_index(char c)
{
	t_list	*curr;
	int	min;
	int	min_index;
	int	i;

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

static void	copy_a(void)
{
	t_list	*curr_a;
	t_list	*curr_cpy;

	curr_a = *(stack_factory('a'));
	curr_cpy = *(stack_factory('c'));
	while (curr_a)
	{
		(*(int *)(curr_cpy->content)) = *((int *)(curr_a->content));

		curr_a = curr_a->next;
		curr_cpy = curr_cpy->next;
	}
}

void	bubble_sort_cpy(void)
{
	int	sorted;
	t_list	*prev;
	t_list	*curr;
	t_list	*next;
	t_list	*aux;
	
	copy_a();
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		prev = NULL;
		curr = *(stack_factory('c'));
		next = (*(stack_factory('c')))->next;
		while (next)
		{
			if ((*(int *)curr->content) > (*(int *)next->content))
			{
				sorted = 0;
				if (prev == NULL)
				{
					curr->next = next->next;
					next->next = curr;
					*(stack_factory('c')) = next;
				}
				else
				{
					aux = next->next;
					prev->next = next;
					next->next = curr;
					curr->next = aux;
				}
			}
			if (prev == NULL)
				prev = *(stack_factory('c'));
			else
				prev = curr;
			curr = next;
			next = next->next;
		}	
	}
}


