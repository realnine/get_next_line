#include "get_next_line.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
	char    *ptr;
	size_t  siz;
	int     i;
	int     j;

	if (!s1 && !s2)
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? strdup(s2) : strdup(s1));
	siz = strlen(s1) + strlen(s2) + 1;
	ptr = malloc(siz);
	if (!ptr)
		return (NULL);
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
