/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnartdin <rnartdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:07:45 by rnartdin          #+#    #+#             */
/*   Updated: 2023/08/06 19:18:15 by rnartdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_full_line(int fd, char *remainder)
{
	char	*buffer;
	int		size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(remainder, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == (-1))
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		remainder = ft_strjoin(remainder, buffer);
	}
	free(buffer);
	return (remainder);
}

char	*cut_the_line(char *remainder)
{
	int		iter;
	char	*new_line;

	iter = 0;
	if (!remainder[iter])
		return (NULL);
	while ((remainder[iter] != '\n') && remainder[iter])
		iter++;
	new_line = malloc((iter + 2) * sizeof(char));
	ft_strlcpy(new_line, remainder, iter + 2);
	return (new_line);
}

char	*get_remainder(char *remainder)
{
	int		iter;
	char	*new_line;

	iter = 0;
	while ((remainder[iter] != '\n') && remainder[iter])
		iter++;
	if (!*(remainder + iter))
	{
		free(remainder);
		return (NULL);
	}
	new_line = malloc((ft_strlen(remainder) - iter + 1) * sizeof(char));
	if (!(new_line))
		return (NULL);
	ft_strlcpy(new_line, remainder + iter + 1, ft_strlen(remainder) - iter);
	free(remainder);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*remainder[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	remainder[fd] = get_full_line(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	line = cut_the_line(remainder[fd]);
	remainder[fd] = get_remainder(remainder[fd]);
	return (line);
}
