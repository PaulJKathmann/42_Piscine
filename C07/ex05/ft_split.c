/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkathman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:24:45 by pkathman          #+#    #+#             */
/*   Updated: 2023/03/02 19:04:10 by pkathman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_n_str(char *str, char *charset)
{
	int	i;
	int	p_sep;
	int	n_str;

	i = 0;
	p_sep = 1;
	n_str = 0;
	while (str[i])
	{
		if (p_sep && !is_separator(str[i], charset))
		{
			n_str++;
			p_sep = 0;
		}
		if (is_separator(str[i], charset))
			p_sep = 1;
		i++;
	}
	return (n_str);
}

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	splitter(char *str, char **str_arr, char *charset)
{
	int	i;
	int	j;
	int	word;
	int	p_sep;

	i = 0;
	p_sep = 1;
	j = 0;
	word = 0;
	while (str[i])
	{
		if (p_sep && !is_separator(str[i], charset))
			j = 0;
		if (!is_separator(str[i], charset))
			str_arr[word][j] = str[i];
		if ((!p_sep && is_separator(str[i], charset)) || str[i + 1] == 0)
		{	
			word++;
		}
		p_sep = is_separator(str[i], charset);
		i++;
		j++;
	}
	str_arr[word][0] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		str_len;
	int		n_strings;
	int		i;
	char	**str_arr;

	if (!str || !charset)
		return (0);
	str_len = ft_str_len(str);
	n_strings = ft_n_str(str, charset);
	printf("test: %d", n_strings);
	str_arr = (char**)malloc(sizeof(char *) * (n_strings + 1));
	i = 0;
	while (i < n_strings + 1)
	{
		str_arr[i] = malloc(sizeof(char) * (str_len));
		i++;
	}
	splitter(str, str_arr, charset);
	return (str_arr);
}

int	main(void)
{
	char *str = "haaiaalo what up";
    char *sep = "";
//	char	*str = "hello world !";
//	char	*sep = "l ";
	char	**str_arr;
	int		i;

	i = 0;
	str_arr = ft_split(str, sep);
	while (str_arr && str_arr[i][0])
	{
		printf("%s,", str_arr[i]);
		i++;
	}
	i = 0;
	while (i < 3 && str_arr)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	return (0);
}
