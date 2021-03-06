/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 01:02:15 by jaewonki          #+#    #+#             */
/*   Updated: 2022/05/06 01:02:15 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_file(int fd, char *save)
{
	ssize_t	nread;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	nread = read(fd, buf, BUFFER_SIZE);
	while (nread > 0)
	{
		buf[nread] = '\0';
		tmp = save;
		save = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(save, '\n') || !save)
			break ;
		nread = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	buf = NULL;
	if (nread < 0)
		return (NULL);
	return (save);
}

static char	*get_line(char *save)
{
	char	*line;
	size_t	i;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
		++i;
	if (save[i] == '\n')
		++i;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		line[i] = save[i];
		++i;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = read_file(fd, save);
	if (!save)
		return (NULL);
	if (*save)
	{
		line = get_line(save);
		if (!line)
			return (NULL);
		tmp = save;
		save = ft_strdup(save + ft_strlen(line));
		free(tmp);
		tmp = NULL;
		if (!save)
			return (NULL);
		return (line);
	}
	free(save);
	save = NULL;
	return (NULL);
}