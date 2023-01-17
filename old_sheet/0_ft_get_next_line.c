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

char	*ft_strchr(const char *s, int c)
{
	char *temp;

	temp = (char *)s;
	if (!s)
		return (NULL);
	while (*++temp != '\0')
	{	
		if(*temp == c)
			break;
	}
	if (*temp == c)
		return (temp);
	return ("merda");
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

char	*ft_get_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*heap;
	char		*line;
	static char	*temp;
	char		c;
	int			line_count;
	int			end;
	int			pos;

	heap = malloc(sizeof(char) * (BUFFER_SIZE));
	line = malloc(sizeof(char) * (BUFFER_SIZE));
	line_count = 0;
	pos=0;
	end=0;
	if (fd < 2)
		return ("shit in the file descriptor");
	while (heap[pos] != '\n')
	{
		if ((pos >= end)/*  && *temp != 0 */)
		{
			end = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			line_count = 0;
			line = ft_strjoin(line, heap);
			if (end == 0)
			{
				if(pos == 0 && heap[pos] == '\0')
					return (NULL);
				else
					break;
			}
		}
		c = buffer[pos++];
		heap[line_count++] = c;
		if (c == '\n')
		{
			line = ft_strjoin(line, heap);
			if (ft_strlen(heap) < BUFFER_SIZE)
				temp = ft_strchr((const char *)buffer, c);
			break;
		}
	}
	return (temp);
}

int	main(void)
{
	int fd;
	int i;
	/* char *str="granda ";
	char *s="Pota"; */

	i = 0;
	fd = open("foobar4.txt", O_RDONLY);
	while (i < 30)
	{
		printf("%s", ft_get_line(fd));
		i++;
	}
	close (fd);
	/* printf("\n%s\n", ft_strchr("dafuck", 'u')); */
	/* str = ft_strjoin(str, s);
	printf("\n%s", str); */
	return (0);
}