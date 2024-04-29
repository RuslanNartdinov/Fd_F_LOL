/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruslannartdinov <ruslannartdinov@student.4 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:22:11 by rnartdin          #+#    #+#             */
/*   Updated: 2024/04/29 11:32:26 by ruslannartdinov  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	check(char a, char c)
{
	if (a == c)
		return (1);
	return (0);
}
char	*duplicate_and_cut(char const **src, int size)
{
	int		iterator;
	char	*string;

	iterator = 0;
	string = malloc(size + 1);
	if (!string)
		return (NULL);
	while (iterator < size)
	{
		string[iterator] = (*src)[iterator];
		iterator++;
	}
	string[iterator] = '\0';
	*src = *src + size;
	return (string);
}

char	*separate(char const **src, char c)
{
	int		iterator;
	char	*duplicated_string;

	iterator = 0;
	while (**src && check(**src, c))
		(*src)++;
	while ((*src)[iterator])
	{
		while ((*src)[iterator] && !check((*src)[iterator], c))
			iterator++;
		if (iterator > 0)
		{
			duplicated_string = duplicate_and_cut(src, iterator);
			return (duplicated_string);
		}
	}
	return (0);
}

int	final_size(char const *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] && check(str[i], c))
		i++;
	while (str[i])
	{
		while (str[i] && !check(str[i], c))
			i++;
		size++;
		while (str[i] && check(str[i], c))
			i++;
	}
	return (size);
}

char	**ft_split(char const *str, char c)
{
	char	**final_strs_arr;
	int		iterator;
	int		num_of_strs;

	iterator = 0;
	if (!str)
		return (NULL);
	num_of_strs = final_size(str, c);
	final_strs_arr = malloc((num_of_strs + 1) * 8);
	if (!final_strs_arr)
		return (0);
	while (iterator < num_of_strs)
	{
		final_strs_arr[iterator] = separate(&str, c);
		if (final_strs_arr[iterator] == 0)
			break ;
		iterator++;
	}
	final_strs_arr[iterator] = 0;
	return (final_strs_arr);
}
