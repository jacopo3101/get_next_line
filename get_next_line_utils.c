/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:59:19 by javellis          #+#    #+#             */
/*   Updated: 2022/10/26 09:59:22 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stddef.h>
#include<stdlib.h>
#include<stdio.h>

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	int		i;
	char	*c;
	i = 0;
	c = malloc(nmemb * size);
	while ((unsigned int)i < nmemb)
	{
		c[i] = 0;
		i++;
	}
	return (c);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	while (i < len + 1)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	size = ft_strlen(s2) + ft_strlen(s1) + 1;
	//printf("%d",ft_strlen(s1));
	str = (char *)malloc(size);
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	//printf("%s*", str);
	free(s1);
	return (str);
}
