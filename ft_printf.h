/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavetyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:39:01 by aavetyan          #+#    #+#             */
/*   Updated: 2021/03/31 15:39:06 by aavetyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

typedef struct		s_option
{
	int		flag_minus;
	int		flag_zero;
	int		width;
	int		dot;
	int		star;
	char	type;
}					t_option;

t_option			flag_initialize(void);
t_option			ft_flagtype(t_option f);
t_option			ret_digit(t_option f, char c);
t_option			ft_get_arg(t_option f, va_list arg);
int					ft_part_in_write(t_option flags, char *s);
char				*ft_strdup(const char *str);
char				*ft_itoa(int arg);
char				*ft_ull_base(unsigned long long ull, int base);
char				*ft_str_lower(char *str);
char				*ft_u_itoa(unsigned int num);
char				*ft_toupper(char *str);
char				ft_istype(char c);
void				ft_putchar(int fd, char c);
int					work_with_flags(const char *arr, int i,
		va_list arg, t_option *flags);
int					ft_treat_save(const char *save, va_list arg);
int					ft_printf(const char *input, ...);
int					char_write(t_option flags, char c);
int					ft_strlen(const char *str);
int					fd_putchar(char c);
int					ft_isdigit(int arg);
int					return_precision(const char *arr,
		int i, t_option *f, va_list arg);
int					start_printing(va_list arg, t_option flags);
int					ft_write_arg(int flag, char *s);
int					ft_write_flags(int width, int minus, int has_zero);
int					hexa_write(t_option flags,
		unsigned int num, int is_lowcase);
int					size_of_n(int num);
int					integer_write(t_option flags, int arg);
int					percent_write(t_option flags);
int					ft_tolower(int c);
int					ft_part_in_u_itoa(t_option flags, char *str_num);
int					ft_part_in_itoa_u_helper(t_option flags, char *str_num);
int					pointer_write(t_option flags, unsigned long long ptr);
int					string_write(t_option flags, char *s);
int					size_of_un(unsigned int n);
int					unsigned_int_write(t_option flags, unsigned int num);

#endif
