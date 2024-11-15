/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:54:47 by kkoujan           #+#    #+#             */
/*   Updated: 2024/11/15 12:54:57 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_helper(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (format == 'u')
		return (ft_putunbr_base(va_arg(args, unsigned int), \
				"0123456789"));
	if (format == 'x')
		return (ft_putunbr_base(va_arg(args, unsigned int), \
				"0123456789abcdef"));
	if (format == 'X')
		return (ft_putunbr_base(va_arg(args, unsigned int), \
				"0123456789ABCDEF"));
	if (format == '%')
		return (ft_putchar_fd('%', 1));
	if (format == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (format == 'p')
		return (ft_putaddress(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	if (format[0] == '\0')
		return (0);
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_print_helper(*format, args);
		}
		else
			count += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
