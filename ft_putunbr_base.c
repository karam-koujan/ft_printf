/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:17:01 by kkoujan           #+#    #+#             */
/*   Updated: 2024/11/14 19:00:32 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_base(unsigned int n, char *base)
{
	char			r;
	unsigned int	len;

	len = ft_strlen(base);
	if (n >= len)
	{
		ft_putunbr_base(n / len, base);
	}
	r = base[n % len];
	write(1, &r, 1);
}