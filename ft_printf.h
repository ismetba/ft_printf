/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu <ibayandu@student.42ist +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:39:45 by cdurro            #+#    #+#             */
/*   Updated: 2024/11/02 21:55:04 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_check_base(char *base);
int		ft_printf(const char *str, ...);

void	ft_putchar(char c, int *total_length);
void	ft_putstr(char *str, int *total_length);
void	ft_string_format(va_list args, int *total_length, int space);
void	ft_integer_format(int *total_length, int i_converted);
void	ft_unsigned_format(va_list args, int *total_length);
void	ft_pointer_format(va_list args, int *total_length);
void	ft_hex_format(char c, int *total_length, unsigned int u_converted);
void	ft_putnbr(int nbr, int *total_length);
void	ft_putunbr_base(unsigned int nbr, char *base, int *total_length);
void	ft_putlnbr_base(unsigned long nbr, char *base, int *total_length);

#endif