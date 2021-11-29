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
		if (move_count <= len/2)
		{
			while (*((int *)(*lb)->content) != len)
				rotate(lb, "Brb\n");
		}
		else
		{
			while (*((int *)(*lb)->content) != len)
				reverse_rotate(lb, "Brrb\n");
		}
		push(lb, la, "Bpa\n");
		len--;
	}
}