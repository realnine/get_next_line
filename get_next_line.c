#include "get_next_line.h"

int cutting(char **buf_store, char **line, char *char_n)
{
		*ptr_n = '\0';
		if ((*line = strdup(*buf_store)) == NULL)
		{
			free(buf_store);
			return (-1);
		}
		free(*buf_store);
		*buf_store = strdup(ptr_n + 1);
		return (1);
}


int tmp()
{
		if (**buf_store == '\0')
		{
			*line = strdup("");
			return (0);
		}
		if ((*line = strdup(*buf_store)) == NULL)
		{
			free(*buf_store);
			return (-1);
		}
		free(buf_store);
		return (0);
}

int get_next_line(int fd, char **line)
{
	char        buf[BUFFER_SIZE + 1];
	static char *buf_store = NULL;
	ssize_t     rtn_read;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);

	while ((rtn_read = read(fd, buf, BUFFER_SIZE)) > 0 )
	{
		buf[BUFFER_SIZE] = '\0';
		tmp = buf_store;
		buf_store = ft_strjoin(buf_store, buf);
		if (tmp != NULL)
			free(tmp);
		if ((tmp = strchr(buf_store, '\n')) != NULL)
			return (cutting(&buf_store, line, tmp));
	}
	if (rtn_read == 0)
	{
		if(buf_store == NULL)
		{
			**line = '\0';
			return (0);
		}
		if ((tmp = strchr(buf_store, '\n')) != NULL)
			return (cutting(&buf_store, line));
	}
	else //rtn_read == -1 일때
	{
		free(buf_store);
		return (-1);
	}
}

