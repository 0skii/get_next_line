#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*tmp;
	int			i;

	i = 0;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		while (buf[fd][i])
			buf[fd][i++] = 0;
		return (NULL);
	}
	tmp = NULL;
	while (buf[fd][0] || read(fd, buf[fd], BUFFER_SIZE) > 0)
	{
		tmp = ft_join(tmp, buf[fd]);
		if (ft_cleaner(buf[fd]))
			break ;
	}
	return (tmp);
}
