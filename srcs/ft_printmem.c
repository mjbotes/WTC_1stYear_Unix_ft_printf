/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:35:22 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/29 13:06:01 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_printmem(va_list ap, t_format *form)
{
	long  add;
	unsigned char	*ptr;
	char			*str;
	char			*tmp;

	ptr = va_arg(ap, void *);
	form->type = 'p';
	add = (long)ptr;
	str = ft_itoa_base(add, 16);
	tmp = ft_strjoin("0x", str);
	ft_strdel(&str);	
	return (ft_printer(tmp, form));
}	
