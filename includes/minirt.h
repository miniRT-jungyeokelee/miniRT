/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 02:49:46 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 22:39:52 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "header.h"
# include "struct.h"

	/* RESOLUTION : FHD */
# define SWID	1920
# define SHEI	1080
# define MARG	50

# define BUFFER_SIZE	512

	/* KEYBOARD */
# define KEY_ESC	53
# define RED_BUTTON	17

	/* MACRO : TO MAKE PRETTIER */
/* basic1 */
# define INDEX	0
# define NUMC	1

/* basic2 */
# define DOT	1
# define SIGN	2
# define ABS	0
# define FRAC	1

# define RED	0
# define GRE	1
# define BLU	2

/* get_info & get_obj */
# define SPH	1
# define PLN	2
# define CYL	3

/* hook.c */
int		_end(t_mini *c);
int		_key(int key, t_mini *c);

/* get_info.c */
void	get_info(t_mini *c);

/* get_acl.c */
void	ft_a(char **s, t_mini *c);
void	ft_c(char **s, t_mini *c);
void	ft_l(char **s, t_mini *c);

/* get_obj.c */
void	ft_sp(char **s, t_mini *c, int i[4]);
void	ft_pl(char **s, t_mini *c, int i[4]);
void	ft_cy(char **s, t_mini *c, int i[4]);

/* make_origin_to_screen.c */
void	make_origin_to_cam(t_mini *c);

/* make_cam_orient_to_my_orient.c */
void	make_cam_orient_to_my_orient(t_mini *c);

/* make_img.c */
void	make_img(t_mini *c);

/* err.c */
void	err_msg(char *s);

	/* BASIC FUNCTIONS */
/* basic.c */
void	ft_memset(void *b, int c, int len);
void	buf_ini(char buf[BUFFER_SIZE + 1]);
int		ft_strlen(char *s);
void	*ft_calloc(int i, int j);
char	*ft_strjoin(char *s1, char *s2);

/* basic1.c */
char	*ft_strchr(char *s, int c);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlenc(char *s, char c);
char	*ft_strdupc(char *s, char c);
char	**ft_split(char *s, char c);

/* basic2.c */
void	free_split(char ***ret, int i);
int		ft_atoi(char *s);
float	ft_atof(char *s);
bool	is_atoz(char *s);
int		ft_color(char *s);

/* basic3.c */
void	get_vec3(float f[3], char *s);
void	mat_init(float mat[3][3]);

	/* 3VECTOR */
/* translation.c */
void	translate(float _this[3], float to_this[3]);

/* rotation.c */
void	rotate(float _this[3], float to_this[3]);

/* v3asic1.c */
void	_mat_mul(float mat[3][3], float pos[3]);

#endif
