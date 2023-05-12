/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:51:01 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 13:36:32 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	get_vec3(float f[3], char *s)
{
	char	*tmp;

	tmp = s;
	f[X] = ft_atof(tmp);
	tmp = ft_strchr(tmp, (int) ',');
	tmp++;
	f[Y] = ft_atof(tmp);
	tmp = ft_strchr(tmp, (int) ',');
	tmp++;
	f[Z] = ft_atof(tmp);
}

void	mat_init(float mat[3][3])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			mat[i][j] = 0;
	}
}
