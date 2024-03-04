/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:25:31 by gabpicci          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:20 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			i;
	char		*line;

	i = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		i = 0;
		while (buffer[i])
			buffer[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (i)
	{
		if (!buffer[0])
			i = read(fd, buffer, BUFFER_SIZE);
		if (i > 0)
			line = ft_strconcat(line, buffer);
		if (nl_buff_clear(buffer))
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