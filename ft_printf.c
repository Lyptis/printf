/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:31:26 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/29 14:42:04 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	ft_arg(char c, va_list ap)
{
	int	count;

	if (c == 'c')
		count = ft_putchar_fd((char)va_arg(ap, int), 1);
	if (c == 's')
		count = ft_putstr_fd(va_arg(ap, char *), 1);
	if (c == 'p')
		count = ft_putptr(va_arg(ap, uintptr_t));
	if (c == 'd')
		count = ft_putnbr_fd((int)va_arg(ap, int), 1, 0);
	if (c == 'i')
		count = ft_putnbr_fd((int)va_arg(ap, int), 1, 0);
	if (c == 'u')
		count = ft_putunbr_fd((unsigned int)va_arg(ap, int), 1, 0);
	if (c == 'x')
		count = ft_put_hexm_nbr_fd((unsigned int)va_arg(ap, int), 1, 0);
	if (c == 'X')
		count = ft_put_hexc_nbr_fd((unsigned int)va_arg(ap, int), 1, 0);
	if (c == '%')
		count = ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;
	int		end_len;

	i = 0;
	end_len = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len = ft_arg(format[i + 1], ap);
			if (len < 0)
				return (-1);
			i += 2;
			end_len += len;
		}
		else if (format[i] != '%')
		{
			ft_putchar_fd(format[i++], 1);
			end_len++;
		}
	}
	va_end(ap);
	return (end_len);
}
