/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_acl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:43:33 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 19:31:24 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_a(char **s, t_mini *c)
{
	if (is_atoz(s[0]) || is_atoz(s[1]) || s[2])
		err_msg("Invalid Contents");
	c->aml.light_ratio = ft_atof(s[0]);
	if (c->aml.light_ratio < 0 || c->aml.light_ratio > 1)
		err_msg("Ambient Lighting Ratio Not in Range");
	c->aml.color = ft_color(s[1]);
}

void	ft_c(char **s, t_mini *c)
{
	if (is_atoz(s[0]) || is_atoz(s[1]) || is_atoz(s[2]) || s[3])
		err_msg("Invalid Contents");
	get_vec3(c->cam.view_point, s[0]);
	get_vec3(c->cam.orient, s[1]);
	if (c->cam.orient[X] < 0 || c->cam.orient[X] > 1
		|| c->cam.orient[Y] < 0 || c->cam.orient[Y] > 1
		|| c->cam.orient[Z] < 0 || c->cam.orient[Z] > 1)
		err_msg("Orientation Vector Not in Range");
	c->cam.fov = ft_atoi(s[2]);
	if (c->cam.fov <= 0 || c->cam.fov >= 180)
		err_msg("FOV Value Not in Range");
}

void	ft_l(char **s, t_mini *c)
{
	if (is_atoz(s[0]) || is_atoz(s[1]) || is_atoz(s[2]) || s[3])
		err_msg("Invalid Contents");
	get_vec3(c->lig.position, s[0]);
	c->lig.bright = ft_atof(s[1]);
	if (c->lig.bright < 0 || c->lig.bright > 1)
		err_msg("Brightness Ratio Not in Range");
	c->lig.color = ft_color(s[2]);
}
