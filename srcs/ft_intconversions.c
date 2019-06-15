/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intconversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:51:44 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/15 08:34:54 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_isint(va_list ap, t_format *form)
{
	signed char c;
	short int	b;
	if (ft_strcmp(form->format, "hh") == 0)
	{
		c = va_arg(ap, int);
		return (ft_printer(ft_itoa(c), form));
	}
	else if (ft_strcmp(form->format, "h") == 0)
	{
		b = va_arg(ap, int);
		return (ft_printer(ft_itoa(b), form));
	}
	else if (ft_strcmp(form->format, "z") == 0)
		return (ft_printer(ft_itoa(va_arg(ap, size_t)), form));
	else if (ft_strcmp(form->format, "j") == 0)
		return (ft_printer(ft_itoa(va_arg(ap, intmax_t)), form));
	else if (ft_strcmp(form->format, "l") == 0)
		return (ft_printer(ft_itoa(va_arg(ap, long)), form));
	else if (ft_strcmp(form->format, "ll") == 0)
		return (ft_printer(ft_itoa(va_arg(ap, long long)), form));
	else
		return (ft_printer(ft_itoa(va_arg(ap, int)), form));
}

int	ft_isuint(va_list ap, t_format *form)
{
	int	num;

	num = va_arg(ap, int);
	num = ft_makeunsigned(num);
	return (ft_printer(ft_itoa(num), form));
}
