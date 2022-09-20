/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:24 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/18 22:52:29 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_list(t_stack	*list, unsigned int n)
{
	t_stack				*begin;
	t_stack				*tmp;
	unsigned int		i = 0;
	int					min = 2147483647;
	int					old_min = -2147483648;

	begin = list;
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
	while (i < n)
	{
		list = begin;
		min = 2147483647;
		while (list)
		{
			if (list->nb > old_min && list->nb < min
				&& (list->nb != 2147483647 && list->nb !=- 2147483648))
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
