/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:52:48 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/07 18:10:04 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_to_empty(t_info *info, t_tile *tile)
{
	tile->symbol = 'P';
	if (info->player.tile->symbol != 'E')
	 	info->player.tile->symbol = 'E';
	info->player.tile = tile;
}


int	move_to(t_info *info, t_tile *tile)
{
	if (tile->symbol == '0')
		move_to_empty(info, tile);
	else
		printf("loh");
	return (0);
	
}

int	button_press(int button, t_info **info_p)
{
	int		flag;
	t_info	*info;
	
	info = *info_p;
	if (button == 53)
	{
		//freeall;
		exit(1);
	}
	if (button == 15)
	{
		//obrabotat
		exit(1);
	}
	// 	return (reset(info));
	// if (info->player.tile == NULL)
	// // 	return (0);
	if (button == 13)
	{
		flag = move_to(*info_p, info->player.tile->up);
	}
	info_p = &info;
	
	
	// else if (key == KEY_DOWN)
	// 	moved = move_to(info, info->player.tile->down);
	// else if (key == KEY_LEFT)
	// 	moved = move_to(info, info->player.tile->left);
	// else if (key == KEY_RIGHT)
	// 	moved = move_to(info, info->player.tile->right);
	// else
	// 	return (0);
	// if (moved)
	// 	printf("Moves -> %02d\n", ++info->moves);
	return (1);
}