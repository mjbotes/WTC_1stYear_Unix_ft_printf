/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:03:40 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/10 15:17:51 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer(char *str, t_format *form)
{
	int temp;

	temp = form->left_pad;
	temp+=ft_strlen(str);
	while (++temp < 0)
		ft_putchar(form->pad_type);
	ft_putstr(str);
	temp = form->right_pad;
	temp -= ft_strlen(str);
	while (--temp > 0)
		ft_putchar(form->pad_type);
}
