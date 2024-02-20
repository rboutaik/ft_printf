/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:54:01 by rboutaik          #+#    #+#             */
/*   Updated: 2023/11/25 13:15:32 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return (write(1, "(null)", 6));
	if (*s == '\0')
		return (0);
	i = 0;
	while (*s)
	{
		i += ft_putchar(*s);
		s++;
	}
	return (i);
}
