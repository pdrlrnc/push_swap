/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:05:54 by pedde-so          #+#    #+#             */
/*   Updated: 2025/04/11 16:31:41 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*result;

	i = 0;
	while (*(s + i))
		i++;
	result = malloc(i + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(result + i) = *(s + i);
		i++;
	}
	*(result + i) = '\0';
	return (result);
}
