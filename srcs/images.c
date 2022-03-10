/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:37:33 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/10 16:17:49 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_ptr_images(t_info **a)
{
	(*a)->collectible = mlx_xpm_file_to_image((*a)->mlx_p,
			"images/collect.xpm", &(*a)->img_size.x, &(*a)->img_size.y);
	(*a)->back = mlx_xpm_file_to_image((*a)->mlx_p, "images/back.xpm",
			&(*a)->img_size.x, &(*a)->img_size.y);
	(*a)->exit_door.door_close = mlx_xpm_file_to_image((*a)->mlx_p,
			"images/door1.xpm", &(*a)->img_size.x, &(*a)->img_size.y);
	(*a)->exit_door.door_open = mlx_xpm_file_to_image((*a)->mlx_p,
			"images/door2.xpm", &(*a)->img_size.x, &(*a)->img_size.y);
	(*a)->player.player_img = mlx_xpm_file_to_image((*a)->mlx_p,
			"images/boris1.xpm", &(*a)->img_size.x, &(*a)->img_size.y);
	(*a)->wall = mlx_xpm_file_to_image((*a)->mlx_p,
			"images/wall.xpm", &(*a)->img_size.x, &(*a)->img_size.y);
}
