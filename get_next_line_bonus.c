/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:25:31 by gabpicci          #+#    #+#             */
/*   Updated: 2023/05/11 21:26:28 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			i;
	char		*line;

	i = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		i = -1;
		while (buffer[fd][++i])
			buffer[fd][i] = 0;
		return (NULL);
	}
	line = NULL;
	while (i)
	{
		if (!buffer[fd][0])
			i = read(fd, buffer[fd], BUFFER_SIZE);
		if (i > 0)
			line = ft_strconcat(line, buffer[fd]);
		if (nl_buff_clear(buffer[fd]))
			break ;
	}
	return (line);
}

// int main()
// {
// 	int i = open("test.txt", 0);
// 	char *s;
// 	while ((s = get_next_line(i)))
// 	{
// 		printf("%s", s);
// 	}
// 	return (0);
// }