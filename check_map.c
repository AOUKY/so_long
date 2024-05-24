/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:20:31 by haouky            #+#    #+#             */
/*   Updated: 2024/05/24 17:41:29 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	after_ff(char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if (v[i][j] == 'C' || v[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	thmv(t_long *strct, char c, int i, int j)
{
	if (c == 'E')
	{
		strct->ei = i;
		strct->ej = j;
		strct->e++;
	}
	else if (c == 'C')
		strct->c++;
	else if (c != 'P' && c != '1' && c != '0')
		ft_error(2);
}

void	semv(t_long *strct, int size, int len, char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[i])
	{
		j = 0;
		while (v[i][j] && v[i][j] != '\n')
		{
			if ((v[i][j] != '1' && i == 0) || (v[i][j] != '1' && i == size - 1))
				ft_error(3);
			if (v[i][j] == 'P')
			{
				strct->pi = i;
				strct->pj = j;
				strct->p++;
			}
			thmv(strct, v[i][j], i, j);
			j++;
		}
		if (len != j || v[i][0] != '1' || v[i][j - 1] != '1')
			ft_error(3);
		i++;
	}
	strct->y = j;
}

void	map_validation(char **v, t_long *strct)
{
	int	len;
	int	size;

	strct->p = 0;
	strct->c = 0;
	strct->e = 0;
	size = 0;
	while (v[size])
		size++;
	strct->x = size;
	len = ft_strlen(v[0]) - 1;
	semv(strct, size, len, v);
	if (size > 22 || strct->y > 40)
		ft_error(6);
	if (strct->p != 1 || strct->e != 1 || strct->c < 1)
		ft_error(4);
	ffld(v, strct->pi, strct->pj);
	len = 0;
	if (after_ff(v) == 0)
		ft_error(5);
	fr_double(v);
}
