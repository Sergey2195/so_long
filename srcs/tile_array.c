/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:20:09 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/10 18:58:39 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_tile	**malloc_tile_array(t_info *info)
{
	t_tile	**tile_arr;
	int		i;

	tile_arr = NULL;
	tile_arr = (t_tile **)malloc(sizeof(t_tile *) * (info->map_height) + 1);
	if (!tile_arr)
		error_exit("Malloc error\n", info);
	i = 0;
	while (i < info->map_height)
	{
		tile_arr[i] = (t_tile *)malloc(sizeof(t_tile) * info->map_width + 1);
		i++;
	}
	return (tile_arr);
}

void	set_neighbours(t_tile **tile_arr, int x, int y, t_info info)
{
	tile_arr[y][x].position.x = x * IMG_SIZE;
	tile_arr[y][x].position.y = y * IMG_SIZE;
	if (y != 0)
		tile_arr[y][x].up = &tile_arr[y - 1][x];
	if (y != info.map_height)
		tile_arr[y][x].down = &tile_arr[y + 1][x];
	if (x != 0)
		tile_arr[y][x].left = &tile_arr[y][x - 1];
	if (x != info.map_width - 1)
		tile_arr[y][x].right = &tile_arr[y][x + 1];
}

void	analysis_tile(t_tile *tile, t_info **info_p)
{
	t_info	*info;

	info = *info_p;
	if (tile->symbol == 'P')
		info->player.tile = tile;
}

t_tile	**init_tile_array(t_info **info)
{
	t_tile	**tile_arr;
	char	**map;
	int		x;
	int		y;	

	tile_arr = malloc_tile_array(*info);
	y = 0;
	map = (*info)->map;
	while (y < (*info)->map_height)
	{
		x = 0;
		while (x < (*info)->map_width)
		{
			tile_arr[y][x].symbol = map[y][x];
			set_neighbours(tile_arr, x, y, **info);
			analysis_tile(&tile_arr[y][x], info);
			x++;
		}
		y++;
	}
	tile_arr[y] = NULL;
	(*info)->window_height = y * 64;
	(*info)->window_width = x * 64;
	return (tile_arr);
}
