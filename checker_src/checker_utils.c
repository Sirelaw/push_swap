/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:32:03 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/11 19:58:19 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	good_operation(char *s)
{
	if ((!ft_strncmp(s, "ra\n", 3)) || (!ft_strncmp(s, "rb\n", 3)))
		return (1);
	if ((!ft_strncmp(s, "rr\n", 3)) || (!ft_strncmp(s, "rra\n", 4)))
		return (1);
	if ((!ft_strncmp(s, "rrb\n", 4)) || (!ft_strncmp(s, "rrr\n", 4)))
		return (1);
	if ((!ft_strncmp(s, "sa\n", 3)) || (!ft_strncmp(s, "sb\n", 3)))
		return (1);
	if ((!ft_strncmp(s, "ss\n", 3)) || (!ft_strncmp(s, "pa\n", 3)))
		return (1);
	if (!ft_strncmp(s, "pb\n", 3))
		return (1);
	else
		return (0);
}

static void	perform_1(t_list **la, t_list **lb, char *s)
{
	if (!ft_strncmp(s, "ra\n", 3))
		rotate(la, "");
	if (!ft_strncmp(s, "rb\n", 3))
		rotate(lb, "");
	if (!ft_strncmp(s, "rr\n", 3))
		rotate(la, "");
	if (!ft_strncmp(s, "rr\n", 3))
		rotate(lb, "");
	if (!ft_strncmp(s, "rra\n", 4))
		reverse_rotate(la, "");
	if (!ft_strncmp(s, "rrb\n", 4))
		reverse_rotate(lb, "");
	if (!ft_strncmp(s, "rrr\n", 4))
		reverse_rotate(la, "");
	if (!ft_strncmp(s, "rrr\n", 4))
		reverse_rotate(lb, "");
}

static void	perform_2(t_list **la, t_list **lb, char *s)
{
	if (!ft_strncmp(s, "sa\n", 3))
		swap(la, "");
	if (!ft_strncmp(s, "sb\n", 3))
		swap(lb, "");
	if (!ft_strncmp(s, "ss\n", 3))
		swap(la, "");
	if (!ft_strncmp(s, "ss\n", 3))
		swap(lb, "");
	if (!ft_strncmp(s, "pa\n", 3))
		push(lb, la, "");
	if (!ft_strncmp(s, "pb\n", 3))
		push(la, lb, "");
}

void	perform_operations_on_list(t_list **la, t_list **lb)
{
	char	*s;

	s = get_next_line_buf_1(STDIN_FILENO);
	while (s)
	{
		if (good_operation(s))
			perform_1(la, lb, s);
		if (good_operation(s))
			perform_2(la, lb, s);
		if (!good_operation(s))
			write(STDOUT_FILENO, "KO: Unknown operation\n", 2);
		if (!good_operation(s))
			exit(1);
		s = get_next_line_buf_1(STDIN_FILENO);
	}
}
