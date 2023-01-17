#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (*str++ != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*temp;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *) malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	temp = s2;
	while (*s1 != '\0')
		*temp++ = *s1++;
	*temp = '\0';
	return (s2);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char *temp;
	char *s3;

	s3 = malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!s3)
		return (NULL);
	temp = s3;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (s3);
}

int	ft_check_new_line(char *str)
{
	if (!str)
		return(-1);
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

int	ft_count_lb(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		i;
	char	c;
	int		end;
	int		pos;

	i = 1;
	pos = BUFFER_SIZE;
	end = 0;
	if (fd < 2)
		return (-1);
	while (1)
	{
		if (pos >= end)
		{	
			end = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			if (end == 0)
			{
				if(pos == 0 && c == 0)
					return (0);
				else
					break;
			}
		}
		c = buffer[pos++];
		if (c == '\n')
			i++;
	}
	return (i);
}

char	*ft_get_next_line(int fd)
{
	char		*line;
	int			i;
	static char	buffer[BUFFER_SIZE];
	char		c;
	int	pos=BUFFER_SIZE;
	int	end=BUFFER_SIZE;
	int			line_pos;

	line_pos = 0;
	i = 0;
	end = 0;
	line = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!line)
		return ("No line");
	if (fd < 2)
		return ("Error");
	while (1)
	{
		if (pos >= end)
		{  
			pos = 0;
			end = read(fd, buffer, BUFFER_SIZE);
			if (end == 0) /* end of file */
			{
				/* No data was read */
				if (line_pos == 0) 
				{
					free (line);
					return NULL;
				}
				else
					break;
			}
			/* free(line); */
		}
		c = buffer[pos++];
		line[line_pos++] = c;
		if (c == '\n')
		{
			i++;
			break ;
		}
	}
	line[line_pos] = '\0';
	return (line);
}

int	main(void)
{
	int fd;
	int i;

	i = 0;
	fd = open("foobar2.txt", O_RDONLY);
	printf("There are %i line breaks in this text", ft_count_lb(fd));
	close (fd);
	return (0);
}

/* int	main(void)
{
	int fd;
	int i;

	i = 0;
	fd = open("foobar2.txt", O_RDONLY);
	while (i < 8)
	{
		printf("%d", ft_count_lb(fd));
		i++;
	}
	close (fd);
	return (0);
} */



/* int main (void)
{
	char			*buf;
	int				nb_read;
	int				fd;

	fd = open("foobar2.txt", O_RDONLY);
	buf = malloc(sizeof(char) * 1000);
	printf("%s\n\n", buf);
	if (fd == -1)
		return (1);
	nb_read = read(fd, buf, BUFFER_SIZE);
	buf[nb_read] = '\0';
	printf("%i and %i;\n %s", fd, nb_read, buf);
	close (fd);
	return (0);
} */