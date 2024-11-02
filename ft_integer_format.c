/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu <ibayandu@student.42ist +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:10:25 by cdurro            #+#    #+#             */
/*   Updated: 2024/11/02 22:00:10 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_integer_format(int *total_length, int i_converted)
{
	if (i_converted == 0)
		ft_putchar('0', total_length);
	else
		ft_putnbr(i_converted, total_length);
}
