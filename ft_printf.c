/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:54:47 by kkoujan           #+#    #+#             */
/*   Updated: 2024/11/14 19:00:38 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_strlen(format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				ft_putchar_fd(va_arg(args, int),1);
			}
			if (*format == 'd' || *format == 'i')
			{
				ft_putnbr_fd(va_arg(args, int),1);
			}
			if (*format == 'u')
			{
				ft_putunbr_base(va_arg(args, unsigned int),"0123456789");
			}
			if (*format == 'x')
			{
				ft_putunbr_base(va_arg(args, unsigned int),"0123456789abcdef");
			}
			if (*format == 'X')
			{
				ft_putunbr_base(va_arg(args, unsigned int),"0123456789ABCDEF");
			}
			if (*format == '%')
			{
				ft_putchar_fd('%',1);
			}
			if (*format == 's')
			{
				ft_putstr_fd(va_arg(args, char *),1);
			}
			if (*format == 'p')
			{
				ft_putaddress(va_arg(args, void *));
			}
		}
		else
		{
			ft_putchar_fd(*format,1);
		}
		format++;
	}
	va_end(args);
	return (len);
}
