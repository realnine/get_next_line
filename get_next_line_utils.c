/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:05:20 by jinglee           #+#    #+#             */
/*   Updated: 2021/04/05 15:05:31 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const void	*dstp = dst;

	if (!dst && !src)
		return (NULL);
	while (n--)
		*((unsigned char *)dstp++) = *((unsigned char *)src++);
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	if (!dst || !src)
		return (0);
	srcsize = ft_strlen(src);
	if (srcsize < dstsize)
		ft_memcpy(dst, src, srcsize + 1);
	else if (dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srcsize);
}

char	*ft_strdup(const char *s1)
{
	const size_t	len = ft_strlen(s1);
	char			*dst;

	if (!(dst = malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(dst, s1, len + 1);
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	siz;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	siz = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(siz);
	if (!ptr)
		return (NULL);
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	free(s1);
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
