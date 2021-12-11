/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:17:25 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/11 18:05:42 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	do_atoi(const char *str, int checker)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[0] == '\0')
		return (0);
	while (ft_strchr(" \n\t\v\f\r", str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	while ((str[i] > 47) && (str[i] < 58))
	{
		num = (num * 10) + (str[i] - 48);
		if ((num > INT_MAX) || ((num * sign) < INT_MIN))
			ft_error(checker);
		i++;
	}
	return (sign * num);
}

static int	check_duplic(int *arr, int n, int checker)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 1;
		while ((i + j) < n)
		{
			if (arr[i] == arr[i + j++])
				ft_error(checker);
		}
		i++;
	}
	return (0);
}

static void	digit_check(char *s, int checker)
{
	int	i;

	i = 0;
	while (s[i++] != '\0')
	{
		if ((!ft_isdigit(s[i - 1])) && (!(((s[i - 1] == '-')
						|| (s[i - 1] == '+')) && (i - 1 == 0))))
			ft_error(checker);
	}
	i = 0;
}

static int	*convert_to_array(char *s, int checker)
{
	int		i;
	int		j;
	char	**ch;
	int		*arr;

	i = 0;
	j = 0;
	ch = ft_split(s, ' ');
	if (ch == NULL)
		return (NULL);
	while (ch[i])
		i++;
	arr = (int *) ft_calloc(i + 1, sizeof(int));
	if (arr == NULL)
		return (NULL);
	arr[0] = i;
	i = 0;
	while (ch[i++])
	{
		digit_check(ch[i - 1], checker);
		arr[i] = do_atoi(ch[i - 1], checker);
		free(ch[i - 1]);
	}
	free(ch);
	return (arr);
}

int	*get_input(int argc, char **argv, int checker)
{
	int	i;
	int	*num;

	i = 0;
	if (argc == 2)
		num = convert_to_array(argv[1], checker);
	else
	{
		num = (int *) ft_calloc(argc, sizeof(int *));
		if (num == NULL)
			return (0);
		num[0] = argc - 1;
		while (i++ < num[0])
		{
			digit_check((char *)argv[i], checker);
			num[i] = do_atoi((char *) argv[i], checker);
		}
	}
	check_duplic(&(num[1]), num[0], checker);
	return (num);
}
