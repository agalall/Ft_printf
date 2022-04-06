/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalall <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:36:38 by agalall           #+#    #+#             */
/*   Updated: 2022/02/03 12:45:04 by agalall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check(char s, va_list *ar, int *len, int *i)
{
	if (s == 'c')
		ft_putchar_len(va_arg(*ar, int), len);
	else if (s == 's')
		ft_str(va_arg(*ar, char *), len);
	else if (s == 'p')
		ft_ptr(va_arg(*ar, size_t), len);
	else if (s == 'd' || s == 'i')
		ft_nmbr(va_arg(*ar, int), len);
	else if (s == 'u')
		ft_u(va_arg(*ar, unsigned int), len);
	else if (s == 'x')
		ft_hex(va_arg(*ar, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hex(va_arg(*ar, unsigned int), len, 'X');
	else if (s == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *ft, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, ft);
	while (ft[i] != '\0')
	{
		if (ft[i] == '%')
		{
			check(ft[++i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar_len(ft[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
