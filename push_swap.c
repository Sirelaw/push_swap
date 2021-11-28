/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:47:14 by oipadeol          #+#    #+#             */
/*   Updated: 2021/11/28 22:48:08 by oipadeol         ###   ########.fr       */
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
	ft_putnbr_fd(*((int *) content), STDERR_FILENO);
	ft_putstr_fd(" ", STDERR_FILENO);
}

void print_stacks(t_list *la, t_list *lb, int num)
{
	t_list	*p1;
	t_list	*pb;
	char	*a;
	char	*b;

	while (num--)
	{
		if (la != NULL)
			a = ft_itoa(*((int *)la->content));
		else
			a = "___";
		if (lb != NULL)
			b = ft_itoa(*((int *)lb->content));
		else
			b = "___";
		printf("	|%03s|		|%03s|	\n", a, b);
		if (la != NULL)
			la = la->next;
		if (lb != NULL)
			lb = lb->next;
	}
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
		if (ret == 1)
			exit(EXIT_SUCCESS);
		return (1);
	}
	return (0);
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


void n_divider_sort(t_list **la, t_list **lb, int len, int n)
{
	int i;
	int	part;
	int pushes;
	int move_count;
	t_list	*p;
	
	i = 1;
	while (i <= n)
	{
		pushes = 0;
		part = (len / n) * i;
		// ft_putnbr_fd(part, 1);
		// ft_putstr_fd("\n", 1);
		while (pushes < (len / n))
		{
			if (*((int *)(*la)->content) > part)
				rotate(la, "ra\n");
			else
			{
				push(la, lb, "pb\n");
				pushes++;
			}
		}
		i++;
	}
	while ((*la) != NULL)
		push(la, lb, "pb\n");
	while (len)
	{
		move_count = 0;
		p = *lb;
		while (*((int *)p->content) != len)
		{
			p = p->next;
			move_count++;
		}
		if (move_count <= len/2)
		{
			while (*((int *)(*lb)->content) != len)
				rotate(lb, "rb\n");
		}
		else
		{
			while (*((int *)(*lb)->content) != len)
				reverse_rotate(lb, "rrb\n");
		}
		push(lb, la, "pa\n");
		len--;
	}
}

void	quick_sort(t_list **la, t_list **lb, int len, int prev_pivot)
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
		quick_sort(la, lb, len, pivot);
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

void	sort_5_quick(t_list **la, t_list **lb,int num)
{
	t_list	*p;
	int		n1;
	int		move_count;

	quick_sort(la, lb, num, 0);
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

void print_stack(t_list *la)
{
	t_list	*p1;
	char	*a;

	p1 = la;
	while (la->next != p1)
	{
		a = ft_itoa(*((int *)la->content));
		printf("	|%3s|\n", a);
		la = la->next;
	}
	a = ft_itoa(*((int *)la->content));
	printf("	|%3s|\n", a);
	la->next =  NULL;
}


int	get_max(int *num, int len)
{
	int	i;
	int max;

	i = 0;
	max = 0;
	while (i++ < len)
	{
		if (max < num[i - 1])
			max = num[i - 1];
	}
	return (max);
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
	// find_lis(la, num[0]);
	//ft_lstiter(la, print_all);
	if (check_sort(la, 1))
		return (0);
	if (num[0] <= 3)
		sort_3(&la, num[0], 1);
	else
		// sort_5(&la, &lb, num[0]);
		//sort_5_quick(&la, &lb, num[0]);
		n_divider_sort(&la, &lb, num[0], 6);
	// else if (num[0] <= 7)
	// 	sort_7(&la, num[0]);
	// else
	// 	sort_5(&la, num[0]);
	//ft_lstiter(la, print_all);
	// ft_putchar_fd('\n', 1);
	// ft_lstiter(lb, print_all);
	// ft_putchar_fd('\n', 1);
	ft_lstiter(la, print_all);
	free(num);
	return (0);
}

