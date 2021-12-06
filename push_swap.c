/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:47:14 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/06 16:46:53 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			moves[1] = len - pushes - moves[1] /* - ((len / n) * (i - 1)) */;
			// ft_putnbr_fd(moves[1], 1);
			// ft_putstr_fd("\n", 1);
			if (moves[0] <= moves[1])
			{
				while (*((int *)(*la)->content) > part)
				{
					if ((*lb != NULL) && (*((int *)(*lb)->content) > index[0]))
					{
						rotate(la, "");
						rotate(lb, "rr\n");
					}
					else
						rotate(la, "ra\n");
				}
			}
			else
			{
				while (*((int *)(*la)->content) > part)
				{
					if ((*lb != NULL) && (*((int *)(*lb)->content) < index[0]))
					{
						reverse_rotate(la, "");
						reverse_rotate(lb, "rrr\n");
					}
					else
						reverse_rotate(la, "rra\n");
				}
			}
			push(la, lb, "pb\n");
			pushes++;
		}
		i++;
		// if (i == n)
		// 	last_n_divide(la, lb, len, n);
	}
	// ft_lstiter(*la, print_all);
	// ft_putstr_fd("\n", 2);
	while ((*la) != NULL)
		push(la, lb, "pb\n");
	find_largest_push_back(la, lb, len);
}

// void n_divider_sort_correct(t_list **la, t_list **lb, int len, int n)
// {
// 	int i;
// 	int	part;
// 	int pushes;
// 	int	moves[2];
// 	int index[2];
// 	int min = len;
// 	int max = 1;
	
// 	i = 1;
// 	while (i <= n)
// 	{
// 		pushes = 0;
// 		part = (len / n) * i;
// 		while (pushes < (len / n))
// 		{
// 			search_best_move(*la, part, moves, index);
// 			moves[1] = len - pushes - moves[1] - ((len / n) * (i - 1) );
// 			// ft_putnbr_fd(moves[1], 1);
// 			// ft_putstr_fd("\n", 1);
// 			if (moves[0] <= moves[1])
// 			{
// 				while (*((int *)(*la)->content) > part)
// 				{
// 					if (((*lb != NULL) && (*((int *)(*lb)->content) > index[0])) || (index[0] < min))
// 					{
// 						rotate(la, "");
// 						rotate(lb, "rr\n");
// 						// if (*((int *)(*la)->content) < part)
// 						// {
// 						// 		while (((*lb != NULL) && (*((int *)(*lb)->content) > index[0])) && !(index[0] < min))
// 						// 			rotate(lb, "rb\n");
// 						// 		if (index[0] < min)
// 						// 		{
// 						// 			while (B_HEAD_CONTENT != max)
// 						// 				rotate(lb, "rb\n");
// 						// 		}
// 						// }
// 					}
// 					else
// 						rotate(la, "ra\n");
// 				}
// 			}
// 			else
// 			{
// 				while (*((int *)(*la)->content) > part)
// 				{
// 					if ((*lb != NULL) && (*((int *)(*lb)->content) < index[1]) && (B_LAST < index[1]) && (B_LAST != min))
// 					{
// 						reverse_rotate(la, "");
// 						reverse_rotate(lb, "rrr\n");
// 						if (*((int *)(*la)->content) < part)
// 						{
// 							while ((*lb != NULL) && (*((int *)(*lb)->content) < index[1]) && (B_LAST < index[1]) && (B_LAST != min))
// 								reverse_rotate(lb, "rrb\n");
								
// 						}
// 					}
// 					else
// 						reverse_rotate(la, "rra\n");
// 				}
// 			}
// 			push(la, lb, "pb\n");
// 			if (B_HEAD_CONTENT < min)
// 				min = B_HEAD_CONTENT;
// 			if (B_HEAD_CONTENT > max)
// 				max = B_HEAD_CONTENT;
// 			pushes++;
// 		}
// 		i++;
// 		// if (i == n)
// 		// 	last_n_divide(la, lb, len, n);
// 	}
// 	// ft_lstiter(*la, print_all);
// 	// ft_putstr_fd("\n", 2);
// 	while ((*la) != NULL)
// 		push(la, lb, "pb\n");
// 	find_largest_push_back(la, lb, len);
// }


void	halves_seek(t_list **la, t_list **lb, int len, int prev_pivot)
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
		halves_seek(la, lb, len, pivot);
}

void	sort_n_halves(t_list **la, t_list **lb,int num)
{
	t_list	*p;
	int		n1;
	int		move_count;

	halves_seek(la, lb, num, 0);
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
}

void	free_stack_array_exit(t_list **la, t_list **lb, int **num, int exit_stat)
{
	int	i;
	t_list	*p;
	t_list	*temp;

	i = 0;
	while (i++ < 2)
	{
		if (i - 1 == 0)
			p = *la;
		else if (i - 1 == 1)
			p = *lb;
		while (p != NULL)
		{
			temp = p->next;
			free(p);
			p = temp;
		}
	}
	free(*num);
	if (exit_stat)
		exit(exit_stat);
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
	ft_lstiter(la, print_all);
	ft_putchar_fd('\n', STDOUT_FILENO);
	if (check_sort(la, 1))
		free_stack_array_exit(&la, &lb, &num, 1);
	if (num[0] <= 3)
		sort_3(&la, num[0]);
	else if (num[0] <= 10)
		sort_below_10(&la, &lb, num[0]);
	else
		// sort_n_halves(&la, &lb, num[0]);
		wheel_algo(&la, &lb);
		// n_divider_sort(&la, &lb, num[0], 11);
		// n_divider_sort_correct(&la, &lb, num[0], 11);
		//ft_lstiter(la, print_all);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_lstiter(la, print_all);
	free_stack_array_exit(&la, &lb, &num, 0);
	return (0);
}

