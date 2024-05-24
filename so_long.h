/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:18:39 by haouky            #+#    #+#             */
/*   Updated: 2024/05/24 18:31:07 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "Get_Next_Line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_long
{
	int			p;
	int			c;
	int			e;
	int			i;
	int			j;
	int			pi;
	int			pj;
	int			ei;
	int			ej;
	int			x;
	int			y;
	void		*mlx;
	void		*texture;
	mlx_image_t	*image;
	mlx_image_t	*pimg;
	char		**map;
}				t_long;
void			pimag(t_long *strct, int i, int j, char *v);
void			ft_mlx_error(void);
void			map_validation(char **v, t_long *strct);
int				chek(char *v);
void			put_image(t_long *strct);
void			my_ftkey(mlx_key_data_t k, void *prm);
void			put_ground(t_long *strct);
void			moving(t_long *strct, int y, int x);
void			ft_error(int n);
void			ffld(char **map, int i, int j);
#endif