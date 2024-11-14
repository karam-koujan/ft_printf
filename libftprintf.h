/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:52:28 by kkoujan           #+#    #+#             */
/*   Updated: 2024/11/14 16:44:34 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_putunbr_base(unsigned int n, char *base);
void	ft_putaddress(void *p);


#endif