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
		if ((n1 < n3) && (n2 > n3))//OK 1 3 2
			reverse_rotate(lst, "rra\n");
		if ((n1 > n2) && (n2 > n3))//OK 3 2 1
			swap(lst, "sa\n");
		if ((n1 > n2) && (n1 < n3))//OK 2 1 3
			swap(lst, "sa\n");
		if ((n1 > n3) && (n2 > n1))//OK 2 3 1
			reverse_rotate(lst, "rra\n");
		if ((n1 > n3) && (n3 > n2))//OK 3 1 2
			rotate(lst, "ra\n");
	}
}

void	reverse_sort_3(t_list **lst)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = *((int *)(*lst)->content);
	n2 = *((int *)((*lst)->next)->content);
	n3 = *((int *)(((*lst)->next)->next)->content);
	if ((n1 < n2) && (n2 < n3))//OK 1 2 3
		rotate(lst, "rb\n");
	if ((n1 > n3) && (n3 > n2))//OK 3 1 2
		reverse_rotate(lst, "rrb\n");
	if ((n1 < n3) && (n2 > n3))//OK 1 3 2
		rotate(lst, "rb\n");
	if ((n1 > n2) && (n1 < n3))//OK 2 1 3
		reverse_rotate(lst, "rrb\n");
	if ((n1 > n3) && (n2 > n1))//OK 2 3 1
		swap(lst, "sb\n");
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

void	find_largest_push_back(t_list **la, t_list **lb, int len)
{
	int	move_count;
	t_list	*p;

	while (len)
	{
		move_count = 0;
		p = *lb;
		while (*((int *)p->content) != len)
		{
			p = p->next;
			move_count++;
		}
		if (move_count <= (len / 2))
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

/* void	find_largest_smalest_push_back(t_list **la, t_list **lb, int len)
{
	int index[2];
	int move_count[2];
	t_list	*p;

	while (len)
	{
		move_count[0] = 0;
		move_count[1] = 0;
		p = *lb;
		while (*(int *)p->content != len) || (*(int *)p->content) != smallest

	}


}*/

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
	index[1] = *((int *)(p)->content);
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

void	sort_below_10(t_list **la, t_list **lb,int num)
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
		push(la, lb, "pb\n");
		n1++;
		stack_size--;
	}
	if (stack_size == 3)
		sort_3(la, 3);
	while ((*lb) != NULL)
		push(lb, la, "pa\n");
}