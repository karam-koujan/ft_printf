/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:40:02 by kkoujan           #+#    #+#             */
/*   Updated: 2024/11/14 16:43:11 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putaddress_base(uintptr_t n, char *base)
{
	char			r;
	unsigned int	len;

	len = ft_strlen(base);
	if (n >= len)
	{
		ft_putaddress_base(n / len, base);
	}
	r = base[n % len];
	write(1, &r, 1);
}

void	ft_putaddress(void *p)
{
	uintptr_t		address;

	address = (uintptr_t)p;
	ft_putstr_fd("0x", 1);
	ft_putaddress_base(address, "0123456789abcdef");
}