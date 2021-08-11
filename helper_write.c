/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavetyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:39:27 by aavetyan          #+#    #+#             */
/*   Updated: 2021/03/31 15:39:38 by aavetyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fd_putchar(char c)
{
	ft_putchar(1, c);
	return (1);
}

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

int		ft_write_arg(int flag, char *s)
{
	int count;

	count = 0;
	while (s[count] && count < flag)
		fd_putchar(s[count++]);
	return (count);
}

int		ft_write_flags(int width, int minus, int has_zero)
{
	int count;

	count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			count += fd_putchar('0');
		else
			count += fd_putchar(' ');
		--width;
	}
	return (count);
}
