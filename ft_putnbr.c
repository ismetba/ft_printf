/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:11:56 by ibayandu          #+#    #+#             */
/*   Updated: 2024/11/02 22:12:46 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *total_length)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', total_length);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, total_length);
		ft_putchar((nbr % 10) + '0', total_length);
	}
	else
		ft_putchar(nbr + '0', total_length);
}
