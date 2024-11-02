/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu <ibayandu@student.42ist +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:54:02 by cdurro            #+#    #+#             */
/*   Updated: 2024/11/02 22:00:32 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_string_format(va_list args, int *total_length, int space)
{
	char	*string_ptr;

	string_ptr = va_arg(args, char *);
	if (space && ft_strncmp(string_ptr, "", ft_strlen(string_ptr)) == 0)
		ft_putstr("", total_length);
	else if (string_ptr == NULL)
		ft_putstr("(null)", total_length);
	else
		ft_putstr(string_ptr, total_length);
}
