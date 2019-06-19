/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:32:29 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/19 07:02:34 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_isidentifier(char c)
{
	return (c == 's' || c == 'i' || c == 'd' || c == 'u' || c == 'o' || 
	   	c == 'O' || c == 'x' || c == 'X' || c == 'c' || c == 'c' || 
		c == '%' || c == 'p' || c == 'f' || c == 'F' || c == 'U' ||
		c == 'D');
}

int		ft_identifier(char c, va_list ap, t_format *form)
{
	if (c == 'f' || c == 'F')
		return (ft_isfloat(ap, form));
	if (c == 's')
		return (ft_isstring(ap, form));
	if (c == 'i' || c == 'd' || c == 'D')
		return (ft_isint(ap, c, form));
	if (c == 'u' || c == 'U')
		return (ft_isuint(ap, c, form));
	if (c == 'o')
		return (ft_isoct(ap, form));
	if (c == 'O')
		return (ft_isOct(ap, form));
	if (c == 'x' || c == 'X')
		return (ft_ishexi(ap, c, form));
	if (c == 'c' || c == 'C')
		return (ft_ischar(ap, c, form));
//	if (c == 'C')
//		return (ft_isunicode(ap, form));
	if (c == 'p')
		return (ft_printmem(ap, form));
	return (ft_printer("%", form));
}

int		ft_isflag(char c)
{
	return (c == '0' || c == '-' || c == '+' || ft_isdigit(c) || c == '#' || c == ' ' || c == '.');
}

void	ft_flag(char **c, t_format *form, va_list ap)
{
	int		loop;
	int		num;
	char	*tm;
	
	loop = 0;
	if (*(c)[0] == '.')
	{

		while (ft_isdigit((*c)[loop + 1]))
				loop++;
		tm = ft_strsub(*c, 1, loop);
			form->zeropad = ft_atoi(tm);
		ft_strdel(&tm);
		tm = ft_strdup(*c + 1 + loop);
		ft_strdel(c);
		*c = ft_strdupdel(&tm);
	}
	else if (*(c)[0] == '+')
	{
		form->plus = 1;
		tm = ft_strdup(&((*c)[1]));
		ft_strdel(c);
		*c = ft_strdupdel(&tm);
	}
	else if (*c[0] == '#')
		ft_hashtag(c, form);
	else if (*c[0] == ' ')
		ft_space(c, form);
	else
		ft_justify(c, form);	
}

int		ft_ischardesc(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}

void	ft_chardesc(char **c, t_format *form)
{
	int n;
	char *tmp;
	char *ptr;

	n = 1;
	if (ft_strncmp(*c,"hh",2) == 0 || ft_strncmp(*c, "ll", 2) == 0)
		n = 2;
	form->format = ft_strndup(*(c), n);
	tmp = ft_strdup(*(c) + n );
	ft_strdel(c);
	*c = ft_strdup(tmp);
	ft_strdel(&tmp);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*tmp;
	char		*str;
	char		*ptr;
	int			ret;
	t_format	*form;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	ret = 0;
	str = ft_strdup(format);
	while ((ptr = ft_replacechr(&str, '%', '\0')) != NULL)
	{
			ft_putstr(str);
		ret += ft_strlen(str);
		tmp = ft_strdup(ptr + 1);
		ft_strdel(&str);
		form = ft_newformat();
		while (tmp[0])
		{
			if (form == NULL)
			   form = ft_newformat();	
			if (ft_isflag(tmp[0]))
				ft_flag(&tmp, form, ap);
			else if (ft_ischardesc(tmp[0]))
				ft_chardesc(&tmp, form);
			else if (ft_isidentifier(tmp[0]))
			{
				ret += ft_identifier(tmp[0], ap, form);
				break ;
			}
			else
			{
				str = ft_strdup(&tmp[1]);
				ft_strdel(&tmp);
				tmp = ft_strdupdel(&str);
			}
		}
		if (tmp[0] == '\0')
			break ;
		str = ft_strdup(tmp + 1);
		ft_strdel(&tmp);
		ft_delformat(&form);
	}
	ft_putstr(str);
	ret += ft_strlen(str);
	va_end(ap);
	ft_strdel(&str);
	return (ret);
}
