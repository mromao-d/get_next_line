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

char	*ft_strchr_adapted(const char *s, int c)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)s;
	if (!s)
		return (NULL);
	while (*temp != '\0')
	{	
		if(*temp == c)
			break;
		temp++;
	}
	if (*temp == c)
		return (++temp);
	return ("merda");
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s3;
	int		keep_size;

	keep_size = ft_strlen((char *)s2);
	i = 0;
	s3 = malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!s3)
		return (NULL);
	while (i < ft_strlen((char *)s1))
	{	
		s3[i] = s1[i];
		i++;
	}
	while (i < ft_strlen((char *)s1) + keep_size)
	{	
		s3[i] = *s2++;
		i++;
	}
	s3[i] = '\0';
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

int	ft_lb_pos(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			break;
		i++;
	}
	if (s[i] == '\n')
		return(i + 1);
	return (0);
}

int	ft_chek_lb(char *heap)
{
	int i;

	i = 0;
	if (!heap)
		return (0);
	while (heap[i])
	{	
		if (heap[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_gnl_read(int fd, char *stack)
{
	char	*heap;
	int		end;
	int		i;

	i = 0;
	heap = calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!heap)
		return (NULL);
	while (1)
	{
		end = read(fd, heap, BUFFER_SIZE);
		if (end == 0)
		{
			if (i == 0 && heap == 0)
				stack = 0;
			free(heap);
			heap = 0;
			break;
		}
		if (fd < 2)
		{
			if (heap)
				free (heap);
			heap = 0;
			break;
		}
		if (ft_chek_lb(heap) == 1)
			break;
		heap[end] = 0;
		stack = ft_strjoin(stack, heap);
		i++;
	}
	stack = ft_strjoin(stack, heap);
	free (heap);
	return (stack);
}

char	*ft_left(char *s, int i)
{
	char	*temp;
	int		size;

	size = 0;
	if (i < ft_strlen(s))
		temp = malloc(sizeof(char) * (i + 1));
	else
		temp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!temp)
		return (NULL);
	if (!s)
		return(NULL);
	if (i == 0)
		return (s = 0);
	else
		while (s[size] != 0 && size < i)
		{	
			temp[size] = s[size];
			size++;
		}
		temp[size] = 0;
	return (temp);
}

char	*ft_get_next_line(int	fd)
{
	static char	*stack;
	char		*line;
	int			pos;

	pos = 0;
	if (ft_strlen(stack) == 0 || ft_chek_lb(stack) == 0)
		stack = ft_gnl_read(fd, stack);
	if (ft_chek_lb(stack) == 1)
	{
		line = ft_left(stack, ft_lb_pos(stack));
		stack =ft_strchr_adapted(stack, '\n');
	}
	else
		line = ft_strdup(stack);
	return (line);
}

int	main(void)
{
	int fd;
	int i;
	/* char *str="granda ";
	char *s="Pota"; */

	i = 0;
	fd = open("foobar4.txt", O_RDONLY);
	while (i < 6)
	{
		printf("%s", ft_get_next_line(fd));
		i++;
	}
	close (fd);
	/* printf("\n%i\n", ft_chek_lb("\ndafuck")); */
	/* str = ft_strjoin(str, s);
	printf("\n%s", str); */
	/* printf("\nstring is: %s\n", ft_strchr("one \n two two two \n three ", '\n')); */
	return (0);
}
