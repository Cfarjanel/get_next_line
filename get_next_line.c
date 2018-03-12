/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:47:29 by cfarjane          #+#    #+#             */
/*   Updated: 2018/03/12 19:35:44 by cfarjane         ###   ########.fr       */
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
	str = NULL;
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

static char		*ft_strccpy(char *str, char c)
{
	char	*new;
	int		i;

	if (!str)
		return (NULL);
	i = ft_strchr(str, c) ? (int)(ft_strchr(str, c) - str) : ft_strlen(str);
	if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
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

	if (fd < 0 || line == NULL || read(fd, str, 0) == -1)
		return (-1);
	if (!str)
		str = ft_read(*line, fd);
	i = 0;
	if (str && str[i])
	{
		while (str[i] && str[i] != '\n' && str[i + 1] != '\0')
			i++;
		*line = ft_strccpy(str, '\n');
		tmp = str;
		if (*(str + i + 1))
			str = ft_strdup(&str[i + 1]);
		else
			str = NULL;
		free(tmp);
		return (1);
	}
	str = NULL;
	return (0);
}
