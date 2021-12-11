/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:28:51 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/11 19:46:30 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_join(char **ret, char c)
{
	int		i;
	char	*temp;

	i = 0;
	if (*ret == NULL)
	{
		*ret = (char *) malloc(1);
		(*ret)[0] = '\0';
	}
	while ((*ret)[i])
		i++;
	temp = (char *) malloc(i + 2);
	temp[i + 1] = '\0';
	i = 0;
	while ((*ret)[i++])
		temp[i - 1] = (*ret)[i - 1];
	temp[i - 1] = c;
	free(*ret);
	*ret = temp;
	if (c == '\n')
		return (1);
	else
		return (0);
}

char	*get_next_line_buf_1(int fd)
{
	char	*ret;
	char	temp[1];
	int		i;

	ret = NULL;
	*temp = '\0';
	i = 1;
	while (i)
	{
		i = 0;
		if (ret == NULL)
		{
			ret = (char *) malloc(1);
			ret[0] = '\0';
		}
		i = read(fd, temp, 1);
		if (i <= 0)
			return (NULL);
		if (ft_join(&ret, *temp))
			return (ret);
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	char	*s;
	int		*num;
	t_list	*la;
	t_list	*lb;

	num = NULL;
	s = NULL;
	lb = NULL;
	if (argc < 2)
		return (1);
	num = get_input(argc, argv, 1);
	num = get_index(num);
	la = create_linked_list(num);
	if (check_sort(la, 0))
		free_stack_array_exit(&la, &lb, &num, 1);
	perform_operations_on_list(&la, &lb);
	if (check_sort(la, 0))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack_array_exit(&la, &lb, &num, 0);
	return (0);
}