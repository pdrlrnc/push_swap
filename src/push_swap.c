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

#include "../include/libft.h"
#include "../include/push_swap.h"
#include <stdio.h>
/*prototypes*/
int	ft_create_stack(t_list *stack, char *argc);

int	main(int argv, char **argc)
{
	t_list	*stack;
	int	crt_reslt;
	int	i;

	if (argv > 0)
	{
		stack = NULL;
		i = 1;
		while (i < argv)
		{
			if (!ft_create_stack(stack, argc[i]))
				printf("Error\n");
			i++;
		}
	}
}



int	ft_create_stack(t_list *stack, char *argc)
{
	int	nb;

	if (ft_check_if_zero(argc))
	{
		nb = 0;
		if (stack == NULL)
			stack = ft_lstnew(&nb);
		else
			ft_lstadd_front(&stack, ft_lstnew(&nb));
	}
	else
	{
		nb = ft_atoi(argc);
		if (nb == 0)
			return (0);
		if (stack == NULL)
			stack = ft_lstnew(&nb);
		else
			ft_lstadd_front(&stack, ft_lstnew(&nb));
	}
	if (!stack)
		return (0);
	return (1);
}
