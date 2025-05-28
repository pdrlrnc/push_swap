/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:19:17 by pedde-so          #+#    #+#             */
/*   Updated: 2025/04/11 16:46:29 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*prototypes*/
static int	ft_isspace(char c);

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	minus;

	result = 0;
	minus = 1;
	i = 0;
	while (ft_isspace(*(nptr + i)))
		i++;
	if (*(nptr + i) == '+' || *(nptr + i) == '-')
	{
		if (*(nptr + i) == '-')
			minus = -1;
		i++;
	}
	while (*(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		result *= 10;
		result += (*(nptr + i) - '0');
		i++;
	}
	if (*(nptr + i))
		return (0);
	return (result * minus);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
