#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>

#define BUFFER_SIZE 50

char *ft_get_next_line(int fd) {
   static char buffer[BUFFER_SIZE];  // static buffer to store data
   static int pos = BUFFER_SIZE;  // current position in the buffer
    int end = BUFFER_SIZE;  // end of data in the buffer

   // allocate memory for the line
   char *line = malloc((sizeof(char)) * BUFFER_SIZE);
   int line_pos = 0;  // current position in the line

   // read data from the file descriptor until a newline is encountered
   while (1) 
   {
	  // if the buffer is empty, refill it
	  
	  if (pos >= end) 
	  {
		 pos = 0;
		 end = read(fd, buffer, BUFFER_SIZE);
		 
		 if (end == 0) 
		 {  // end of file
			if (line_pos == 0) 
			{  // no data was read
			   free(line);
			   return NULL;
			} 
			else 
			{  // return the line
		  		break;
			}
		}
	  }

	  // add the next character to the line
	  char ch = buffer[pos++];
	  line[line_pos++] = ch;
	  if (ch == '\n') {  // end of line
			break;
	  }
   }

   // null terminate the string
   line[line_pos] = '\0';
	/* printf("\nbuffer is: %s\n",buffer); */
   return line;
}

int	main(void)
{
	int fd;
	int i;

	i = 0;
	fd = open("foobar4.txt", O_RDONLY);
	while (i < 9)
	{
		printf("%s", ft_get_next_line(fd));
		i++;
	}
	close (fd);
	return (0);
}