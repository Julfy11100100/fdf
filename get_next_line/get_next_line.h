/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:08:01 by mmark             #+#    #+#             */
/*   Updated: 2019/05/24 22:53:41 by mmark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 4

int		get_next_line(const int fd, char **line);
int		get_new_line(const int fd, int flag, char **line, char **str);
int		get_strbuf(const int fd, char **str);
int		get_new_n(const int fd, int i, char **line, char **str);

#endif
