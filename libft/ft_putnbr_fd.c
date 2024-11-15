/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:07:36 by kkoujan           #+#    #+#             */
/*   Updated: 2024/11/15 10:34:11 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char		r;
	long		nbr;
	int			count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		count++;
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		count+=ft_putnbr_fd(nbr / 10, fd);
	}
	r = nbr % 10 + '0';
	write(fd, &r, 1);
	count++;
	return (count);
}
