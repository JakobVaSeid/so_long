/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:30:41 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/20 16:33:04 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_newline(char *str)
{
	if (str && ft_strlen(str) > 0 \
		&& str[ft_strlen(str) - 1] == '\n')
		return (0);
	else
		return (1);
}

void	double_free(char *s1, char *s2, int fd, t_game *so_long)
{
	free(s1);
	free(s2);
	while (1)
	{
		s1 = get_next_line(fd);
		if (s1 != NULL)
			free(s1);
		else
			break ;
	}
	ft_error("Invalid map", so_long);
}

void	single_free(char *s1, t_game *so_long)
{
	free(s1);
	ft_error("Invalid map", so_long);
}

char	*get_map_temp(t_game *so_long, char *map_temp, int fd)
{
	char	*line_temp;
	char	*tmp;

	while (1)
	{
		line_temp = get_next_line(fd);
		if (!line_temp)
			single_free(map_temp, so_long);
		if (line_temp && line_temp[0] == '\n')
			double_free(line_temp, map_temp, fd, so_long);
		tmp = ft_strjoin(map_temp, line_temp);
		if (!tmp)
			double_free(map_temp, line_temp, fd, so_long);
		free(map_temp);
		map_temp = tmp;
		so_long->rows++;
		if (check_for_newline(line_temp) == 1)
		{
			free(line_temp);
			break ;
		}
		free(line_temp);
		line_temp = 0;
	}
	return (map_temp);
}

void	init_map(t_game *so_long, char *argv)
{
	char	*map_temp;
	char	*filextension;

	filextension = ft_strrchr(&argv[1], '.');
	if (filextension && (ft_strncmp(filextension, ".ber", 4) == 0 \
		&& ft_strlen(filextension) == 4))
	{
		so_long->fd = open(argv, O_RDONLY);
		if (so_long->fd < 0)
			ft_error("Couldn't read map!", so_long);
		map_temp = ft_strdup("");
		if (!map_temp)
			ft_error("Error!", so_long);
		map_temp = get_map_temp(so_long, map_temp, so_long->fd);
		if (!map_temp)
			single_free(map_temp, so_long);
		if (close(so_long->fd))
			single_free(map_temp, so_long);
		so_long->map = ft_split(map_temp, '\n');
		if (so_long->map == NULL)
			single_free(map_temp, so_long);
		free(map_temp);
	}
	else
		ft_error("Error!", so_long);
}
