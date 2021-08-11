/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavetyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:40:21 by aavetyan          #+#    #+#             */
/*   Updated: 2021/03/31 15:40:24 by aavetyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent_write(t_option flags)
{
	int count;

	count = 0;
	if (flags.flag_minus == 1)
	{
		count += fd_putchar('%');
		count += ft_write_flags(flags.width, 1, 0);
	}
	else if (flags.flag_zero == 1)
	{
		count += ft_write_flags(flags.width, 1, 1);
		count += fd_putchar('%');
	}
	else
	{
		count += ft_write_flags(flags.width, 1, 0);
		count += fd_putchar('%');
	}
	return (count);
}
