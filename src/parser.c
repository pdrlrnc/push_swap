/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:43:08 by pedde-so          #+#    #+#             */
/*   Updated: 2025/08/20 11:43:12 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	string_args(char **argc)
{
	int		i;
	int		valid;
	char	**inputs;

	i = 0;
	valid = 1;
	inputs = ft_split(argc[1], ' ');
	if (!inputs || !inputs[0])
		return (0);
	while (inputs[i] && valid)
		valid = ft_str_isdigit(inputs[i++]);
	if (valid)
	{
		i = 0;
		while (inputs[i] && valid)
			valid = add_to_stack(inputs[i++]);
	}
	ft_splitfree(inputs);
	return (valid);
}

int	value_args(int argv, char **argc)
{
	int	i;
	int	valid;

	i = 1;
	valid = 1;
	while ((i < argv) && valid)
		valid = ft_str_isdigit(argc[i++]);
	i = 1;
	while ((i < argv) && valid)
		valid = add_to_stack(argc[i++]);
	return (valid);
}

int	add_to_stack(char *argc)
{
	int	*nb;

	nb = malloc(sizeof(int));
	if (!nb)
		return (0);
	if (ft_atoi_l(argc) > INT_MAX || ft_atoi_l(argc) < INT_MIN)
		return (free(nb), (0));
	*nb = ft_atoi(argc);
	if (ft_lst_contains_int(*(stack_factory('a')), nb))
		return (free(nb), (0));
	if (!stack_factory('a'))
		*(stack_factory('a')) = ft_lstnew(nb);
	else
		ft_lstadd_back(stack_factory('a'), ft_lstnew(nb));
	return (1);
}

static int	normalize_lst_cont(int lst_size, int *values)
{
	t_list	*lst;
	int		i;

	lst = *(stack_factory('a'));
	while (lst)
	{
		i = 0;
		while (i < lst_size)
		{
			if (*(values + i) == *(int *)lst->content)
				*(int *)lst->content = i;
			i++;
		}
		lst = lst->next;
	}
	free(values);
	return (1);
}

int	normalize_lst(void)
{
	int		*values;
	int		i;
	int		lst_size;
	t_list	*lst;

	lst = *(stack_factory('a'));
	lst_size = ft_lstsize(lst);
	if (lst_size < 2)
	{
		if (lst_size == 1)
			*(int *)(lst->content) = 0;
		return (1);
	}
	values = malloc(sizeof(int) * lst_size);
	if (!values)
		return (0);
	i = 0;
	while (lst)
	{
		*(values + i++) = *(int *)lst->content;
		lst = lst->next;
	}
	bubble_sort_arr(values, lst_size);
	return (normalize_lst_cont(lst_size, values));
}
