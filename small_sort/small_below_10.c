/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:14:53 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/10 16:35:27 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sort(t_list *lst, int ret)
{
	t_list	*p;
	int		num1;
	int		num2;

	p = lst;
	while (p->next != NULL)
	{
		num1 = *((int *)(p->content));
		num2 = *((int *)((p->next)->content));
		if (num1 > num2)
			break ;
		p = p->next;
	}
	if (p->next == NULL)
	{
		if (ret == 1)
			exit(EXIT_SUCCESS);
		return (1);
	}
	return (0);
}

void	sort_3(t_list **lst, int num)
{
	int		n1;
	int		n2;
	int		n3;

	if (num == 2)
		swap(lst, "sa");
	else
	{
		n1 = *((int *)(*lst)->content);
		n2 = *((int *)((*lst)->next)->content);
		n3 = *((int *)(((*lst)->next)->next)->content);
		if (((n1 < n3) && (n2 > n3)) || ((n1 > n2) && (n2 > n3)))
			swap(lst, "sa\n");
		if (((n1 < n3) && (n2 > n3)) || ((n1 > n3) && (n3 > n2)))
			rotate(lst, "ra\n");
		if (((n1 > n2) && (n2 > n3)) || ((n1 > n3) && (n2 > n1)))
			reverse_rotate(lst, "rra\n");
		if ((n1 > n2) && (n1 < n3))
			swap(lst, "sa\n");
	}
}

int	*get_index(int *num)
{
	int	i;
	int	j;
	int	smaller;
	int	*indexx;

	indexx = ft_calloc(num[0] + 1, sizeof(int));
	i = 0;
	j = 1;
	smaller = 1;
	indexx[0] = num[0];
	while (i++ < num[0])
	{
		j = 0;
		while (j++ < num[0])
		{
			if (num[j] < num[i])
				smaller++;
		}
		indexx[i] = smaller;
		smaller = 1;
	}
	free(num);
	return (indexx);
}

static void	sort_into_b(t_list **la, t_list **lb, int n, int stack_size)
{
	t_list	*p;
	int		move_count;

	move_count = 0;
	p = *la;
	while (*((int *)p->content) != n)
	{
		p = p->next;
		move_count++;
	}
	if (move_count <= (stack_size / 2))
	{
		while (*((int *)(*la)->content) != n)
			rotate(la, "ra\n");
	}
	else
	{
		while (*((int *)(*la)->content) != n)
			reverse_rotate(la, "rra\n");
	}
	push(la, lb, "pb\n");
}

void	sort_below_10(t_list **la, t_list **lb, int num)
{
	int		n1;
	int		stack_size;

	n1 = 1;
	stack_size = num;
	while (stack_size > 3)
	{
		if (check_sort(*la, 0))
			break ;
		sort_into_b(la, lb, n1, stack_size);
		n1++;
		stack_size--;
	}
	if (stack_size == 3)
		sort_3(la, 3);
	while ((*lb) != NULL)
		push(lb, la, "pa\n");
}
