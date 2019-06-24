/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:33:43 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/18 13:36:59 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
		ft_strdel(&str);
		str = ft_strdup(*(c + loop));
		ft_strdel(c);
		*c = ft_strdup(str);
	}
}

void	ft_justify(char **c, t_format *form)
{
	int 	loop;
	char	*str;
	int		num;
	int		start;

	loop = 0;
	start = 0;
	if (form->right_pad == 0 && form->left_pad == 0)
	{
		if ((*c)[0] == '0')
		{
			loop = 1;
			form->pad_type = '0';
			start = 1;
		}
		if ((*c)[loop] == '+' || (*c)[loop] == '-')
			loop++;
		while (ft_isdigit((*c)[loop]))
				++loop;
		if (loop != 0)
		{
			str = ft_strsub(*c, start, loop - start);
			num = ft_atoi(str);
			/*if (form->pad_type == '0')
			{
				if (num < 0)
					form->pad_type = ' ';
				else
					num *= -1;
			}*/
			if (num > 0)
				form->left_pad = num;
			if (num < 0)
				form->right_pad = num;
			ft_strdel(&str);
			str = ft_strdup(*(c) + loop);
			ft_strdel(c);
			*c = ft_strdup(str);
		}
	}	
}

void	ft_wildcard(va_list ap, char **c, t_format *form)
{
	int	num;
	char	*str;

	num = va_arg(ap, int);
	if (num == 0)
		form->pad_type = '0';
	if (num > 0)
		form->left_pad = num;
	if (num < 0)
		form->right_pad = num;
	str = ft_strdup(&(*c)[1]);
	*c = ft_strdupdel(&str);
}

void	ft_space(char **c, t_format *form)
{
    int     loop;
    char    *str;
    int     num;

    loop = 1;
{

}	if (*(c)[loop] == '-' || *(c)[loop] == '+')
		loop++;
	while (ft_iswhitespace(*(c)[loop]))
			loop++;
	while (ft_isdigit(*(c)[loop]))
		loop ++;
	str = ft_strsub(*c, 0, loop);
	num = ft_atoi(str);
	if (num == 0)
		num = 1;
	form->space = num;
	ft_strdel(&str);
	str = ft_strdup(&((*c)[loop]));
	ft_strdel(c);
	*c = ft_strdup(str);
}

void	ft_isintmax(t_format form)
{

}

void	ft_issizet(tformat)
{

}
