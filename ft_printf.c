/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:31:26 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/28 16:45:36 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

static int	ft_arg(char c, va_list ap)
{
	int	count;

	if (c == 'c')
	{
		ft_putchar_fd((char)va_arg(ap, int), 1);
	}
	if (c == 's')
	{
		ft_putstr_fd(va_arg(ap, char *), 1);
	}
	if (c == 'p')
		ft_putstr_fd("TODO", 1);
	if (c == 'd')
		ft_putnbr_fd((int)va_arg(ap, int), 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	size_t	printed;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%' && format[i])
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
		else if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] != '%')
			{
				ft_arg(format[i + 1], ap);
				i += 2;
			}
		}
		else
			i++;
	}
	va_end(ap);
	return (i);
}
