#ifndef get_next_line
# define get_next_line
# define BUFFER_SIZE 100

#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>

struct node 
{
   char         *content;
   struct       node *next;
}              t_list;


int     ft_strlen(char *str);
char    *ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_next_line(int fd);


#endif