#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
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

int main(void)
{
	printf("%s and strlen %i\n strjoin is: %s", ft_strdup("Asdsdadsu"), ft_strlen("Asdsdadsu"), ft_strjoin("Asdsdadsu", "Asdsdadsu"));
	return (0);
}

/* int main (void)
{
	char			*buf;
	static	char	*str;
	int				nb_read;
	int				fd;

	fd = open("foo2.txt", O_RDONLY);
	buf = malloc(sizeof(char) * 100);
	printf("%s\n\n", buf);
	if (fd == -1)
		return (1);
	nb_read = read(fd, buf, BUFFER_SIZE);
	while (nb_read != '\0')
	{	
		if (nb_read == -1)
		{	
			free(buf);
			return (0);
		}
	}
	buf[nb_read] = '\0';
	printf("%i and %i;\n %s", fd, nb_read, buf);
	close (fd);
	close (fd1);
	return (0);
} */