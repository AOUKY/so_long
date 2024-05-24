/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:27:58 by haouky            #+#    #+#             */
/*   Updated: 2024/05/24 17:17:04 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	se_main(int c, char **v, t_long *strct)
{
	int		fd;
	char	*line;
	t_list	*head;

	head = NULL;
	if (c != 2)
		ft_error(0);
	chek(v[1]);
	fd = open(v[1], O_RDONLY);
	if (fd == -1)
		ft_error(1);
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		line = get_next_line(fd);
	}
	strct->map = getarray(head);
	map_validation(cpy_dbl_ar(strct->map), strct);
}

int	main(int c, char **v)
{
	t_long	strct;

	se_main(c, v, &strct);
	put_ground(&strct);
	strct.i = 0;
	while (strct.map[strct.i])
	{
		put_image(&strct);
		strct.i++;
	}
	strct.texture = mlx_load_png("textures/player.png");
	if (!strct.texture)
		ft_mlx_error();
	strct.pimg = mlx_texture_to_image(strct.mlx, strct.texture);
	mlx_delete_texture(strct.texture);
	if (!strct.pimg)
		ft_mlx_error();
	if (mlx_image_to_window(strct.mlx, strct.pimg, strct.pj * 64, strct.pi
			* 64) < 0)
		ft_mlx_error();
	strct.i = 0;
	mlx_key_hook(strct.mlx, &my_ftkey, &strct);
	mlx_loop(strct.mlx);
}
