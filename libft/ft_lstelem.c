/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:24:32 by oipadeol          #+#    #+#             */
/*   Updated: 2021/11/09 21:25:25 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstelem(t_list *lst, int n)
{
	t_list	*p;
	int		i;

	i = 0;
	p = lst;
	while ((p != NULL) && (i < n))
	{
		p = p->next;
		i++;
	}
	if (i == n)
		return (p->content);
	else
		return (NULL);
}
