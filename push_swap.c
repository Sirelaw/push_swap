/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:47:14 by oipadeol          #+#    #+#             */
/*   Updated: 2021/11/30 00:44:43 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_best_move(t_list *la, int part, int moves[2], int index[2])
{
	t_list	*p;
	int		temp;

	temp = 0;
	moves[0] = 0;
	moves[1] = 0;
	p = la;
	while (*((int *)(p)->content) > part)
	{
		p = p->next;
		(moves[0])++;
	}
	index[0] = *((int *)(p)->content);
	p = la;
	while (p->next != NULL)
	{
		p = p->next;
		temp++;
		if (*((int *)(p)->content) <= part)
		{
			moves[1] = temp;
			index[1] = *((int *)(p)->content);
		}
	}
}

void n_divider_sort(t_list **la, t_list **lb, int len, int n)
{
	int i;
	int	part;
	int pushes;
	int	moves[2];
	int index[2];
	
	i = 1;
	while (i <= n)
	{
		pushes = 0;
		part = (len / n) * i;
		while (pushes < (len / n))
		{
			search_best_move(*la, part, moves, index);
			moves[1] = len - pushes - moves[1];
			if (moves[0] <= moves[1])
			{
				while (*((int *)(*la)->content) > part)
				{
					if ((*lb != NULL) && (*((int *)(*lb)->content) > index[0]))
					{
						rotate(la, "");
						rotate(lb, "Arr\n");
					}
					else
						rotate(la, "Ara\n");
				}
			}
			else
			{
				while (*((int *)(*la)->content) > part)
				{
					if ((*lb != NULL) && (*((int *)(*lb)->content) < index[0]))
					{
						reverse_rotate(la, "");
						reverse_rotate(lb, "Arrr\n");
					}
					else
						reverse_rotate(la, "Arra\n");
				}
			}
			push(la, lb, "Apb\n");
			pushes++;
		}
		i++;
	}
	// ft_lstiter(*la, print_all);
	// ft_putstr_fd("\n", 2);
	while ((*la) != NULL)
		push(la, lb, "Apb\n");
	
	find_largest_push_back(la, lb, len);
}



void	halves_sort(t_list **la, t_list **lb, int len, int prev_pivot)
{
	int	pivot;
	int pushes;

	pushes = 0;
	pivot = prev_pivot + (len / 2);
	while ((pushes < pivot - prev_pivot))
	{
		if (*((int *)(*la)->content) > pivot)
			rotate(la, "ra\n");
		else
		{
			push(la, lb, "pb\n");
			pushes++;
			len--;
			if (len == 2)
			{
				if (*((int *)(*la)->content) > *((int *)(*la)->next->content))
					swap(la, "sa\n");
				break;
			}
		}
	}
	if (len != 2)
		halves_sort(la, lb, len, pivot);
}

void	sort_n_halves(t_list **la, t_list **lb,int num)
{
	t_list	*p;
	int		n1;
	int		move_count;

	halves_sort(la, lb, num, 0);
	n1 = *((int *)(*la)->content) - 1;
	while (n1)
	{
		move_count = 0;
		p = *lb;
		while (*((int *)p->content) != n1)
		{
			p = p->next;
			move_count++;
		}
		if (move_count <= n1/2)
		{
			while (*((int *)(*lb)->content) != n1)
				rotate(lb, "rb\n");
		}
		else
		{
			while (*((int *)(*lb)->content) != n1)
				reverse_rotate(lb, "rrb\n");
		}
		push(lb, la, "pa\n");
		n1--;
	}
	ft_lstiter(*la, print_all);
	// ft_lstiter(*lb, print_all);
}

void	sort_below_8(t_list **la, t_list **lb,int num)
{
	t_list	*p;
	int		n1;
	int		stack_size;
	int		move_count;
	
	n1 = 1;
	stack_size = num;
	while (stack_size > 3)
	{
		if (check_sort(*la, 0))
			break;
		move_count = 0;
		p = *la;
		while (*((int *)p->content) != n1)
		{
			p = p->next;
			move_count++;
		}
		if (move_count <= (stack_size/2))
		{
			while (*((int *)(*la)->content) != n1)
				rotate(la, "ra\n");
		}
		else
		{
			while (*((int *)(*la)->content) != n1)
				reverse_rotate(la, "rra\n");
		}
		if (check_sort(*la, 0))
			break;
		push(la, lb, "pb\n");
		n1++;
		stack_size--;
	}
	if (stack_size == 3)
		sort_3(la, 3, 0);
	while ((*lb) != NULL)
		push(lb, la, "pa\n");
	ft_lstiter(*la, print_all);
}

int	main(int argc, char **argv)
{
	int		*num;
	int		i;
	t_list	*la;
	t_list	*lb;

	lb = NULL;
	la = NULL;
	i = 0;
	if (argc < 2)
		return (1);
	num = get_input(argc, argv);
	num = get_index(num);
	la = create_linked_list(num);
	// ft_lstiter(la, print_all);
	// ft_putstr_fd("\n", 2);
	if (check_sort(la, 1))
		return (0);
	if (num[0] <= 3)
		sort_3(&la, num[0], 1);
	else
		// sort_below_8(&la, &lb, num[0]);
		//sort_n_halves(&la, &lb, num[0]);
		n_divider_sort(&la, &lb, num[0], 4);
	ft_lstiter(la, print_all);
	free(num);
	return (0);
}
