#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <unistd.h>
#include <fcntl.h>

int		get_next_line(int fd, char **line);
void    *ft_memcpy(void *dst, const void *src, size_t n);
size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char    *ft_strdup(const char *s1);
char    *ft_strjoin(char const *s1, char const *s2);

#endif
