/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalall <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:34:20 by agalall           #+#    #+#             */
/*   Updated: 2022/02/03 13:48:40 by agalall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr(size_t arg, int *len)
{
	int		i;
	char	b[50];
	char	*bas;

	bas = "0123456789abcdef";
	write(1, "0x", 2);
	(*len) += 2;
	i = 0;
	if (arg == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (arg != 0)
	{
		b[i] = bas[arg % 16];
		arg /= 16;
		i++;
	}
	while (i--)
		ft_putchar_len(b[i], len);
}
