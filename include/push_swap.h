/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:40:30 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/28 15:40:31 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <unistd.h>
#include <limits.h>

int	ft_start_stack(t_list *stack, char *argc);
int	ft_isspace(char c);
int	ft_check_if_zero(char *str);
int	get_min_index(char c);
t_list	**stack_factory(char c);
int	ft_create_stack(char *argc);
int	swap_a(void);
int	swap_b(void);
int	ss(void);
int	push_a(void);
int	push_b(void);
int	rotate_a(void);
int	rotate_b(void);
int	rr(void);
int	rra(void);
int	rrb(void);
int	rrr(void);
void	choose_algorithm(int elements);
void	hardcoded_2(void);
void	hardcoded_3(void);
void	hardcoded_4(void);
void	hardcoded_5(void);
int	ft_input_is_valid(void);
void	bubble_sort_cpy(void);
void	chunked_insertion_sort(void);
int	*normalize_input(void);

#endif
