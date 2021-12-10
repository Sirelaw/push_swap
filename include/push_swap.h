/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:14:38 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/10 15:29:17 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>

int		smallest(int *arr, int size);
int		smaller(int n1, int n2);
int		bigger(int n1, int n2);
void	push(t_list **la, t_list **lb, char *s);
void	swap(t_list **lst, char *s);
void	rotate_la_to_min(t_list **la);
void	rotate(t_list **lst, char *s);
void	reverse_rotate(t_list **lst, char *s);
int		*get_input(int argc, char **argv);
void	ft_error(void);
void	rotate_both(t_list **la, t_list **lb, int n);
void	reverse_rotate_both(t_list **la, t_list **lb, int n);
void	rotate_stack_b(t_list **lb, int move);
void	rotate_stack_a(t_list **la, int move);
int		move_both(t_list **la, t_list **lb, int move_a, int move_b);
void	move_stacks(t_list **la, t_list **lb, t_list *p, int min_max[2]);
// Finds the right positon to insert index in already sorted list lst 
int		right_insert(t_list *lst, int min_max[2], int index);
int		check_sort(t_list *lst, int ret);
void	sort_3(t_list **lst, int num);
int		*get_index(int *num);
void	sort_below_10(t_list **la, t_list **lb, int num);
void	cost_algo(t_list **la, t_list **lb, int *lis);
int		*find_lis(int *num, int size);
int		best_rot(t_list *la, t_list *lb, int move_a, int move_b);
int		best_rot_type(t_list *la, t_list *lb, int move_a, int move_b);

#endif