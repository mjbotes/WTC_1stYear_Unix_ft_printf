/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:35:22 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/15 14:29:21 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_printmem(void *ptr, t_format *form)
{
	long add;

	if (ptr == NULL)
		return (0);
	add = (long)ptr;
	return (ft_printer(ft_itoa_base(add, 16),form));
}
	
