/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:32:09 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/06 17:34:05 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_extension(char *str, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	if (i <= 4)
		error_exit("Map extension must be .ber\n", info);
	if (!ft_strnstr(str + (ft_strlen(str) - 4), ".ber", 4))
		error_exit("Map extension must be .ber\n", info);
}

void	check_args_init_map(int argc, char **argv, t_info **info)
{
	int		fd;
	int		i;
	char	**map;

	i = 0;
	if (argc < 2)
		error_exit("No map", *info);
	if (argc > 2)
		error_exit("Too many arguments", *info);
	check_extension(argv[1], *info);
	map_init(*info, argv[1]);	
}