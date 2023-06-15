/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:48:48 by odouhri           #+#    #+#             */
/*   Updated: 2023/06/14 01:49:40 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_check.h"

void	check_issorted(t_stack *s)
{
	int	i;

	i = s->top - 1;
	while (i > 0)
	{
		if (s->items[i] > s->items[i - 1])
			return ;
		i--;
	}
	stack_destroy(s);
	exit(0);
}

void	check_dup(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->top)
	{
		j = i + 1;
		while (j < s->top)
		{
			if (s->items[i] == s->items[j])
			{
				ft_printerr("Error\n");
				stack_destroy(s);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
