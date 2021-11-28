#include "push_swap.h" 
#include <stdio.h>

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

void	print_all(void *content)
{
	ft_putnbr_fd(*((int *) content), STDOUT_FILENO);
	ft_putstr_fd(" ", STDOUT_FILENO);
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

void	quick_sort(t_list **la, t_list **lb, int len, int prev_pivot)
{
	int	pivot;
	int pushes;
	
	pushes = 0;
	pivot = prev_pivot + (len / 2);
	if (len < 3)
		pivot = prev_pivot + 1;
	while (pushes < pivot - prev_pivot)
	{
		if (*((int *)(*la)->content) > pivot)
			rotate(la, "ra\n");
		else
		{
			push(la, lb, "pb\n");
			pushes++;
		}
	}
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(pivot, 1);
	ft_putchar_fd('\n', 1);
	if ((len >= 1) && (!check_sort(*la, 0)))
		 quick_sort(la, lb, len / 2, pivot);
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

int main(int argc, char **argv)
{
	char	*s;
	int		*num;
	int		counter = 0;
	int		i = 0;
	t_list	*la;
	t_list	*lb;

	i = 0;
	num = NULL;
	s = NULL;
	lb = NULL;
	if (argc < 2)
		return (1);
	num = get_input(argc, argv);
	num = get_index(num);
	la = create_linked_list(num);
	//ft_lstiter(la, print_all);
	quick_sort(&la, &lb, num[0], 0);
	print_stacks(la, lb, num[0]);
	s = malloc(4);
	
	while (1)
	{
		while (i++ < 4)
			s[i - 1] = '\0';
		i = read(STDIN_FILENO, s, 4);
		s[i] = '\0';
		if (!ft_strncmp(s,"ra\n",3))
			rotate(&la, "");
		if (!ft_strncmp(s,"rb\n",3))
			rotate(&lb, "");
		if (!ft_strncmp(s,"rr\n",3)){
			rotate(&la, "");
			rotate(&lb, "");
		}
		if (!ft_strncmp(s,"rra\n",4)){
			reverse_rotate(&la, "");
		}
		if (!ft_strncmp(s,"rrb\n",4))
			reverse_rotate(&lb, "");
		if (!ft_strncmp(s,"rrr\n",4)){
			reverse_rotate(&la, "");
			reverse_rotate(&lb, "");
		}
		if (!ft_strncmp(s,"sa\n",3))
			swap(&la, "");
		if (!ft_strncmp(s,"sb\n",3))
			swap(&lb, "");
		if (!ft_strncmp(s,"ss\n",3)){
			swap(&la, "");
			swap(&lb, "");
		}
		if (!ft_strncmp(s,"pa\n",3))
			push(&lb, &la, "");
		if (!ft_strncmp(s,"pb\n",3))
			push(&la, &lb, "");
		if (!ft_strncmp(s,"mis\n",4)){
			printf("Operation count - 1:	%i\n", --counter);
		}
		if (!ft_strncmp(s,"end\n",4))
			break;
		else if ((!ft_strncmp(s,"ra\n",3)) || (!ft_strncmp(s,"rb\n",3)) || (!ft_strncmp(s,"rr\n",3)) || (!ft_strncmp(s,"rra\n",4)) 
			|| (!ft_strncmp(s,"rrb\n",4))|| (!ft_strncmp(s,"rrr\n",4)) || (!ft_strncmp(s,"sa\n",3)) || (!ft_strncmp(s,"sb\n",3))
			 || (!ft_strncmp(s,"ss\n",3)) || (!ft_strncmp(s,"pa\n",3)) || (!ft_strncmp(s,"pb\n",3))){
			print_stacks(la, lb, num[0]);
			printf("Operation count:	%i\n", ++counter);
		}
		i = 0;
	}
	return (0);
}
