/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmagalha <mmagalha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:45:26 by mmagalha          #+#    #+#             */
/*   Updated: 2022/05/20 20:12:36 by mmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_arg(char c, va_list args);
int	ft_putchar(char c, int i);
int	ft_putstr(const void *str);
int	ft_pointer(unsigned long int nbr);
int	ft_strlen(const char *str);
int	ft_base(long long int nbr, char *base);

#endif
