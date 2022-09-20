/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:32:27 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/20 00:37:23 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *algo_for_3(t_stack *list, unsigned int n)
{
	if (list->index == (n - 2) && list->next->index == n
		&& list->next->next->index == (n - 1))
	{
		list = ft_sa(list);
		list = ft_ra(list);
	}
	else if (list->index == (n - 1) && list->next->index == (n - 2)
		&& list->next->next->index == n)
		list = ft_sa(list);
	else if (list->index == (n - 1) && list->next->index == n
		&& list->next->next->index == (n - 2))
	{
		list = ft_ra(list);
		list = ft_ra(list);
	}
	else if (list->index == n && list->next->index == (n - 1)
		&& list->next->next->index == (n - 2))
	{
		list = ft_ra(list);
		list = ft_sa(list);
	}
	else if (list->index == n && list->next->index == (n - 2)
		&& list->next->next->index == (n - 1))
		list = ft_ra(list);
	return (list);
}
