/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:11:59 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/29 14:37:10 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr)
{
	char	*nb;
	int		len;

	len = 0;
	nb = ft_itoa(nbr);
	len += ft_putstr(nb);
	free(nb);
	return (len);
}

int	ft_conv_base(char spec, long n, int base)
{
	char	*base_s;
	int		count;

	count = 0;
	if (spec == 'x')
		base_s = "0123456789abcdef";
	else
		base_s = "0123456789ABCDEF";
	if (n < 0)
	{
		write (1, "-", 1);
		return (ft_conv_base(spec, -n, base) + 1);
	}
	else if (n < base)
		return (ft_putchar(base_s[n]));
	else
	{
		count = ft_conv_base(spec, n / base, base);
		return (count + ft_conv_base(spec, n % base, base));
	}
}

static	int	handle_conversions(char spec, va_list args)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (spec == 'p')
		return (ft_put_adress_ptr(va_arg(args, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (spec == 'u')
		return (ft_conv_base(spec, (long)va_arg(args, unsigned int), 10));
	if (spec == 'x' || spec == 'X')
		return (ft_conv_base(spec, (long)va_arg(args, unsigned int), 16));
	if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	print = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			print += handle_conversions(format[++i], args);
		else
			print += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print);
}
