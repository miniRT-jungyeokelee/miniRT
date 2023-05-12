/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3asic1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:14:08 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 17:19:55 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	_mat_mul(float mat[3][3], float pos[3])
{
	float	f[3];
	
	f[Y] = 0;
	f[Y] = 0;
	f[Z] = 0;
	f[X] += mat[X][X] * pos[X] + mat[X][Y] * pos[Y] + mat[X][Z] * pos[Z];
	f[Y] += mat[Y][X] * pos[X] + mat[Y][Y] * pos[Y] + mat[Y][Z] * pos[Z];
	f[Z] += mat[Z][X] * pos[X] + mat[Z][Y] * pos[Y] + mat[Z][Z] * pos[Z];
	pos[X] = f[X];
	pos[Y] = f[Y];
	pos[Z] = f[Z];
}
