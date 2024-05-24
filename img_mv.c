/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_mv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:58:05 by haouky            #+#    #+#             */
/*   Updated: 2024/05/24 17:16:49 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_ground(t_long *strct)
{
	strct->mlx = mlx_init(strct->y * 64, strct->x * 64, "so_long", 0);
	if (!strct->mlx)
		ft_mlx_error();
	strct->i = 0;
	while (strct->map[strct->i])
	{
		strct->j = 0;
		while (strct->map[strct->i][strct->j]
			&& strct->map[strct->i][strct->j] != '\n')
		{
			strct->texture = mlx_load_png("textures/ground.png");
			if (!strct->texture)
				ft_mlx_error();
			strct->image = mlx_texture_to_image(strct->mlx, strct->texture);
			mlx_delete_texture(strct->texture);
			if (!strct->image)
				ft_mlx_error();
			if (mlx_image_to_window(strct->mlx, strct->image, strct->j * 64,
					strct->i * 64) < 0)
				ft_mlx_error();
			strct->j++;
		}
		strct->i++;
	}
}

void	put_image(t_long *strct)
{
	strct->j = 0;
	while (strct->map[strct->i][strct->j]
		&& strct->map[strct->i][strct->j] != '\n')
	{
		if (strct->map[strct->i][strct->j] == 'E')
			strct->texture = mlx_load_png("textures/dart.png");
		else if (strct->map[strct->i][strct->j] == '1')
			strct->texture = mlx_load_png("textures/wallt.png");
		else if (strct->map[strct->i][strct->j] == '0'
				|| strct->map[strct->i][strct->j] == 'P')
			strct->texture = mlx_load_png("textures/ground.png");
		else if (strct->map[strct->i][strct->j] == 'C')
			strct->texture = mlx_load_png("textures/coins.png");
		if (!strct->texture)
			ft_mlx_error();
		strct->image = mlx_texture_to_image(strct->mlx, strct->texture);
		mlx_delete_texture(strct->texture);
		if (!strct->image)
			ft_mlx_error();
		if (mlx_image_to_window(strct->mlx, strct->image, strct->j * 64,
				strct->i * 64) < 0)
			ft_mlx_error();
		strct->j++;
	}
}

static void	semov(t_long *strct)
{
	strct->c--;
	strct->map[strct->pi][strct->pj] = '0';
	pimag(strct, strct->pi, strct->pj, "textures/ground.png");
	strct->texture = mlx_load_png("textures/player.png");
	if (!strct->texture)
		ft_mlx_error();
	mlx_delete_image(strct->mlx, strct->pimg);
	strct->pimg = mlx_texture_to_image(strct->mlx, strct->texture);
	mlx_delete_texture(strct->texture);
	if (!strct->pimg)
		ft_mlx_error();
	if (mlx_image_to_window(strct->mlx, strct->pimg, strct->pj * 64, strct->pi
			* 64) < 0)
		ft_mlx_error();
}

void	moving(t_long *strct, int y, int x)
{
	strct->i++;
	ft_printf(" %d moves\n", strct->i);
	strct->pi += y;
	strct->pj += x;
	if (strct->map[strct->pi][strct->pj] == 'C')
	{
		semov(strct);
		if (!strct->c)
			pimag(strct, strct->ei, strct->ej, "textures/fdar.png");
	}
	else
	{
		strct->pimg->instances->x += x * 64;
		strct->pimg->instances->y += y * 64;
	}
	if (strct->map[strct->pi][strct->pj] == 'E' && !strct->c)
	{
		exit(0);
	}
}

void	my_ftkey(mlx_key_data_t k, void *prm)
{
	t_long	*strct;

	strct = prm;
	if ((k.key == MLX_KEY_UP || k.key == MLX_KEY_W) && k.action)
		if (strct->map[strct->pi - 1][strct->pj] != '1')
			moving(strct, -1, 0);
	if ((k.key == MLX_KEY_DOWN || k.key == MLX_KEY_S) && k.action)
		if (strct->map[strct->pi + 1][strct->pj] != '1')
			moving(strct, 1, 0);
	if ((k.key == MLX_KEY_RIGHT || k.key == MLX_KEY_D) && k.action)
		if (strct->map[strct->pi][strct->pj + 1] != '1')
			moving(strct, 0, 1);
	if ((k.key == MLX_KEY_LEFT || k.key == MLX_KEY_A) && k.action)
		if (strct->map[strct->pi][strct->pj - 1] != '1')
			moving(strct, 0, -1);
	if (k.key == MLX_KEY_ESCAPE)
	{
		exit(0);
	}
}
