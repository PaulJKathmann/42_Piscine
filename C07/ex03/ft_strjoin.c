/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkathman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:03:49 by pkathman          #+#    #+#             */
/*   Updated: 2023/03/02 18:00:23 by pkathman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen] != 0)
	{
		strlen++;
	}
	return (strlen);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	dest_length;

	i = 0;
	dest_length = 0;
	while (dest[dest_length] != 0)
	{
		dest_length++;
	}		
	while (src[i] != 0)
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest);
}

int	total_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size && strs[i])
	{
		total_len = total_len + ft_strlen(strs[i]);
		i++;
	}
	total_len = total_len + ft_strlen(sep) * (size - 1) + 1;
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		i;
	int		total_len;

	if (!sep || !strs)
		return (NULL);
	string = "";
	if (size <= 0)
		return (string);
	total_len = total_length(size, strs, sep);
	string = (char *)malloc(sizeof(char) * total_len);
	if (!string)
		return (NULL);
	i = 0;
	while (i < size && strs[i])
	{
		ft_strcat(string, strs[i]);
		if (i < size - 1 && strs[i + 1])
			ft_strcat(string, sep);
		i++;
	}
	return (string);
}

#include <stdio.h>
int	main(void)
{
	char	**strs;
	char	*ptr;

	strs = (char**)malloc(sizeof(*strs) * 2);
	*strs = (char*)malloc(sizeof(**strs) * 20);
	strs[0] = "Hello";
	strs[1] = "World";
	strs[2] = "and";
	strs[3] = "bye";

	char	*sep = " ";

	printf("%s\n", ft_strjoin(8, strs, sep));
	ptr = ft_strjoin(4, strs, sep);
	free(strs);
	free(ptr);
}
