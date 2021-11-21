/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:25:33 by oipadeol          #+#    #+#             */
/*   Updated: 2021/11/20 19:27:47 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_b(t_list **la, t_list **lb, char *s)
{
	t_list	*temp;

	if (*la != NULL)
	{
		temp = (*la)->next;
		ft_lstadd_front(lb, *la);			
		*la = temp;
		write(STDOUT_FILENO, s, ft_strlen(s));
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	swap_sa_sb_ss(t_list **lst, char *s)
{
	t_list	*temp;

	if ((*lst != NULL) && ((*lst)->next != NULL))
	{
		temp = (*lst)->next;
		(*lst)->next = temp->next;
		temp->next = *lst;
		*lst = temp;
		write(STDOUT_FILENO, s, ft_strlen(s));
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	rotate_ra_rb_rr(t_list **lst, char *s)
{
	t_list	*temp;
	t_list	*p;

	if ((*lst != NULL) && ((*lst)->next != NULL))
	{
		temp = (*lst)->next;
		p = *lst;
		while (p->next != NULL)
			p = p->next;
		p->next = *lst;
		(*lst)->next = NULL;
		*lst = temp;
		write(STDOUT_FILENO, s, ft_strlen(s));
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	reverse_rotate_rra_rrb_rrr(t_list **lst, char *s)
{
	t_list	*p1;
	t_list	*p2;

	if ((*lst != NULL) && ((*lst)->next != NULL))
	{
		p1 = *lst;
		while (p1->next != NULL)
		{
			p2 = p1->next;
			if (p2->next == NULL)
			{
				p2->next = *lst;
				p1->next = NULL;
				*lst = p2;
				break;
			}
			p1 = p1->next;
		}
	}
	write(STDOUT_FILENO, s, ft_strlen(s));
	write(STDOUT_FILENO, "\n", 1);
}

