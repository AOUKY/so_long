/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:09:23 by haouky            #+#    #+#             */
/*   Updated: 2024/05/24 17:52:27 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int n)
{
	ft_putstr_fd("Error:", 2);
	if (n == 0)
		ft_putstr_fd(" ./so_long (filename).ber\n", 2);
	if (n == 1)
		ft_putstr_fd(" wrong file\n", 2);
	if (n == 2)
		ft_putstr_fd(" invaid map (charachter != (P,C,E) )\n", 2);
	if (n == 3)
		ft_putstr_fd(" invaid map (the wall)\n", 2);
	if (n == 4)
		ft_putstr_fd(" invaid map (number of charachter is not right)\n", 2);
	if (n == 5)
		ft_putstr_fd(" invaid map (no acces to the coins or the exit)\n", 2);
	if (n == 6)
		ft_putstr_fd(" invaid map (the map is too big)\n", 2);
	exit(1);
}

void	ffld(char **map, int i, int j)
{
	if (map[i][j] == '1')
		return ;
	map[i][j] = '1';
	ffld(map, i - 1, j);
	ffld(map, i, j - 1);
	ffld(map, i + 1, j);
	ffld(map, i, j + 1);
}

int	chek(char *v)
{
	int	i;

	i = 0;
	while (v[i])
		i++;
	if (v[i - 1] != 'r' || v[i - 2] != 'e' || v[i - 3] != 'b' 
		|| v[i - 4] != '.')
		ft_error(1);
	return (1);
}

void	pimag(t_long *strct, int i, int j, char *v)
{
	strct->texture = mlx_load_png(v);
	if (!strct->texture)
		ft_mlx_error();
	strct->image = mlx_texture_to_image(strct->mlx, strct->texture);
	mlx_delete_texture(strct->texture);
	if (!strct->image)
		ft_mlx_error();
	if (mlx_image_to_window(strct->mlx, strct->image, j * 64, i * 64) < 0)
		ft_mlx_error();
}
