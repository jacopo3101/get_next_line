/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:58:52 by javellis          #+#    #+#             */
/*   Updated: 2022/10/26 09:58:55 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*ft_line_builder(char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
		return (buf);
	line = (char *)malloc(i + 2);
	while (buf[i] && i > j)
	{
		line[j] = buf[j];
		j++;
	}
	line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_set_new_mem(char *mem, int i)
{
	char	*new_mem;
	int		j;

	j = 0;
	while (mem[j])
		j++;
	new_mem = malloc(j - ++i + 1);
	if (!new_mem)
		return (NULL);
	new_mem[j - i] = '\0';
	j = 0;
	while (mem[i])
		new_mem[j++] = mem[i++];
	free(mem);
	if (!new_mem[0])
	{
		free(new_mem);
		return (NULL);
	}
	return (new_mem);
}

char	*ft_set_mem(char *mem)
{
	int		i;

	i = 0;
	if (!ft_strchr(mem, '\n'))
		return (NULL);
	while (mem[i] && mem[i] != '\n')
		i++;
	if (!mem[i])
	{
		free(mem);
		return (NULL);
	}
	return (ft_set_new_mem(mem, i));
}

char	*ft_read_buf(int fd, char *mem)
{
	char	*buffer;
	int		buf_read;

	buf_read = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && buf_read != 0)
	{
		buf_read = read(fd, buffer, BUFFER_SIZE);
		if (buf_read <= 0)
		{
			free(buffer);
			if (buf_read == 0)
				return (mem);
			return (NULL);
		}
		buffer[buf_read] = '\0';
		mem = ft_strjoin(mem, buffer);
	}
	free(buffer);
	return (mem);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	mem = ft_read_buf(fd, mem);
	if (!mem)
	{
		return (NULL);
	}
	line = ft_line_builder(mem);
	mem = ft_set_mem(mem);
	return (line);
}
/*
int main()
{
	int fd = open("files/giant_line.txt", O_RDWR);
	char *line = get_next_line(fd);
	printf("%s", line);
	//printf("\n-------------------------\n");
	line = get_next_line(fd);
	printf("%s", line);
	
	
}*/
