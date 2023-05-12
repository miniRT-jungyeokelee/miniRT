/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:47:41 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 13:28:21 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_sp(char **s, t_mini *c, int i[4])
{
	if (is_atoz(s[0]) || is_atoz(s[1]) || is_atoz(s[2]) || s[3])
		err_msg("Invalid Contents");
	get_vec3(c->sph[i[SPH]].center, s[0]);
	c->sph[i[SPH]].diameter = ft_atof(s[1]);
	c->sph[i[SPH]].color = ft_color(s[2]);
	i[SPH]++;
}

void	ft_pl(char **s, t_mini *c, int i[4])
{
	if (is_atoz(s[0]) || is_atoz(s[1]) || is_atoz(s[2]) || s[3])
		err_msg("Invalid Contents");
	get_vec3(c->pln[i[PLN]].point_pl, s[0]);
	get_vec3(c->pln[i[PLN]].n_vec, s[1]);
	if (c->pln[i[PLN]].n_vec[X] < -1 || c->pln[i[PLN]].n_vec[X] > 1
		|| c->pln[i[PLN]].n_vec[Y] < -1 || c->pln[i[PLN]].n_vec[Y] > 1
		|| c->pln[i[PLN]].n_vec[Z] < -1 || c->pln[i[PLN]].n_vec[Z] > 1)
		err_msg("Normal Vector of Plane Not in Range");
	c->pln[i[PLN]].color = ft_color(s[2]);
	i[PLN]++;
}

void	ft_cy(char **s, t_mini *c, int i[4])
{
	if (is_atoz(s[0]) || is_atoz(s[1]) || is_atoz(s[2])
		|| is_atoz(s[3]) || is_atoz(s[4]) || s[5])
		err_msg("Invalid Contents");
	get_vec3(c->cyl[i[CYL]].center, s[0]);
	get_vec3(c->cyl[i[CYL]].axis, s[1]);
	if (c->cyl[i[CYL]].axis[X] < -1 || c->cyl[i[CYL]].axis[X] > 1
		|| c->cyl[i[CYL]].axis[Y] < -1 || c->cyl[i[CYL]].axis[Y] > 1
		|| c->cyl[i[CYL]].axis[Z] < -1 || c->cyl[i[CYL]].axis[Z] > 1)
		err_msg("Axis Vector of Cylinder Not in Range");
	c->cyl[i[CYL]].diameter = ft_atof(s[2]);
	c->cyl[i[CYL]].height = ft_atof(s[3]);
	c->cyl[i[CYL]].color = ft_color(s[4]);
	i[CYL]++;
}
