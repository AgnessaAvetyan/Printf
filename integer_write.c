/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavetyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:39:58 by aavetyan          #+#    #+#             */
/*   Updated: 2021/03/31 15:40:14 by aavetyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			size_of_n(int num)
{
	int i;
	int n;

	i = 0;
	n = num;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int arg)
{
	char	*r;
	int		i;
	long	num;

	num = arg;
	i = size_of_n(num);
	if (!(r = (char *)malloc(i + 1)))
		return (NULL);
	r[i] = '\0';
	i--;
	if (num == 0)
		r[0] = '0';
	else if (num < 0)
	{
		r[0] = '-';
		num *= -1;
	}
	while (num != 0)
	{
		r[i] = (num % 10) + '0';
		num /= 10;
		--i;
	}
	return (r);
}

static int	ft_part_in_itoa_helper(t_option flags, char *str_num, int num)
{
	int count;

	count = 0;
	if (num < 0 && flags.dot >= 0)
		ft_putchar(1, '-');
	if (flags.dot >= 0)
		count += ft_write_flags(flags.dot - 1, ft_strlen(str_num) - 1, 1);
	count += ft_write_arg(ft_strlen(str_num), str_num);
	return (count);
}

static int	ft_part_in_itoa(t_option flags, char *str_num, int num)
{
	int i;

	i = 0;
	if (flags.flag_minus == 1)
	{
		i += ft_part_in_itoa_helper(flags, str_num, num);
		flags.flag_zero = 0;
	}
	if (flags.dot >= 0 && flags.dot < ft_strlen(str_num))
		flags.dot = ft_strlen(str_num);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		i += ft_write_flags(flags.width, 0, 0);
	}
	else
		i += ft_write_flags(flags.width, ft_strlen(str_num), flags.flag_zero);
	if (flags.flag_minus == 0)
		i += ft_part_in_itoa_helper(flags, str_num, num);
	return (i);
}

int			integer_write(t_option flags, int arg)
{
	int		count;
	char	*str_num;
	int		num;

	count = 0;
	num = arg;
	if (arg == 0 && flags.dot == 0)
	{
		count += ft_write_flags(flags.width, 0, 0);
		return (count);
	}
	if (arg < 0 && (flags.dot >= 0 || flags.flag_zero == 1))
	{
		if (flags.flag_zero == 1 && flags.dot == -1)
			count += fd_putchar('-');
		arg *= -1;
		flags.flag_zero = 1;
		flags.width--;
	}
	str_num = (char *)malloc(size_of_n(arg) + 1);
	str_num = ft_itoa(arg);
	count += ft_part_in_itoa(flags, str_num, num);
	free(str_num);
	return (count);
}
