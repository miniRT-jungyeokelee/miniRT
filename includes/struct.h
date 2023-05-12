/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 02:50:33 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 22:39:30 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define X	0
# define Y	1
# define Z	2

typedef struct s_a
{
	float	light_ratio;
	int		color;
}t_a;

typedef struct s_c
{
	float	view_point[3];
	float	orient[3];
	int		fov;
}t_c;

typedef struct s_l
{
	float	position[3];
	float	bright;
	int		color;
}t_l;

typedef struct s_sp
{
	float	center[3];
	float	diameter;
	int		color;
}t_sp;

typedef struct s_pl
{
	float	point_pl[3];
	float	n_vec[3];
	int		color;
}t_pl;

typedef struct s_cy
{
	float	center[3];
	float	axis[3];
	float	diameter;
	float	height;
	int		color;
}t_cy;

typedef struct s_mini
{
	char	*l_map;
	char	**map;

	void	*ptr;
	void	*win;
	void	*img;
	void	*adr;
	int		bpp;
	int		s_l;
	int		end;

	float	dist_scr;

	int		naml;
	int		ncam;
	int		nlig;
	int		nsph;
	int		npln;
	int		ncyl;
	t_a		aml;
	t_c		cam;
	t_l		lig;
	t_sp	*sph;
	t_pl	*pln;
	t_cy	*cyl;
}t_mini;

#endif
