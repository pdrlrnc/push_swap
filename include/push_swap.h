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
#include "printf.h"
#include "clean_list.h"
#include <unistd.h>
#include <limits.h>

int	ft_start_stack(t_list *stack, char *argc);
int	get_min_index(char c);
int	get_max_index(void);
t_list	**stack_factory(char c);
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
int	is_ordered(char c);
void	add_move(char *move);
void	radix(void);
int	string_args(char **argc);
int	value_args(int argv, char **argc);
int	add_to_stack(char *argc);
int	normalize_lst(void);
void	bubble_sort_arr(int *arr, int size);

#endif
