/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavetyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:39:15 by aavetyan          #+#    #+#             */
/*   Updated: 2021/03/31 15:39:20 by aavetyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(int arg)
{
	if (arg >= 48 && arg <= 57)
		return (1);
	return (0);
}

t_option	ret_digit(t_option f, char c)
{
	if (f.star == 1)
		f.width = 0;
	f.width = ((f.width * 10) + (c - '0'));
	return (f);
}

int			return_precision(const char *arr, int i, t_option *f, va_list arg)
{
	int count;

	count = i;
	count++;
	if (arr[count] == '*')
	{
		f->dot = va_arg(arg, int);
		count++;
	}
	else
	{
		f->dot = 0;
		while (ft_isdigit(arr[count]))
			f->dot = ((f->dot * 10) + (arr[count++] - '0'));
	}
	return (count);
}

t_option	ft_get_arg(t_option f, va_list arg)
{
	f.star = 1;
	f.width = va_arg(arg, int);
	if (f.width < 0)
	{
		f.flag_minus = 1;
		f.width *= -1;
	}
	return (f);
}

int			start_printing(va_list arg, t_option flags)
{
	int count;

	count = 0;
	if (flags.type == 'c')
		count = char_write(flags, va_arg(arg, int));
	else if (flags.type == 's')
		count = string_write(flags, va_arg(arg, char *));
	else if (flags.type == 'd' || flags.type == 'i')
		count = integer_write(flags, va_arg(arg, int));
	else if (flags.type == 'p')
		count = pointer_write(flags, va_arg(arg, unsigned long long));
	else if (flags.type == 'u')
		count = unsigned_int_write(flags,
				(unsigned int)va_arg(arg, unsigned int));
	else if (flags.type == 'x')
		count = hexa_write(flags, va_arg(arg, unsigned int), 1);
	else if (flags.type == 'X')
		count = hexa_write(flags, va_arg(arg, unsigned int), 0);
	else if (flags.type == '%')
		count = percent_write(flags);
	return (count);
}
