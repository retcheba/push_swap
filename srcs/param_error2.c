/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:41:13 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/21 17:51:40 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*int_max(void)
{
	char	*nb;

	nb = malloc(sizeof(char) * 11);
	nb[10] = '\0';
	nb[9] = '2';
	nb[8] = '1';
	nb[7] = '4';
	nb[6] = '7';
	nb[5] = '4';
	nb[4] = '8';
	nb[3] = '3';
	nb[2] = '6';
	nb[1] = '4';
	nb[0] = '7';
	return (nb);
}

static int	ft_len_number(char *stack, char *max, int *j)
{
	int	count;

	count = 0;
	while (stack[*j] == 32)
		*j += 1;
	if (stack[*j] == '+' || stack[*j] == '-')
	{
		if (stack[*j] == '-')
			max[0] = '8';
		*j += 1;
	}
	while (stack[*j] == '0')
		*j += 1;
	while (stack[*j] >= '0' && stack[*j] <= '9')
	{
		*j += 1;
		count++;
	}
	return (count);
}

static int	is_bigger_than_max(char *stack, char *max, int count, int j)
{
	while (count > 0)
	{
		if (stack[j - count] > max[count - 1])
		{
			free(max);
			return (1);
		}
		else if (stack[j - count] < max[count - 1])
			break ;
		count--;
	}
	return (0);
}

int	is_an_int(char **stack)
{
	int		i;
	int		j;
	int		count;
	char	*max;

	i = -1;
	max = int_max();
	while (stack[++i])
	{
		j = 0;
		count = ft_len_number(stack[i], max, &j);
		if (count > 10)
		{
			free(max);
			return (0);
		}
		else if (count == 10)
		{
			if (is_bigger_than_max(stack[i], max, count, j))
				return (0);
		}
	}
	free(max);
	return (1);
}
