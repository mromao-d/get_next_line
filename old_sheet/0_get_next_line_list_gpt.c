#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>

typedef struct s_list {
    char c;
    struct s_list *next;
} t_list;

t_list *new_node(char c) {
    t_list *node = (t_list*)malloc(sizeof(t_list));
    node->c = c;
    node->next = NULL;
    return node;
}

t_list *add_node(t_list *head, char c) {
    if (head == NULL) {
        return new_node(c);
    } else {
        t_list *node = head;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = new_node(c);
        return head;
    }
}

char *ft_get_next_line(int fd) {
    char c;
    t_list *head = NULL;
    while (read(fd, &c, 1) > 0) {
        head = add_node(head, c);
        if (c == '\n') {
            break;
        }
    }
    int size = 0;
    t_list *node = head;
    while (node != NULL) {
        size++;
        node = node->next;
    }
    char *line = (char*)malloc(size + 1);
    int i = 0;
    node = head;
    while (node != NULL) {
        line[i++] = node->c;
        t_list *temp = node;
        node = node->next;
        free(temp);
    }
    line[i] = '\0';
    return line;
}


int	main(void)
{
	int fd;
	int i;

	i = 0;
	fd = open("foobar2.txt", O_RDONLY);
	while (i < 40)
	{
		printf("%s", ft_get_next_line(fd));
		i++;
	}
	close (fd);
	return (0);
}