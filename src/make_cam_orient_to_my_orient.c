/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cam_orient_to_my_orient.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:25:33 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 19:29:01 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

// Our view orientation is -z axis (0, 0, -1)

void	rotate_obj(t_mini *c, float ang[3])
{
	int	i;

	i = -1;
	while (++i < c->nsph)
		rotate(c->sph[i].center, ang);
	i = -1;
	while (++i < c->npln)
	{
		rotate(c->pln[i].point_pl, ang);
		rotate(c->pln[i].n_vec, ang);
	}
	i = -1;
	while (++i < c->ncyl)
	{
		rotate(c->cyl[i].center, ang);
		rotate(c->cyl[i].axis, ang);
	}
}

void	make_cam_orient_to_my_orient(t_mini *c)
{
	float	norm;
	float	ang[3];

	norm = sqrt(c->cam.orient[X] * c->cam.orient[X]
		+ c->cam.orient[Y] * c->cam.orient[Y]
		+ c->cam.orient[Z] * c->cam.orient[Z]);
	ang[Z] = 0;
	ang[Y] = asin(c->cam.orient[X] / norm);
	ang[X] = acos(c->cam.orient[Z] / (norm * cos(ang[Y])));
	rotate(c->cam.orient, ang);
	rotate(c->lig.position, ang);
	rotate_obj(c, ang);
}
