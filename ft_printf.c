/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:54:47 by kkoujan           #+#    #+#             */
/*   Updated: 2024/11/15 10:49:17 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				ft_putchar_fd(va_arg(args, int),1);
				count++;
			}
			if (*format == 'd' || *format == 'i')
			{
				count+=ft_putnbr_fd(va_arg(args, int),1);
			}
			if (*format == 'u')
			{
				count+=ft_putunbr_base(va_arg(args, unsigned int),"0123456789");
			}
			if (*format == 'x')
			{
				count+=ft_putunbr_base(va_arg(args, unsigned int),"0123456789abcdef");
			}
			if (*format == 'X')
			{
				count+=ft_putunbr_base(va_arg(args, unsigned int),"0123456789ABCDEF");
			}
			if (*format == '%')
			{
				ft_putchar_fd('%',1);
				count++;
			}
			if (*format == 's')
			{
				count+=ft_putstr_fd(va_arg(args, char *),1);
			}
			if (*format == 'p')
			{
				count+=ft_putaddress(va_arg(args, void *));
			}
		}
		else
		{
			ft_putchar_fd(*format,1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
#include <stdio.h>

int main()
{
	printf("sdasd %s",NULL);
	ft_printf("sdasd %s",NULL);
}