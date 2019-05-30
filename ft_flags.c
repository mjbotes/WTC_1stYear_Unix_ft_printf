/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:33:43 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/30 13:04:43 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zeropad(char **c, t_format *form)
{
	int 	loop;
	char	*str;
	int		num;

	loop = 0;
	while (ft_isdigit(*c[loop]))
			loop ++;
	if (loop != 0)
	{
		str = ft_strndup(*c, loop);
		num = ft_atoi(str);
		form->zero_pad = num;
		ft_strdel(&str);
		str = ft_strdup(*(c + loop));
		ft_strdel(c);
		*c = ft_strdup(str);
	}
}

void	ft_leftjustify(char **c, t_format *form)
{
	int 	loop;
	char	*str;
	int		num;

	loop = 0;
	while (ft_isdigit(*c[loop]))
			loop ++;
	if (loop != 0)
	{
		str = ft_strndup(*c, loop);
		num = ft_atoi(str);
		form->left_pad = num;
		ft_strdel(&str);
		str = ft_strdup(*(c + loop));
		ft_strdel(c);
		*c = ft_strdup(str);
	}
}


void	ft_rightjustify(char **c, t_format *form)
{
	int 	loop;
	char	*str;
	int		num;

	loop = 0;
	while (ft_isdigit(*c[loop]))
			loop ++;
	if (loop != 0)
	{
		str = ft_strndup(*c, loop);
		num = ft_atoi(str);
		form->right_pad = num;
		ft_strdel(&str);
		str = ft_strdup(*(c + loop));
		ft_strdel(c);
		*c = ft_strdup(str);
	}
}

void	ft_hashtag(char **c, t_format *form)
{
	int 	loop;
	char	*str;
	int		num;

	loop = 0;
	while (ft_isdigit(*c[loop]))
			loop ++;
	if (loop != 0)
	{
		str = ft_strndup(*c, loop);
		num = ft_atoi(str);
		form->zero_pad = num;
		ft_strdel(&str);
		str = ft_strdup(*(c + loop));
		ft_strdel(c);
		*c = ft_strdup(str);
	}
}

void	ft_space(char **c, t_format *form)
{
	int 	loop;
	char	*str;
	int		num;

	loop = 0;
	while (ft_isdigit(*c[loop]))
			loop ++;
	if (loop != 0)
	{
		str = ft_strndup(*c, loop);
		num = ft_atoi(str);
		form->zero_pad = num;
		ft_strdel(&str);
		str = ft_strdup(*(c + loop));
		ft_strdel(c);
		*c = ft_strdup(str);
	}
}

void	ft_isintmax(t_format form)
{

}

void	ft_issizet(tformat)
{

}
