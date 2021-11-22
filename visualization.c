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
			a = "-";
		if (lb != NULL)
			b = ft_itoa(*((int *)lb->content));
		else
			b = "-";
		printf("	%s		%s	\n", a, b);
		if (la != NULL)
			la = la->next;
		if (lb != NULL)
			lb = lb->next;
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

int main(int argc, char **argv)
{
	char	*s;
	int		i = 0;
	int		*num;
	t_list	*la;
	t_list	*lb;

	i = 0;
	if (argc < 2)
		return (1);
	num = get_input(argc, argv);
	num = get_index(num);
	la = create_linked_list(num);
	print_stacks(la, lb, num[0]);
	s = malloc(4);
	while (1)
	{
		while (i++ < 4)
			s[i - 1] = '\0';
		i = read(STDIN_FILENO, s, 4);
		s[i] = '\0';
		if (!ft_strncmp(s,"ra\n",3))
			rotate(&la, "ra");
		if (!ft_strncmp(s,"rb\n",3))
			rotate(&lb, "ra");
		if (!ft_strncmp(s,"rr\n",3)){
			rotate(&la, "");
			rotate(&lb, "rr");
		}
		if (!ft_strncmp(s,"rra\n",4)){
			reverse_rotate(&la, "rra");
		}
		if (!ft_strncmp(s,"rrb\n",4))
			reverse_rotate(&lb, "rrb");
		if (!ft_strncmp(s,"rrr\n",4)){
			reverse_rotate(&la, "");
			reverse_rotate(&lb, "rrr");
		}
		if (!ft_strncmp(s,"sa\n",3))
			swap(&la, "sa");
		if (!ft_strncmp(s,"sb\n",3))
			swap(&lb, "sb");
		if (!ft_strncmp(s,"ss\n",3)){
			swap(&la, "");
			swap(&lb, "ss");
		}
		if (!ft_strncmp(s,"pa\n",3))
			push(&lb, &la, "pa");
		if (!ft_strncmp(s,"pb\n",3))
			push(&la, &lb, "pb");
		print_stacks(la, lb, num[0]);
		i = 0;
	}
}
