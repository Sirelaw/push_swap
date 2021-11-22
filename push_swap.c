/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:47:14 by oipadeol          #+#    #+#             */
/*   Updated: 2021/11/22 19:44:36 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_linked_list(int *arr)
{
	int		i;
	t_list	*lst;

	i = arr[0];
	lst = ft_lstnew((int *) &arr[i]);
	while (--i > 0)
		ft_lstadd_front(&lst, ft_lstnew((int *) &arr[i]));
	return (lst);
}

void	print_all(void *content)
{
	ft_putnbr_fd(*((int *) content), STDIN_FILENO);
	ft_putstr_fd(" ", STDIN_FILENO);
}

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
			break;
		p = p->next;
	}
	if (p->next == NULL)
	{
		// ft_lstiter(lst, print_all);
		// ft_putchar_fd('\n', 1);
		if (ret == 1)
			exit(EXIT_SUCCESS);
		return (1);
	}
	return (0);
}



int	*get_index(int *num)
{
	int i;
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

void	sort_3(t_list **lst, int num, int ret)
{
	int		n1;
	int		n2;
	int		n3;
	
	if (num == 2)
	{
		swap(lst, "sa");
		check_sort(*lst, ret);
	}
	while (!check_sort(*lst, ret))
	{
		n1 = *((int *)(*lst)->content);
		n2 = *((int *)((*lst)->next)->content);
		n3 = *((int *)(((*lst)->next)->next)->content);
		if ((n1 < n3) && (n2 > n3))//OK 1 3 2
			reverse_rotate(lst, "rra\n");
		if ((n1 > n2) && (n1 < n3))//OK 2 1 3
			swap(lst, "sa\n");
		if ((n1 > n2) && (n2 > n3))//OK 3 2 1
			swap(lst, "sa\n");
		if ((n1 > n3) && (n2 > n1))//OK 2 3 1
			reverse_rotate(lst, "rra\n");
		if ((n1 > n3) && (n3 > n2))//OK 3 1 2
			rotate(lst, "ra\n");
	}
}

void	sort_5(t_list **la, t_list **lb,int num)
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
		if (move_count <= stack_size/2)
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
	ft_putchar_fd('\n', 1);
	check_sort(*la, 1);
}

int	main(int argc, char **argv)
{
	int		*num;
	int		i;
	t_list	*la;
	t_list	*lb;

	i = 0;
	if (argc < 2)
		return (1);
	num = get_input(argc, argv);
	num = get_index(num);
	la = create_linked_list(num);
	if (check_sort(la, 1))
		return (0);
	ft_lstiter(la, print_all);
	ft_putchar_fd('\n', 1);
	if (num[0] <= 3)
		sort_3(&la, num[0], 1);
	else
		sort_5(&la, &lb, num[0]);
	// else if (num[0] <= 7)
	// 	sort_7(&la, num[0]);
	// else
	// 	sort_5(&la, num[0]);
	// ft_lstiter(la, print_all);
	// ft_putchar_fd('\n', 1);
	// ft_lstiter(lb, print_all);
	// ft_putchar_fd('\n', 1);
	// ft_lstiter(la, print_all);
	free(num);
	return (0);
}

