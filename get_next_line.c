/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhaled1855gmail.com <alikhaled1855gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:43:49 by alikhaled18       #+#    #+#             */
/*   Updated: 2026/01/22 07:58:31 by alikhaled18      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_null(char *ptr)
{
	free(ptr);
	return (NULL);
}

static char	*ft_read_loop(int fd, char *buffer)
{
	char	*temp;
	int		bytes;
	char	*old;

	temp = malloc((size_t)BUFFER_SIZE + 1);
	if (!temp)
		return (ft_free_null(buffer));
	bytes = 1;
	while (!ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		temp[bytes] = '\0';
		old = buffer;
		buffer = ft_strjoin(buffer, temp);
		free(old);
		if (!buffer)
			return (ft_free_null(temp));
	}
	free(temp);
	if (bytes == -1)
		return (ft_free_null(buffer));
	return (buffer);
}

static char	*ft_extract_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, i + 1);
	if (buffer[i] == '\n')
		line[i + 1] = '\0';
	else
		line[i] = '\0';
	return (line);
}

static char	*ft_update_buffer(char *buffer)
{
	size_t	len;
	char	*newline;
	char	*new_buff;

	newline = ft_strchr(buffer, '\n');
	if (!newline)
	{
		free(buffer);
		return (NULL);
	}
	newline++;
	len = ft_strlen(newline);
	new_buff = malloc(len + 1);
	if (!new_buff)
	{
		free(buffer);
		return (NULL);
	}
	ft_strlcpy(new_buff, newline, len);
	new_buff[len] = '\0';
	free(buffer);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = ft_read_loop(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_update_buffer(buffer);
	return (line);
}
