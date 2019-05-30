/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:50:27 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/30 13:12:09 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_ischar(va_list ap, t_format *form)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar(c);
}

void	ft_isoct(va_list ap, t_format *form)
{
	int		i;
	char	*str;

	i = va_arg(ap, int);
	i = ft_makeunsigned(i);
	str = ft_itooctal(i);
	ft_putstr(str);
}

void	ft_ishexi(va_list ap, char c, t_format *form)
{
	int		i;
	char	*str;

	i = va_arg(ap, int);
	i = ft_makeunsigned(i);
	str = ft_itohexi(i);
	if (c == 'X')
		str = ft_makeUpper(str);
	ft_putstr(str);
}

void	ft_isstring(va_list ap, t_format *form)
{
	char *str;

	str = va_arg(ap, char *);
	ft_putstr(str);
}
