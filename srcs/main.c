/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:14:36 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/07 17:34:24 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_init(t_info **info_p)
{
	t_info	*info;

	info = *info_p;
	info->mlx_p = mlx_init();
	info->window_p = mlx_new_window(info->mlx_p, info->window_width, info->window_height, "so_long");
	mlx_hook(info->window_p, 17, 0, finish, info);
	info_p = &info;
	get_ptr_images(info_p);
	//2 panelki
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = NULL;
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		error_exit("Malloc error", info);
	check_args_init_map(argc, argv, &info);
	//anim_setup
	game_init(&info);
	mlx_hook(info->window_p, 2, 0, button_press, &info);
	mlx_loop_hook(info->mlx_p, update, info);
	mlx_loop(info->mlx_p);
	return (0);
}
// for (size_t i = 0; i <= info->map_height; i++)
// 		{
// 			for (size_t z = 0; z < info->map_width; z++)
// 			{
// 				printf("%c", info->tile_array[i][z].symbol);
// 			}
// 			printf("\n");
// 		}