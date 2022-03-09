/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:02:59 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/06 12:51:10 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	c_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

char	**write_map(t_info *info, char *str)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (info->map_height + 1));
	i = 0;
	while (i <= info->map_height)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
		{
			info->map_height--;
			break ;
		}
		if (c_line(map[i]) != info->map_width)
			error_exit("The map must be a rectangle\n", info);
		i++;
	}
	close(fd);
	return (map);
}

int	line_count_f(t_info *info, char *arg)
{
	int		fd;
	int		count;
	int		r;
	char	buff;

	count = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error_exit("Map fd error\n", info);
	info->map_width = 0;
	while (1)
	{
		r = read(fd, &buff, 1);
		if (r == 0)
			break ;
		if (r == -1)
			error_exit("Reading error\n", info);
		if (count == 0 && buff != '\n')
			info->map_width++;
		if (buff == '\n')
			count++;
	}
	close(fd);
	return (count);
}

void	map_init(t_info *info, char *arg)
{
	int		fd;
	int		line_count;
	char	**map;

	line_count = line_count_f(info, arg);
	if (line_count == 0)
		error_exit("Map error\n", info);
	info->map_height = line_count;
	map = write_map(info, arg);
	info->map = map;
	check_map(info); //dodelat
	info->tile_array = init_tile_array(info);
}
