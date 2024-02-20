/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:40:43 by rboutaik          #+#    #+#             */
/*   Updated: 2023/11/25 13:15:33 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	i;
	int	x;

	x = 0;
	if (nb == -2147483648)
		x += write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		x += ft_putchar('-');
		i = -nb;
		x += ft_putnbr(i);
	}
	else if (nb <= 9)
		x += ft_putchar(nb + '0');
	else
	{
		x += ft_putnbr(nb / 10);
		x += ft_putnbr(nb % 10);
	}
	return (x);
}
