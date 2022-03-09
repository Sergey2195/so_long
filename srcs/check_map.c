/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:29:59 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/24 13:49:23 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_str_fl(char *str, t_map_check *check, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->map_width)
	{
		if (str[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	check_intermed(char *str, t_map_check *check, t_info *info)
{
	int	i;

	i = 1;
	if (str[0] != '1' || str[info->map_width - 1] != '1')
		return (-1);
	while (i < info->map_width)
	{
		if (str[i] == 'C')
			check->map_collect++;
		else if (str[i] == 'E')
			check->map_exit++;
		else if (str[i] == 'P')
			check->map_start++;
		else
		{
			if (str[i] != '0' && str[i] != '1')
				return (-1);
		}
		i++;
	}
	return (1);
}

void	check_map(t_info *info)
{
	t_map_check	*check;
	int			i;
	char		**map;

	// check = NULL;
	// check = (t_map_check *)malloc(sizeof(t_map_check));
	// if (!check)
	// 	error_exit("Malloc error\n", info);
	// check->map_collect = 0;
	// check->map_exit = 0;
	// check->map_start = 0;
	// i = 0;
	// map = info->map;
	// while (i <= info->map_height)
	// {
	// 	if (i == 0 || i == info->map_height)
	// 		if (check_str_fl(map[i], check, info) == -1)
	// 			error_exit("Not valid map\n", info);
	// 	else
	// 		if (check_intermed(map[i], check, info) == -1)
	// 			error_exit("Not valid map\n", info);
	// 	i++;
	// }
	// //analysis check
	// free(check);
}
