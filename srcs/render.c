/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:22:29 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/07 15:01:45 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_tile(t_tile tile, t_info info, t_vector pos)
{
	mlx_put_image_to_window(info.mlx_p, info.window_p, info.back, pos.x, pos.y);
	if (tile.symbol == '1')
		mlx_put_image_to_window(info.mlx_p, info.window_p, info.wall_image.ptr_image, pos.x, pos.y);
	if (tile.symbol == 'P')
		mlx_put_image_to_window(info.mlx_p, info.window_p, info.player.idle_img_0, pos.x, pos.y);
	if (tile.symbol == 'E')
	 	mlx_put_image_to_window(info.mlx_p, info.window_p, info.exit_door.ptr_image, pos.x, pos.y);
	if (tile.symbol == 'C')
		mlx_put_image_to_window(info.mlx_p, info.window_p, info.collectible, pos.x, pos.y);
}

void	render(t_info **info_p)
{
	t_tile	**tilemap;
	t_tile	tile;
	t_info	*info;
	int		x;
	int		y;

	info = *info_p;
	tilemap = info->tile_array;
	mlx_clear_window(info->mlx_p, info->window_p);
	y = 0;
	// printf("%d %d\n", info->map_height, info->map_width);
	while (y <= info->map_height)
	{
		x = 0;
		while (x < info->map_width)
		{
			tile = tilemap[y][x];
			render_tile(tile, **info_p, tile.position);
			x++;
		}
		y++;
	}
}