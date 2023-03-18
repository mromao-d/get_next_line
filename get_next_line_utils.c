/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:42:35 by mromao-d          #+#    #+#             */
/*   Updated: 2023/03/18 19:03:09 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char  *str)
{
	int i;

	i = 0;
	if (!str || str[0] == 0)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_lb_pos(char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == 0 || s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	if (s[i] == '\n')
		return (i + 1);
	return (0);
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
	/* free(temp); */
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*output;
	int		keep_size;

	if (!s1 || !s2 )
		return(NULL);
	i = 0;
	keep_size = ft_strlen(s2);
	output = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if(!output)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		output[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + keep_size && *s2)
	{
		output[i] = *s2++;
		i++;
	}
	/* free(s1);
	s1 = 0; */
	output[i] = '\0';
	return (output);
}
