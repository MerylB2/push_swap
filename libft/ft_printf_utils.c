/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:05:39 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/29 14:36:55 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write (1, str, ft_strlen(str)));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static size_t	ft_putadress(const unsigned long ptr)
{
	if (ptr / 16)
		return (ft_putadress(ptr / 16) + ft_putadress(ptr % 16));
	else if (!(ptr / 10))
		ft_putchar(ptr + '0');
	else
		ft_putchar((char)ptr - 10 + 'a');
	return (1);
}

int	ft_put_adress_ptr(void *ptr)
{
	unsigned long	pt;
	int				len;

	len = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	pt = (unsigned long)ptr;
	len += write(1, "0x", 2);
	len += ft_putadress(pt);
	return (len);
}
