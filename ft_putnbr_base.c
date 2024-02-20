/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:38:11 by rboutaik          #+#    #+#             */
/*   Updated: 2023/11/25 13:15:35 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_tupple(int x, int y, int size, char *base)
{
	while (x < size - 1)
	{
		y = x + 1;
		while (y < size)
		{
			if (base[x] == base[y])
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

static int	errors(char *base)
{
	int	size;
	int	m;

	size = 0;
	while (base[size])
		size++;
	if (size == 0 || size == 1)
		return (1);
	m = 0;
	while (base[m])
	{
		if (base[m] == 43 || base[m] == 45 || base[m] <= 32 || base[m] == 127)
		{
			return (1);
		}
		m++;
	}
	if (check_tupple(0, 0, size, base))
		return (1);
	return (0);
}

static void	ft_puthex(unsigned long n, int bs, char *base, int *v)
{
	if (n < (unsigned long)bs)
	{
		ft_putchar(base[n]);
		*v += 1;
	}
	else if (n >= (unsigned long)bs)
	{
		ft_puthex(n / bs, bs, base, v);
		ft_puthex(n % bs, bs, base, v);
	}
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int				basesize;
	int				i;

	i = 0;
	basesize = 0;
	if (!errors(base))
	{
		while (base[basesize])
		{
			basesize++;
		}
		ft_puthex(nbr, basesize, base, &i);
	}
	return (i);
}
