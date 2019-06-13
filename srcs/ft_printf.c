/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:32:29 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/13 15:45:04 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_isidentifier(char c)
{
	return (c == 's' || c == 'i' || c == 'd' || c == 'u' || c == 'o' || c == 'O' || c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%');
}

void	ft_identifier(char c, va_list ap, t_format *form)
{
	if (c == 's')
		ft_isstring(ap, form);
	else if (c == 'i' || c == 'd')
		ft_isint(ap, form);
	else if (c == 'u')
		ft_isuint(ap, form);
	else if (c == 'o' || c == 'O')
		ft_isoct(ap, form);
	else if (c == 'x' || c == 'X')
		ft_ishexi(ap, c, form);
	else if (c == 'c')
		ft_ischar(ap, form);
	else if (c == 'C')
		ft_isunicode(ap, form);
	else if (c == '%')
		ft_printer("%", form);
}

int		ft_isflag(char c)
{
	return (c == '0' || c == '-' || ft_isdigit(c) || c == '#' || c == ' ');
}

void	ft_flag(char **c, t_format *form)
{
	int		loop;

	loop = 0;
	if (*c[0] == '#')
		ft_hashtag(c, form);
	if (*c[0] == ' ')
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
	int			loop;
	t_format	*form;

	va_start(ap, format);
	loop = -1;
	str = ft_strdup(format);
	while (str[++loop] != '\0')
		if (str[loop] == '%')
		{
			str[loop] = '\0';
			//ft_putstr(str);
			loop++;
			tmp = ft_strdup(&str[loop]);
			ft_strdel(&str);
			loop = 0;
			form = ft_newformat();
			while (tmp[0])
			{
				if (form == NULL)
				   form = ft_newformat();	
				if (ft_isflag(tmp[0]))
					ft_flag(&tmp, form);
				else if (ft_ischardesc(tmp[0]))
					ft_chardesc(&tmp, form);
				else if (ft_isidentifier(tmp[0]))
				{
					ft_identifier(tmp[0], ap, form);
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
				break; 
			str = ft_strdup(tmp + 1);
			ft_strdel(&tmp);
			ft_delformat(&form);
		}
	ft_putstr(str);
	va_end(ap);
	ft_strdel(&str);
	return (0);
}
