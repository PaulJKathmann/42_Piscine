/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkathman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:58:55 by pkathman          #+#    #+#             */
/*   Updated: 2023/03/02 14:46:02 by pkathman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	i;

	*range = (int *)malloc(sizeof(range) * (max - min + 1));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!*range)
	{
		return (-1);
	}
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
/*
#include <stdio.h>
int	main(void)
{
	int	min = -10;
	int	max = 5;
	int	i 	= 0;
	int	*range;

	printf("size of range: %d\n", ft_ultimate_range(&range, min, max));
	while (i < (max - min))
	{
		printf("%d ", range[i]);
		i++;
	}
	printf("%d ", range[i]);
	free(range);
	return (0);
}*/
