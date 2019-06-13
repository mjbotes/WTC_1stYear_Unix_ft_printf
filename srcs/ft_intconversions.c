/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intconversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:51:44 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/11 12:58:49 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_isint(va_list ap, t_format *form)
{
	signed char c;
	short int	b;
	if (form->format != NULL)
	{
		if (ft_strcmp(form->format, "hh") == 0)
		{
			c = va_arg(ap, int);
			ft_putnbr(c);
		}
		else if (ft_strcmp(form->format, "h") == 0)
		{
			b = va_arg(ap, int);
			ft_putnbr(b);
		}
		else if (ft_strcmp(form->format, "z") == 0)
			ft_putnbr(va_arg(ap, size_t));
		else if (ft_strcmp(form->format, "j") == 0)
			ft_putnbr(va_arg(ap, intmax_t));
		else if (ft_strcmp(form->format, "l") == 0)
			ft_putnbr(va_arg(ap, long int));
		else if (ft_strcmp(form->format, "ll") == 0)
			ft_putnbr( va_arg(ap, long long int));
		else
			ft_putnbr(va_arg(ap, int));
	}else
		ft_putnbr(va_arg(ap, int));
}

void	ft_isuint(va_list ap, t_format *form)
{
	int	num;

	num = va_arg(ap, int);
	num = ft_makeunsigned(num);
	ft_putnbr(num);
}
