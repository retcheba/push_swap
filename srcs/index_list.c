/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:24 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/21 16:38:36 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index_list2(t_stack *list, unsigned int n, unsigned int i)
{
	t_stack			*tmp;
	t_stack			*begin;
	int				min;
	int				old_min;

	old_min = -2147483648;
	begin = list;
	while (i < n)
	{
		list = begin;
		min = 2147483647;
		while (list)
		{
			if (list->nb > old_min && list->nb < min
				&& (list->nb != 2147483647 && list->nb != -2147483648))
			{
				min = list->nb;
				tmp = list;
			}
			list = list->next;
		}
		old_min = min;
		tmp->index = i + 1;
		i++;
	}
}

void	index_list(t_stack	*list, unsigned int n)
{
	t_stack			*begin;
	unsigned int	i;

	begin = list;
	i = 0;
	while (list)
	{
		if (list->nb == 2147483647)
		{
			list->index = n;
			n--;
		}
		else if (list->nb == -2147483648)
		{
			list->index = 1;
			i++;
		}
		list = list->next;
	}
	list = begin;
	index_list2(list, n, i);
}
