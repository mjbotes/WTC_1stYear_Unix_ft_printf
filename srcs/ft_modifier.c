/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:24:08 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/19 07:03:12 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_charint(t_format *form)
{
	if (!(form->format = ft_strdup("char")))
		return (-1);
	return (0);
}

int		ft_shortint(t_format *form)
{
	if (!(form->format = ft_strdup("short")))
		return (-1);
	return (0);
}

int		ft_longint(t_format *form)
{
	if (!(form->format = ft_strdup("long")))
		return (-1);
	return (0);
}

int		ft_intmax(t_format *form)
{
	if (!(form->format = ft_strdup("max")))
		return (-1);
	return (0);
}

int		ft_sizet(t_format *form)
{
	if (!(form->format = ft_strdup("size_t")))
		return (-1);
	return (0);
}
