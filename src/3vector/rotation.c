/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:49:58 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 17:44:08 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	rotx(float _this[3], float angx)
{
	float	mat[3][3];

	mat_init(mat);
	mat[0][0] = 1;
	mat[1][1] = cos(angx);
	mat[2][2] = cos(angx);
	mat[1][2] = -sin(angx);
	mat[2][1] = sin(angx);
	_mat_mul(mat, _this);
}

void	roty(float _this[3], float angy)
{
	float   mat[3][3];

	mat_init(mat);
	mat[0][0] = cos(angy);
	mat[1][1] = 1;
	mat[2][2] = cos(angy);
	mat[0][2] = sin(angy);
	mat[2][2] = cos(angy);
	_mat_mul(mat, _this);
}

void	rotz(float _this[3], float angz)
{
	float   mat[3][3];

	mat_init(mat);
	mat[0][0] = cos(angz);
	mat[1][1] = cos(angz);
	mat[2][2] = 1;
	mat[1][0] = sin(angz);
	mat[0][1] = -sin(angz);
	_mat_mul(mat, _this);
}

void	rotate(float _this[3], float to_this[3])
{
	rotx(_this, to_this[X]);
	roty(_this, to_this[Y]);
	rotz(_this, to_this[Z]);
}
