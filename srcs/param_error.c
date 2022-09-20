/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:09:53 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/20 09:43:59 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_duplicates(t_stack *list_a, t_stack *list_b)
{
	t_stack *begin;
	int	count;

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
		&& !(!(str[i - 1] >= '0' && str[i - 1] <= '9') && str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		&& !(!(str[i - 1] >= '0' && str[i - 1] <= '9') && str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

int	is_an_int(char **stack)
{
	int	i;
	int	j;
	int	count;
	int	n;
	char max[10] = "7463847412";
	char min[10] = "8463847412";

	i = 0;
	while (stack[i])
	{
		j = 0;
		n = 0;
		count = 0;
		while (stack[i][j] == ' ' || (stack[i][j] >= '\t' && stack[i][j] <= '\r'))
			j++;
		if (stack[i][j] == '+' || stack[i][j] == '-')
		{
			if (stack[i][j] == '-')
				n++;
			j++;
		}
		while (stack[i][j] == '0')
			j++;
		while (stack[i][j] >= '0' && stack[i][j] <= '9')
		{
			j++;
			count++;
		}
		if (count > 10)
			return (0);
		else if (count == 10)
		{
			if (n == 0)
			{
				while (count > 0)
				{
					if (stack[i][j - count] > max[count - 1])
						return (0);
					else if (stack[i][j - count] < max[count - 1])
						break;
					count--;
				}
			}
			else
			{
				while (count > 0)
				{
					if (stack[i][j - count] > min[count - 1])
						return (0);
					else if (stack[i][j - count] < min[count - 1])
						break;
					count--;
				}
			}
		}
		i++;
	}
	return (1);
}
