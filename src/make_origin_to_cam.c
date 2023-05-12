/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_origin_to_cam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:33:33 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 19:28:15 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	make_origin_to_cam(t_mini *c)
{
	float	f[3];
	int		i;

	f[X] = -c->cam.view_point[X];
	f[Y] = -c->cam.view_point[Y];
	f[Z] = -c->cam.view_point[Z];
	translate(c->cam.view_point, f);
	translate(c->lig.position, f);
	i = -1;
	while (++i < c->nsph)
		translate(c->sph[i].center, f);
	i = -1;
	while (++i < c->npln)
		translate(c->pln[i].point_pl, f);
	i = -1;
	while (++i < c->ncyl)
		translate(c->cyl[i].center, f);
}
