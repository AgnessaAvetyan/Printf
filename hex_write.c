/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavetyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:39:44 by aavetyan          #+#    #+#             */
/*   Updated: 2021/03/31 15:39:49 by aavetyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_toupper(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int		hexa_write(t_option flags, unsigned int num, int is_lowcase)
{
	int		count;
	char	*res;

	count = 0;
	num = (unsigned int)(4294967296 + num);
	res = ft_ull_base((unsigned long long)num, 16);
	if (is_lowcase)
		res = ft_str_lower(res);
	if (num == 0 && flags.dot == 0)
		return (count += ft_write_flags(flags.width, 0, 0));
	if (flags.flag_minus == 1 || flags.flag_zero == 1)
		count += ft_part_in_u_itoa(flags, res);
	else
	{
		if (flags.dot >= 0 && flags.dot > ft_strlen(res))
			count += ft_write_flags(flags.width, flags.dot, 0);
		else
			count += ft_write_flags(flags.width, ft_strlen(res), 0);
		count += ft_write_flags(flags.dot, ft_strlen(res), 1);
		count += ft_write_arg(ft_strlen(res), res);
	}
	free(res);
	return (count);
}
