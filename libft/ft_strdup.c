/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:50:13 by haouky            #+#    #+#             */
/*   Updated: 2024/05/24 16:03:03 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**cpy_dbl_ar(char **v)
{
	int		i;
	int		j;
	char	**cpy;

	i = 0;
	while (v[i])
		i++;
	cpy = malloc((i * (sizeof(char *))) + 1);
	if (!cpy)
		return (0);
	j = 0;
	while (j < i)
	{
		cpy[j] = ft_strdup(v[j]);
		j++;
	}
	cpy[j] = 0;
	return (cpy);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	i = ft_strlen(s1);
	s = malloc(i + 1);
	if (s == 0)
		return (0);
	ft_strlcpy(s, s1, i + 1);
	return (s);
}
