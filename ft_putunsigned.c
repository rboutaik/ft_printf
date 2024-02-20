/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:59:59 by rboutaik          #+#    #+#             */
/*   Updated: 2023/11/25 13:15:30 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	x;

	x = 0;
	if (n <= 9)
		x += ft_putchar(n + '0');
	else
	{
		x += ft_putunsigned(n / 10);
		x += ft_putunsigned(n % 10);
	}
	return (x);
}
