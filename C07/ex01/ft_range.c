/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkathman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:58:55 by pkathman          #+#    #+#             */
/*   Updated: 2023/03/02 11:17:14 by pkathman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	range = (int *)malloc(sizeof(int) * (max - min));
	if (!range)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
/*
#include <stdio.h>
int	main(void)
{
	int	min = -10;
	int	max = 5;
	int	i 	= 0;
	int	*range;

	range = ft_range(min, max);
	while (i < (max - min))
	{
		printf("%d ", range[i]);
		i++;
	}
	free(range);
	return (0);
}*/
