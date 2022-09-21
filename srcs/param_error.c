/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:09:53 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/20 16:09:25 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_duplicates(t_stack *list_a, t_stack *list_b)
{
	t_stack	*begin;
	int		count;

	count = 0;
	begin = list_b;
	while (list_a)
	{
		count = 0;
		list_b = begin;
		while (list_b)
		{
			if (list_b->nb == list_a->nb)
				count++;
			list_b = list_b->next;
		}
		if (count > 1)
			return (1);
		list_a = list_a->next;
	}
	return (0);
}

int	is_only_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && !(str[i] >= '0' && str[i] <= '9')
			&& !(!(str[i - 1] >= '0' && str[i - 1] <= '9') && str[i] == '-'
				&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
			&& !(!(str[i - 1] >= '0' && str[i - 1] <= '9') && str[i] == '+'
				&& (str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

int	order_is_correct(t_stack *list, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (list->nb > list->next->nb)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

int	argv_is_ok(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}
