/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:23:23 by lanachaineu       #+#    #+#             */
/*   Updated: 2021/08/12 13:29:40 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (is_break(*line))
		return (1);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret)
	{
		if (ret == (-1))
			return (-1);
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		if (!*line)
			return (-1);
		if (is_break(*line))
			return (1);
		ret = read(fd, buf, BUFFER_SIZE);
	}
	return (0);
}

char	*before_break(char *line)
{
	int		i;
	char	*line_bis;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	line_bis = (char *)malloc(sizeof(char) * (i + 1));
	if (!line_bis)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		line_bis[i] = line[i];
		i++;
	}
	line_bis[i] = '\0';
	return (line_bis);
}

char	*after_break(char *line)
{
	int		i;
	int		j;
	char	*line_bis;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	line_bis = (char *)malloc(sizeof(char)
			* (ft_strlen(line) - i + 1));
	if (!line_bis)
		return (0);
	while (line[i])
		line_bis[j++] = line[i++];
	line_bis[j] = '\0';
	free(line);
	return (line_bis);
}

int	get_next_line(int fd, char **line)
{
	static char	*new_line;
	int			rep;

	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	if (!new_line)
	{
		new_line = (char *)malloc(sizeof(char));
		if (!new_line)
			return (-1);
		new_line[0] = '\0';
	}
	rep = read_line(fd, &new_line);
	*line = before_break(new_line);
	if (!*line)
		return (-1);
	if (rep == 1)
		new_line = after_break(new_line);
	else
	{
		free(new_line);
		new_line = 0;
	}
	return (rep);
}
