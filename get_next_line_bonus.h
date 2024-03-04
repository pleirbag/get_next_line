/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:35:10 by gabpicci          #+#    #+#             */
/*   Updated: 2023/05/11 21:24:26 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		nl_buff_clear(char *str);

char	*ft_strconcat(char *s1, char *s2);

int		ft_strlen(const char *str);

char	*get_next_line(int fd);

int		ft_find_nl(char *str);

char	*ft_strjoin(char *s1, char *s2);

#endif