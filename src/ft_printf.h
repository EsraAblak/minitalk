/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:58:59 by eablak            #+#    #+#             */
/*   Updated: 2022/11/18 11:59:00 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *c);
int		ft_putnbr(int a);
int		ft_type_control(char c, va_list arg);
int		ft_printf(const char *str, ...);
int		ft_convert(size_t data, char *base);
int		ft_abs(int data);
size_t	ft_strlen(const char *s);

#endif
