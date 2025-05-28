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
