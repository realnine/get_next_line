#include "get_next_line.h"

int cutting(char **buf_store, char **line, char *ptr_next)
{
	char *tmp;

	*ptr_next = '\0';
	if ((*line = strdup(*buf_store)) == NULL)
	{
		free(*buf_store);
		return (-1);
	}
	tmp = *buf_store;
	*buf_store = strdup(ptr_next + 1);
	free(tmp);
	return (1);
}

int last_cutting(char **buf_store, char **line)
{
	if ((*line = strdup(*buf_store)) == NULL)
	{
		free(*buf_store);
		return (-1);
	}
	free(buf_store);
	*buf_store = NULL;
	return (0);
}

int get_next_line(int fd, char **line)
{
	char        buf[BUFFER_SIZE + 1];
	static char *buf_store[OPEN_MAX] = { 0, };
	ssize_t     rtn_read;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((rtn_read = read(fd, buf, BUFFER_SIZE)) > 0 )
	{
		buf[rtn_read] = '\0';
		tmp = buf_store[fd];
		buf_store[fd] = ft_strjoin(buf_store[fd], buf);
		if (tmp != NULL)
			free(tmp);
		if ((tmp = strchr(buf_store[fd], '\n')) != NULL)
			return (cutting(&buf_store[fd], line, tmp));
	}
	if (rtn_read == 0)
	{
		if(buf_store[fd] == NULL)
		{
			*line = strdup("");
			return (0);
		}
		else if ((tmp = strchr(buf_store[fd], '\n')) != NULL)
			return (cutting(&buf_store[fd], line, tmp));
		else if (tmp == NULL)
			return (last_cutting(&buf_store[fd], line));
	}
	
		if(buf_store[fd] != NULL)
		{
			free(buf_store[fd]);
			buf_store[fd] = NULL;
		}
		return (-1);
}
