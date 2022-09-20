/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_DIY.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:32:27 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/20 01:53:40 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *algo_DIY(t_stack *list_a, t_stack *list_b, unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (i < n - 2)
	{
		while (list_a->index != i)
			list_a = ft_ra(list_a);
		ft_printf("pb\n");
		list_b = add_link_top(list_b, list_a->nb, list_a->index);
		list_a = ft_next(list_a);
		i++;
	}
	list_a = algo_for_3(list_a, n);
	i = 1;
	while (i < n - 2)
	{
		ft_printf("pa\n");
		list_a = add_link_top(list_a, list_b->nb, list_b->index);
		list_b = ft_next(list_b);
		i++;
	}
	list_b = NULL;
	return (list_a);
}
