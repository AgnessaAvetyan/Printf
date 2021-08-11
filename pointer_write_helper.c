/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_write_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavetyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:40:54 by aavetyan          #+#    #+#             */
/*   Updated: 2021/03/31 15:40:59 by aavetyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_ull_base_write(unsigned long long ull,
		int b, char *ptr, int i)
{
	while (ull != 0)
	{
		if ((ull % b) < 10)
			ptr[i - 1] = (ull % b) + 48;
		else
			ptr[i - 1] = (ull % b) + 55;
		ull /= b;
		i--;
	}
	return (ptr);
}

char			*ft_ull_base(unsigned long long ull, int base)
{
	char				*pointer;
	unsigned long long	save_ull;
	int					count;

	pointer = 0;
	count = 0;
	save_ull = ull;
	if (save_ull == 0)
		return (ft_strdup("0"));
	while (save_ull != 0)
	{
		save_ull /= base;
		count++;
	}
	if (!(pointer = malloc(sizeof(char) * (count + 1))))
		return (0);
	pointer[count] = '\0';
	pointer = ft_ull_base_write(ull, base, pointer, count);
	return (pointer);
}

int				ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

char			*ft_str_lower(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		str[i] = ft_tolower(str[i]);
	}
	return (str);
}
