/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:22:47 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/20 08:00:40 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cmpt_word(char **stack)
{
	int	i;

	i = 0;
	while (stack[i] != NULL)
		i++;
	return (i);
}

void ft_free_stack(char **stack)
{
	int	i;

	i = ft_cmpt_word(stack);
	while (--i >= 0)
	{
		free(stack[i]);
		stack[i] = NULL;
	}
	free(stack);
}

char	*ft_merge(char **argv)
{
	int	i;
	char *str;
	char *tmp1;
	char *tmp2;

	str = malloc(sizeof(char) * 2);
	str[0] = ' ';
	str[1] = '\0';
	i = 1;
	while (argv[i] != NULL)
	{
		tmp1 = str;
		tmp2 = ft_strjoin((const char *)argv[i], (const char *)" ");
		str = ft_strjoin((const char *)tmp1, (const char *)tmp2);
		free(tmp1);
		tmp1 = NULL;
		free(tmp2);
		tmp2 = NULL;
		i++;
	}
	return (str);
}

t_stack	*ft_parsing(t_stack *list_a, char **argv)
{
	int	i;
	char *str;
	char **stack;

	str = ft_merge(argv);
	if (!(is_only_numbers(str)))
	{
		free(str);
		return (NULL);
	}
	stack = ft_split((const char *)str, 32);
	free(str);
	str = NULL;
	if (!(is_an_int(stack)))
	{
		ft_free_stack(stack);
		return (NULL);
	}
	i = ft_cmpt_word(stack);
	while (--i >= 0)
		list_a = add_link_top(list_a, ft_atoi((const char *)stack[i]), 0);
	ft_free_stack(stack);
	return (list_a);
}
