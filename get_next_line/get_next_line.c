/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:06:06 by mmark             #+#    #+#             */
/*   Updated: 2019/05/08 21:08:30 by mmark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char		*str[1024];
	int				flag;

	if (fd < 0 || line == NULL)
		return (-1);
	flag = get_strbuf(fd, str);
	if (flag < 0)
		return (-1);
	return (get_new_line(fd, flag, line, str));
}

int		get_strbuf(const int fd, char **str)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*s;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buf);
		else
		{
			s = ft_strjoin(str[fd], buf);
			free(str[fd]);
			str[fd] = s;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (ret);
}

int		get_new_line(const int fd, int flag, char **line, char **str)
{
	int		i;

	if (flag == 0 && (str[fd] == NULL))
	{
		*line = NULL;
		return (0);
	}
	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
		get_new_n(fd, i, line, str);
	else
	{
		if (flag == BUFF_SIZE)
			get_next_line(fd, line);
		else
		{
			*line = ft_strdup(str[fd]);
			ft_strdel(&str[fd]);
		}
	}
	return (1);
}

int		get_new_n(const int fd, int i, char **line, char **str)
{
	char	*buf;

	*line = ft_strsub(str[fd], 0, i);
	buf = ft_strdup(str[fd] + i + 1);
	free(str[fd]);
	str[fd] = buf;
	if (str[fd][0] == '\0')
		ft_strdel(&str[fd]);
	return (0);
}
