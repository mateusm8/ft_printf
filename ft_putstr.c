/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmagalha <mmagalha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:53:26 by mmagalha          #+#    #+#             */
/*   Updated: 2022/05/20 19:55:56 by mmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const void *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *) str;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (temp[i])
	{
		write(1, &temp[i], 1);
		i++;
	}
	return (i);
}
