/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:37:33 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/09 19:49:00 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_ptr_images(t_info **info_p)
{
	
	(*info_p)->collectible = mlx_xpm_file_to_image((*info_p)->mlx_p,
			"images/collect.xpm", &(*info_p)->img_size.x, &(*info_p)->img_size.y);
	(*info_p)->back = mlx_xpm_file_to_image((*info_p)->mlx_p, "images/back.xpm",
			&(*info_p)->img_size.x, &(*info_p)->img_size.y);
	(*info_p)->exit_door.door_close = mlx_xpm_file_to_image((*info_p)->mlx_p,
			"images/door1.xpm", &(*info_p)->img_size.x, &(*info_p)->img_size.y);
	(*info_p)->exit_door.door_open = mlx_xpm_file_to_image((*info_p)->mlx_p,
			"images/door2.xpm", &(*info_p)->img_size.x, &(*info_p)->img_size.y);
	(*info_p)->player.player_img = mlx_xpm_file_to_image((*info_p)->mlx_p,
			"images/boris1.xpm", &(*info_p)->img_size.x, &(*info_p)->img_size.y);
	(*info_p)->wall = mlx_xpm_file_to_image((*info_p)->mlx_p,
			"images/wall.xpm", &(*info_p)->img_size.x, &(*info_p)->img_size.y);
}
