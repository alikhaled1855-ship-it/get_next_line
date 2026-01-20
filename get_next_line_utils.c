/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhaled1855gmail.com <alikhaled1855gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:30:53 by alikhaled18       #+#    #+#             */
/*   Updated: 2026/01/20 19:22:32 by alikhaled18      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t ft_strlen(const char *s)
{
    size_t i;

    if(!s)
    return (0);
    i = 0;
    while(s[i])
    i++;
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    size_t i;

    if(!s)
    return NULL;
    i = 0;
    while(s[i])
    {
        if(s[i] == (unsigned char)c)
        return &s[i];
        i++;
    }
    if(s[i] == (unsigned char)c)
    return &s[i];
    return NULL;
}

size_t ft_strlcpy(char *dst, const char *src, size_t len)
{
    size_t i;

    i = 0;
    while(src[i] && i < len)
    {
        dst[i] = src[i];
        i++;
    }
    //dst[i++] = '\n';
    //dst[i] = '\0';
    return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len;
    size_t s1len;
    size_t s2len;
    char *sp;
// abc def
    if(!s1 || !s2)
        return (NULL);
    s1len = ft_strlen(s1);
    s2len = ft_strlen(s2);
    len = (s1len + s2len);
    sp = malloc(len + 1);
    if (!sp)
        return (NULL);
    ft_strlcpy(sp, s1, s1len);
    ft_strlcpy(sp + s1len, s2, s2len);
    sp[len] = '\0';
    return (sp);
}
