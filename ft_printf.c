/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmagalha <mmagalha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:03:29 by mmagalha          #+#    #+#             */
/*   Updated: 2022/05/20 20:11:26 by mmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base(long long int nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		i++;
	}
	if (nbr >= (long long int)ft_strlen(base))
		i += ft_base(nbr / ft_strlen(base), base);
	i += write(1, &base[nbr % ft_strlen(base)], 1);
	return (i);
}

int	ft_pointer(unsigned long int nbr)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	i += 2;
	if (nbr >= (unsigned long int)ft_strlen(base))
		i += ft_base(nbr / ft_strlen(base), base);
	i += write(1, &base[nbr % ft_strlen(base)], 1);
	return (i);
}

int	ft_arg(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 37)
		len += ft_putchar(37, 1);
	if (c == 'c')
		len += ft_putchar(va_arg(args, int), 1);
	else if (c == 's')
		len += ft_putstr(va_arg(args, const void *));
	else if (c == 'p')
		len += ft_pointer(va_arg(args, unsigned long int));
	if (c == 'd' || c == 'i')
		len += ft_base(va_arg(args, int), "0123456789");
	else if (c == 'u')
		len += ft_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		len += ft_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == 37)
		{
			i++;
			len += ft_arg(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end (args);
	return (len);
}
