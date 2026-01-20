/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhaled1855gmail.com <alikhaled1855gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:43:49 by alikhaled18       #+#    #+#             */
/*   Updated: 2026/01/20 19:46:41 by alikhaled18      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{
    static char *buffer;
    int bytes_read;
    char temp[BUFFER_SIZE + 1];
    char *line;
    char *newline;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    if (!buffer)
    {
        buffer = malloc(1);
        if (!buffer)
            return (NULL);
        buffer[0] = '\0';
    }
    bytes_read = 1;
    while (!ft_strchr(buffer, '\n'))
    {
        bytes_read = read(fd, temp, BUFFER_SIZE);

        if (bytes_read <= 0)
            break;

        temp[bytes_read] = '\0';
        char *old = buffer;
        buffer = ft_strjoin(buffer, temp);
        free(old);
    }
    if (bytes_read <= 0)
    {
        if (buffer && buffer[0] != '\0')
        {
            line = buffer;
            buffer = NULL;
            return (line);
        }
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    if(ft_strchr(buffer, '\n'))
    {
        size_t i;
        char *c;

        i = 0;
        while(buffer[i] != '\n')
        i++;
        c = malloc(i+2);
        if(!c)
        {
            free(buffer);
            return (NULL);
        }
        ft_strlcpy(c, buffer, i+1);
        c[i+1] = '\0';
        newline = ft_strchr(buffer, '\n');
        newline++;
        char *ramining = malloc(ft_strlen(newline)+1);
        if(!ramining)
        {
            free(c);
            free(buffer);
            return (NULL);
        }
        ft_strlcpy(ramining, newline, ft_strlen(newline));
        ramining[ft_strlen(newline)] = '\0';
        free(buffer);
        buffer = ramining;  // ✅ بس!
        return (c);
    }
    return (NULL);
}
