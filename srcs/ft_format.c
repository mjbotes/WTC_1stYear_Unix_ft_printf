/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 07:59:39 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/11 12:59:06 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_format	*ft_newformat()
{
	t_format	*new;

	if (!(new = malloc(sizeof(t_format))))
		return (NULL);
	new->right_pad = 0;
	new->left_pad = 0;
	new->pad_type = ' ';
	new->space  = 0;
	new->format = NULL;
	return (new);
}

void		ft_delformat(t_format **ptr)
{
	if ((*ptr)->format != NULL)
{
		ft_strdel(&(*ptr)->format);
	free(*ptr);
	*ptr = NULL;
	ptr = NULL;
}
}
