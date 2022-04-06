/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalall <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:44:42 by agalall           #+#    #+#             */
/*   Updated: 2022/02/03 13:49:06 by agalall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u(unsigned int arg, int *len)
{
	if (arg > 9)
	{
		ft_nmbr(arg / 10, len);
	}
	ft_putchar_len((arg % 10) + '0', len);
}