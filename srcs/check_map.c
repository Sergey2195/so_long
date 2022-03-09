/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:29:59 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/09 19:19:34 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_str_fl(char *str, t_info *info)
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

int	check_vars(t_map_check check, t_info **info_p)
{
	if (check.map_start != 1 || check.map_collect < 1 || check.map_exit != 1)
		return (-1);
	else
	{
		(**info_p).number_of_collect = check.map_collect;
		return (1);
	}
}

t_map_check	*malloc_checker(t_info **info_p)
{
	t_map_check	*check;

	check = (t_map_check *)malloc(sizeof(t_map_check));
	if (!check)
		error_exit("Malloc error\n", *info_p);
	check->map_collect = 0;
	check->map_exit = 0;
	check->map_start = 0;
	return (check);
}

void	check_map(t_info **info_p)
{
	t_map_check	*check;
	int			i;
	char		**map;

	check = malloc_checker(info_p);
	i = 0;
	map = (**info_p).map;
	while (i <= (**info_p).map_height)
	{
		if (i == 0 || i == (**info_p).map_height)
		{
			if (check_str_fl(map[i], *info_p) == -1)
				error_exit("The map must be closed by walls\n", *info_p);
		}
		else
			if (check_intermed(map[i], check, *info_p) == -1)
				error_exit("Walls error or invalid symbols\n", *info_p);
		i++;
	}
	if (check_vars(*check, info_p) == -1)
	{
		free(check);
		error_exit("Not valid map: C >= 1, 1 E, 1 P\n", *info_p);
	}
	free(check);
}
