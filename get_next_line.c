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
	int	i;
	int	j;
	char	*line;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
		return (NULL);
	line = (char *)malloc(i + 2);
	while(buf[i] && i > j)
	{
		line[j] = buf[j];
		j++;
	}
	line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_set_mem(char *mem)
{
	int	i;
	int	j;
	char	*new_mem;

	i = 0;
	j = 0;
	if (!ft_strchr(mem, '\n'))
		return (NULL);
	while (mem[i] && mem[i] != '\n')
		i++;
	if (mem[i] == '\0')
	{
		free(mem);
		return (NULL);
	}
	while (mem[j])
		j++;
	new_mem = malloc(j - ++i + 1);
	j = 0;
	while (mem[i])
	{
		new_mem[j] = mem[i];
		i++;
		j++;
	}
	free(mem);
	return (new_mem);
}

char	*ft_read_buf(int fd, char *mem)
{
	char	*buffer;
	int	buf_read;

	buf_read = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && buf_read != 0)
	{
		buf_read = read(fd, buffer, BUFFER_SIZE);
		if (buf_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[buf_read] = '\0';
		mem = ft_strjoin(mem, buffer);
		//printf("%s\n", buffer);
	}
	free(buffer);
	return (mem);
}
//ciaoComeStai \n 1
//clear && gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c
char *get_next_line(int fd)
{
	static char	*mem;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	mem = ft_read_buf(fd, mem);
	if (!mem)
		return (NULL);
	line = ft_line_builder(mem);
	//printf("1 :%s\n",mem);
	mem = ft_set_mem(mem);
	//printf("2 :%s\n",mem);
	return (line);
}
/*
int main()
{
	int fd = open("empty.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
}*/
