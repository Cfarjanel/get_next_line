/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:47:29 by cfarjane          #+#    #+#             */
/*   Updated: 2018/03/07 17:30:23 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_read(char *str, int fd)
{
	int		i;
	int		ret;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		else
		{
			tmp = str;
			str = ft_strjoin(tmp, buff);
			ft_strdel(&tmp);
		}
	}
	return (str);
}

static int		error(int fd, char **str, char **line)
{
	if (fd < 0 || line == NULL || read(fd, &str, 0) == -1)
		return (-1);
	if (!(*line = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	return (0);
}

static char		*ft_strccpy(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	while (str[i] && str[i] != c)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*tmp;
	int			i;

	if (error(fd, &str, line) == -1)
		return (-1);
	if (str)
		ft_strcpy(*line, str);
	else
		str = ft_read(*line, fd);
	i = 0;
	if (str[i])
	{
		while (str[i] && str[i] != '\n' && str[i + 1] != '\0')
			i++;
		if (i == 0)
			*line = ft_strdup("");
		else
		{
			*line = ft_strccpy(str, '\n');
			tmp = str;
			str = ft_strdup(&str[i + 1]);
			free(tmp);
		}
		return (1);
	}
	return (0);
}
