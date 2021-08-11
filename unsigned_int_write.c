/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavetyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:41:18 by aavetyan          #+#    #+#             */
/*   Updated: 2021/03/31 15:41:21 by aavetyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_of_un(unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_u_itoa(unsigned int num)
{
	char	*str_num;
	int		len;

	len = size_of_un(num);
	if (!(str_num = (char *)malloc(len + 1)))
		return (0);
	str_num[len] = '\0';
	if (num == 0)
		str_num[len - 1] = '0';
	while (num != 0)
	{
		str_num[len - 1] = (num % 10) + '0';
		len--;
		num /= 10;
	}
	return (str_num);
}

int		ft_part_in_itoa_u_helper(t_option flags, char *str_num)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_write_flags(flags.dot - 1, ft_strlen(str_num) - 1, 1);
	count += ft_write_arg(ft_strlen(str_num), str_num);
	return (count);
}

int		ft_part_in_u_itoa(t_option flags, char *str_num)
{
	int i;

	i = 0;
	if (flags.flag_minus == 1)
		i += ft_part_in_itoa_u_helper(flags, str_num);
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
		i += ft_part_in_itoa_u_helper(flags, str_num);
	return (i);
}

int		unsigned_int_write(t_option flags, unsigned int num)
{
	int		count;
	char	*str_num;

	count = 0;
	num = (unsigned int)(4294967296 + num);
	if (num == 0 && flags.dot == 0)
		return (count += ft_write_flags(flags.width, 0, 0));
	str_num = ft_u_itoa(num);
	count += ft_part_in_u_itoa(flags, str_num);
	free(str_num);
	return (count);
}
