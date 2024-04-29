/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnartdin <rnartdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:07:20 by rnartdin          #+#    #+#             */
/*   Updated: 2023/08/06 19:10:26 by rnartdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	iter;

	iter = 0;
	if (!str || !str[iter])
		return (0);
	while (str[iter])
		iter++;
	return (iter);
}

char	*ft_strchr(const char *s, int c)
{
	char	*string;

	if (!s || !*s)
		return (NULL);
	string = (char *)s;
	while (*string != (unsigned char)c)
	{
		if (!*string)
			return (0);
		string++;
	}
	return (string);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	int		iter;
	size_t	length;

	iter = 0;
	length = ft_strlen((char *)src);
	if (!dstsize)
		return (length);
	while (dstsize - 1)
	{
		dst[iter] = src[iter];
		if (!dst[iter] || !src[iter])
			return (length);
		iter++;
		dstsize--;
	}
	dst[iter] = '\0';
	return (length);
}

char	*ft_strjoin(char *remainder, char *buffer)
{
	size_t	remainder_lenght;
	size_t	buffer_lenght;
	char	*result;

	if (!remainder)
	{
		remainder = malloc(sizeof(char));
		if (!remainder)
			return (NULL);
		remainder[0] = 0;
	}
	if (!remainder || !buffer)
		return (NULL);
	remainder_lenght = ft_strlen(remainder);
	buffer_lenght = ft_strlen(buffer);
	result = malloc((remainder_lenght + buffer_lenght + 1) * sizeof(char));
	if (!result)
		return (0);
	ft_strlcpy(result, remainder, remainder_lenght + 1);
	ft_strlcpy(result + remainder_lenght, buffer, buffer_lenght + 1);
	free(remainder);
	return (result);
}
