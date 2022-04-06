/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalall <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:11:04 by agalall           #+#    #+#             */
/*   Updated: 2022/02/03 13:48:57 by agalall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nmbr(int arg, int *len)
{
	if (arg == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (arg < 0)
	{
		write(1, "-", 1);
		(*len) += 1;
		ft_nmbr((arg * -1), len);
	}
	else
	{
		if (arg > 9)
			ft_nmbr(arg / 10, len);
		ft_putchar_len(((arg % 10) + '0'), len);
	}
}
