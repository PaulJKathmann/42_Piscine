/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkathman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:45:51 by pkathman          #+#    #+#             */
/*   Updated: 2023/03/02 17:51:24 by pkathman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

long int	check_base_to(char *base)
{
	long int	i;
	long int	j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		j = i;
		while (base[j] != 0)
		{
			if (base[i] == base[j + 1])
				return (-1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

int	ft_putnbr_base(long int nbr, char *base, char *str)
{
	long int	base_size;
	int			index;

	index = 0;
	if (str[0] == '-')
		index = 1;
	if (check_base_to(base) < 0)
		return (0);
	else
		base_size = check_base_to(base);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr > base_size - 1)
		index = ft_putnbr_base(nbr / base_size, base, str);
	str[index] = base[nbr % base_size];
	return (index + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	char	*str;
	int		index;

	str = malloc(sizeof(char) * 31);
	if (!str)
		return (0);
	number = ft_atoi_base(nbr, base_from);
	index = ft_putnbr_base(number, base_to, str);
	if (number == 0 || index == 0)
		return (0);
	str[index] = '\0';
	return (str);
}

#include <stdio.h>
int	main(void)
{
	char	*nbr;
	char	*base_from = "0123456789";
	char	*base_to = "01";
	nbr = "\t\n -100sdas324";
//	printf("Atoi_base returns: %d\n", ft_atoi_base(nbr, base_from));
	printf("ft_convert_base: %s\n", ft_convert_base(nbr, base_from, base_to));
}
