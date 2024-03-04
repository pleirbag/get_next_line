/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:25:44 by gabpicci          #+#    #+#             */
/*   Updated: 2023/05/11 21:17:42 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strconcat(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = -1;
	if (!s2)
		return (0);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		dest[i++] = s2[j];
		if (s2[j] == '\n' || !s2[j])
			break ;
	}
	dest[i] = 0;
	free(s1);
	return (dest);
}

int	nl_buff_clear(char *str)
{
	int	i;
	int	j;
	int	new_line;

	i = 0;
	j = 0;
	new_line = 0;
	while (str[i] && str[i] != '\n')
		str[i++] = 0;
	if (str[i] == '\n')
	{
		new_line = 1;
		str[i++] = 0;
		while (str[i] != 0)
		{
			str[j++] = str[i];
			str[i++] = 0;
		}
	}
	return (new_line);
}
