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
	s = malloc(4);
	while (1)
	{
		while (i++ < 4)
			s[i - 1] = '\0';
		i = read(STDIN_FILENO, s, 3);
		s[i] = '\0';
		ft_putstr_fd(s,1);
		i = 0;
	}
}

void print_stacks(t_list *la, t_list *lb, int num)
{
	t_list	*p1;
	t_list	*pb;

	while (num--)
	{
		printf("	%i		%i	\n", *((int *)la->content), *((int *)lb->content));
		if (la != NULL)
			la = la->next;
		if (lb != NULL)
			lb = la->next;
		
	}
}