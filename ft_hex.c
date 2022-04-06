/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalall <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:45:59 by agalall           #+#    #+#             */
/*   Updated: 2022/02/03 13:49:31 by agalall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned int arg, int *len, char x)
{
	char	b[50];
	int		i;
	char	*bas;

	i = 0;
	if (x == 'x')
		bas = "0123456789abcdef";
	else if (x == 'X')
		bas = "0123456789ABCDEF";
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
