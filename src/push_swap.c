/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:03:17 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/28 15:03:18 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	putstr_wrapper(void *content)
{
	ft_printf("%s", (char *) content);
}

int	main(int argv, char **argc)
{
	int	valid;
	int	i;

	if (argv > 1)
	{
		i = 1;
		while (i < argv)
			valid = string_args(argc[i++]);
		if (valid)
		{
			valid = normalize_lst();
			if (valid && !is_ordered('a'))
				choose_algorithm(ft_lstsize(*stack_factory('a')));
		}
		else
			ft_printf("Error\n");
		clean_list_all_moves();
		ft_lstiter(*stack_factory('m'), putstr_wrapper);
		ft_lstclear(stack_factory('a'), free);
		ft_lstclear(stack_factory('b'), free);
		ft_lstclear(stack_factory('c'), free);
		ft_lstclear(stack_factory('m'), free);
	}
}

void	clean_list_all_moves(void)
{
	t_params	params;

	params.mv_1 = "ra";
	params.mv_2 = "rra";
	clean_list(params);
	params.mv_1 = "rra";
	params.mv_2 = "ra";
	clean_list(params);
	params.mv_1 = "rb";
	params.mv_2 = "rrb";
	clean_list(params);
	params.mv_1 = "rrb";
	params.mv_2 = "rb";
	clean_list(params);
	params.mv_1 = "pa";
	params.mv_2 = "pb";
	clean_list(params);
	params.mv_1 = "pb";
	params.mv_2 = "pa";
	clean_list(params);
}

void	choose_algorithm(int elements)
{
	if (elements == 2)
		hardcoded_2();
	else if (elements == 3)
		hardcoded_3();
	else if (elements == 4)
		hardcoded_4();
	else if (elements == 5)
		hardcoded_5();
	else
		radix();
}

t_list	**stack_factory(char c)
{
	static t_list	*stack_a;
	static t_list	*stack_b;
	static t_list	*moves;

	if (c == 'a')
		return (&stack_a);
	if (c == 'b')
		return (&stack_b);
	if (c == 'm')
		return (&moves);
	return (NULL);
}
