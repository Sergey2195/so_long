/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:02:59 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/10 19:26:53 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**write_map(t_info **info, char *str)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * ((*info)->map_height + 1));
	i = 0;
	while (i < (*info)->map_height)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			error_signal(*info, 5);
		i++;
	}
	close(fd);
	map[i] = NULL;
	(*info)->map_width = ft_strlen(map[0]);
	return (map);
}

int	line_count_f(t_info **info, char *arg)
{
	int		fd;
	int		count;
	int		r;
	char	buff;

	count = 1;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error_signal(*info, 1);
	(*info)->map_width = 0;
	while (1)
	{
		r = read(fd, &buff, 1);
		if (r == 0)
			break ;
		if (r == -1)
			error_signal(*info, 1);
		if (buff == '\n')
			count++;
	}
	close(fd);
	return (count);
}

void	check_rectangle(t_info **info)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (**info).map;
	while (i < (*info)->map_height)
	{
		if (i == (*info)->map_height - 1)
			j = ft_strlen(map[i]) + 1;
		else
			j = ft_strlen(map[i]);
		if (j != (*info)-> map_width)
			error_exit("Invalid map\n", *info);
		i++;
	}
}

void	map_init(t_info **info, char *arg)
{
	int		line_count;
	char	**map;

	line_count = line_count_f(info, arg);
	if (line_count == 0)
		error_exit("Invalid map\n", *info);
	(*info)->map_height = line_count;
	map = write_map(info, arg);
	(*info)->map = map;
	check_map(info);
	check_rectangle(info);
	(*info)->tile_array = init_tile_array(info);
}
