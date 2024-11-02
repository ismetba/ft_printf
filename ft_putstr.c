/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu <ibayandu@student.42ist +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:08:57 by cdurro            #+#    #+#             */
/*   Updated: 2024/11/02 22:00:26 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *total_length)
{
	while (*str)
	{
		ft_putchar(*str, total_length);
		str++;
	}
}
