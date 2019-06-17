/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:35:22 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/17 13:15:43 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_printmem(va_list ap, t_format *form)
{
	long add;
	void *ptr;

	ptr = va_arg(ap, void *);
		ptr = NULL;
	if (ptr == NULL)
		return (ft_printer("0x0",form));
	add = (long)ptr;
	return (ft_printer(ft_itoa_base(add, 16),form));
}
	
