/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:32:29 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/30 14:58:35 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		ft_putchar('%');
}

int		ft_isflag(char c)
{
	return (c == '0' || c == '-' || ft_isdigit(c) || c == '#' || c == ' ');
}

void	ft_flag(char **c, t_format *form)
{
	int		loop;

	loop = 0;
	if (*c[0] == '0')
	{
		if (ft_isdigit(*c[loop]))
			ft_zeropad(c, form);
	}
	else if (*c[0] == '-')
	{
		if (ft_isdigit(*c[1]))
			ft_leftjustify(c, form);
	}
	else if (ft_isdigit(*c[0]))
		ft_rightjustify(c, form);
	else if (*c[0] == '#')
		ft_hashtag(&c, form);
	else if (*c[0] == ' ')
		if (ft_isdigit(*c[1]))
			ft_space(c, form);
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
	loop = 0;
	str = ft_strdup(format);
	while (str[loop] != '\0')
	{
		if (str[loop] == '%')
		{
			tmp = ft_strdup(&str[loop + 1]);
			str[loop] = '\0';
			if (!(form = ft_newformat()))
				return (-1);
			ft_putstr(str);
			ft_strdel(&str);
			loop = 0;
			while (ft_isflag(tmp[0]) || ft_ischardesc(tmp[0]))
			{
				if (ft_isflag(tmp[0]))
					ft_flag(&tmp, form);
				if (ft_ischardesc(tmp[0]))
					ft_chardesc(&tmp, form);
			}
			if (ft_isidentifier(tmp[loop]))
				ft_identifier(tmp[0], ap, form);
			str = ft_strdup(tmp + 1);
			ft_strdel(&tmp);
		}
		loop++;
	}
	ft_putstr(str);
	va_end(ap);
	return (0);
}

int		main()
{
	ft_printf("test 1 :%s my name is %s and i am %hhi", "hi", "marnus", 'c');
}