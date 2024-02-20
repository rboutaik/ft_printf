/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:48:11 by rboutaik          #+#    #+#             */
/*   Updated: 2023/11/25 13:15:39 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getconv(const char *s, va_list args, int *i)
{
	*i += 1;
	if (s[*i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (s[*i] == 'd' || s[*i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (s[*i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s[*i] == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (s[*i] == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (s[*i] == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (s[*i] == 'p')
		return (ft_putstr("0x")
			+ ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef"));
	else if (s[*i] == '%')
		return (ft_putchar('%'));
	else if (s[*i - 1] && s[*i])
	{
		return (ft_putchar(*(s + *i)));
	}
	return (0);
}
