/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:47:41 by javellis          #+#    #+#             */
/*   Updated: 2022/11/02 14:47:44 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_buf(int fd, char *mem);
int		ft_strlen(const char *s);
char	*ft_set_mem(char *mem);
char	*ft_line_builder(char *buf);
void	*ft_calloc(unsigned int nmemb, unsigned int size);
char	*ft_set_new_mem(char *mem, int i);

#endif
