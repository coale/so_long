/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:53:14 by aconta            #+#    #+#             */
/*   Updated: 2023/04/04 15:36:38 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

char	*ft_joinstr(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 1;
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(*str));
		str[0] = '\0';
	}
	j = ft_strlen(str) + ft_strlen(buff);
	if (!str || !buff)
		return (NULL);
	new_str = malloc((j + 1) * sizeof(*new_str));
	if (new_str == NULL)
		return (NULL);
	if (str)
		while (*str != '\0' && i++)
			*(new_str++) = *(str++);
	while (*buff != '\0')
		*(new_str++) = *(buff++);
	*new_str = '\0';
	str -= (i - 1);
	free(str);
	return (new_str - j);
}

char	*read_the_file(int fd, char *save)
{
	char	*buf;
	int		read_bytes;

	buf = malloc(sizeof (char) *(BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		save = ft_joinstr(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_a_line(char *save)
{
	int		i;
	char	*potential_line;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	potential_line = (char *)malloc(sizeof(*potential_line) * (i + 2));
	if (!potential_line)
		return (NULL);
	i = -1;
	while (save[++i] != '\n' && save[i])
		potential_line[i] = save[i];
	if (save[i] == '\n')
	{
		potential_line[i] = '\n';
		i++;
	}
	potential_line[i] = '\0';
	return (potential_line);
}

char	*save_after_newline(char *save)
{
	char	*newsave;
	int		i;
	int		j;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	newsave = malloc(sizeof (char) * (ft_strlen(save) - i + 1));
	if (!newsave)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		newsave[j++] = save[i++];
	newsave[j] = '\0';
	free(save);
	return (newsave);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = read_the_file(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = get_a_line(save[fd]);
	save[fd] = save_after_newline(save[fd]);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
