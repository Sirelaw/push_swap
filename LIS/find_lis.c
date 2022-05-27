/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 01:55:46 by oipadeol          #+#    #+#             */
/*   Updated: 2022/05/27 11:35:33 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	largest(int *arr, int size)
{
	int	i;
	int	j;
	int	max;

	max = arr[0];
	i = 0;
	j = 0;
	while (i < size)
	{
		if (max < arr[i])
		{
			max = arr[i];
			j = i;
		}
		i++;
	}
	return (j);
}

void	lis_value(int **arr, int *num, int **actual, int loc)
{
	int	max;
	int	i;

	max = 1;
	i = 1;
	while ((*arr)[i + loc] != -1)
	{
		if ((num[loc + i + 1] > num[loc + 1]) && (max <= (*arr)[i + loc]))
		{
			max = 1 + (*arr)[i + loc];
			(*actual)[loc] = num[loc + i + 1];
		}
		i++;
	}
	(*arr)[loc] = max;
}

int	*lis_list(int i, int *num, int *actual, int *arr)
{
	int	*lis;
	int	next;
	int	j;

	j = 0;
	lis = (int *)ft_calloc(arr[i] + 1, sizeof(int));
	lis[arr[i]] = -1;
	lis[j] = num[i + 1];
	next = actual[i];
	while (arr[i] != -1)
	{
		if (num[i + 1] == next)
		{
			lis[++j] = next;
			next = actual[i];
		}
		i++;
	}
	return (lis);
}

int	*find_lis(int *num, int size)
{
	int	i;
	int	*arr;
	int	*actual;
	int	loc;
	int	*ret;

	i = 0;
	loc = size;
	arr = (int *)ft_calloc(size + 1, sizeof(int));
	if (arr == NULL)
		return (0);
	actual = (int *)ft_calloc(size + 1, sizeof(int));
	if (arr == NULL)
		return (0);
	arr[size] = -1;
	while (loc--)
	{
		arr[loc] = 1;
		lis_value(&arr, num, &actual, loc);
	}
	i = largest(arr, size);
	ret = lis_list(i, num, actual, arr);
	free(arr);
	free(actual);
	return (ret);
}
