#include "get_next_line.h"

/* void	*ft_calloc(int nmemb, int size)
{
	void	*str;
	int	i;

	i = 0;
	str = (void *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)str)[i] = 0;
		i++;
	}
	return (str);
} */

char	*ft_gnl_read(int fd, char *stack)
{
	int		end;
	char	*heap;
	char	*tmp;

	end = BUFFER_SIZE;
	heap = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!heap)
		return (NULL);
	while (end > 0)
	{
		if (ft_lb_pos(heap) > 0)
			break;
		end = read(fd, heap, BUFFER_SIZE);
		if (end < 0)
		{
			if (heap)
			{
				free(heap);
				heap = 0;
			}
			if (stack)
				free(stack);
			break;
		}
		heap[end] = 0;
		if (stack && heap)
		{
			tmp = ft_strdup(stack);
			free(stack);
			stack = ft_strjoin(tmp, heap);
			free(tmp);
		}
		else
			stack = ft_strdup(heap);
	}
	if (heap)
	{
		free(heap);
		heap = 0;
	}
	return(stack);
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
		temp[size] = '\0';
	return (temp);
}

char	*ft_substr(char *str, int start)
{
	char	*output;
	char	*tmp;
	int		i;
	int		len;
	int		j;

	if (start < 1)
	{	
		if (str)
		{
			free(str);
			str = 0;
		}
		return (NULL);
	}
	i = 0;
	len = ft_strlen(str);
	tmp = ft_strdup(str);
	j = -1;
	while (tmp[i] && i < start)
		i++;
	output = malloc(sizeof(char) * (len - i + 1));
	if (!output)
		return (NULL);
	while (tmp[i])
		output[++j] = tmp[i++];
	output[++j] = 0;
	free(str);
	str = 0;
	free(tmp);
	tmp = 0;
	return(output);
}

char	*ft_strchr_adapted(char *s, int c)
{
	char	*temp;
	char	*output;
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
	{
		output = ft_strdup(++temp);
		free(s);
		return (output);
	}
	/* if (s)
	{	
		free(s);
		s = 0;
	} */
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*clean_stack;
	char		*line;

	if (!fd || fd < 2 || read(fd, NULL, 0) < 0  || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (ft_lb_pos(stack) == 0)
		stack = ft_gnl_read(fd, stack);
	if (!stack || stack[0] == 0)
	{
		free(stack);
		stack = 0;
		return (NULL);
	}
	if (ft_lb_pos(stack) > 0)
	{	
		line = ft_left(stack, ft_lb_pos(stack));
		/* free(line); */
	}
	else
		line = stack;
	if (!line || line[0] == 0)
	{
		free(line);
		line = 0;
		return (NULL);
	}
	clean_stack = stack;
	stack = ft_strchr_adapted(stack, '\n');
	/* free(clean_stack); */
	/* if (stack[0] == 0)
	{	
		free(stack);
		stack = 0;
	} */
	/* if (line)
		free(line); */
	return (line);
}


int	main(void)
{
	int fd;
	int i;
	char *str;

	i = 0;
	fd = open("foobar2.txt", O_RDONLY);
	while (i < 1)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	close (fd); 
	return (0);
}

/*  
int	main(void)
{
	int fd;
	int i;

	i = 0;
	fd = open("foobar2.txt", O_RDONLY);
	while (i < 1)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close (fd); 
	return (0);
}
 */

/*  int main(void)
 {
	printf("%s", ft_substr("Granda Pota!", 3));
	return (0);
 } */