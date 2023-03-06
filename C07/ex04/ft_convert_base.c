/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkathman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:45:51 by pkathman          #+#    #+#             */
/*   Updated: 2023/02/28 17:32:39 by pkathman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	check_base_from(char *base)
{
	int	i;
	int	j;

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

int	string_length(char *str, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (base[j] != 0)
		{
			if (str[i] == base[j])
				break ;
			j++;
			if (base[j] == '\0')
				return (i);
		}
		i++;
	}
	return (i);
}

int	base_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
	{
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_size;
	int	integer;
	int	sign;
	int	i;

	integer = 0;
	sign = 1;
	i = 0;
	if (check_base_from(base) < 0)
		return (0);
	base_size = check_base_from(base);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (i < string_length(str, base))
	{
		integer = integer * base_size + base_value(str[i], base);
		i++;
	}
	return (integer * sign);
}
