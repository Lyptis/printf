/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:57:36 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/29 14:41:08 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexc_nbr_fd(unsigned int nb, int fd, int len)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		len = ft_put_hexc_nbr_fd(nb / 16, fd, len);
		len += ft_putchar_fd(base[(nb % 16)], fd);
		return (len);
	}
	else
		len += ft_putchar_fd(base[nb], fd);
	return (len);
}

int	ft_put_hexm_nbr_fd(unsigned int nb, int fd, int len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		len = ft_put_hexm_nbr_fd(nb / 16, fd, len);
		len += ft_putchar_fd(base[(nb % 16)], fd);
		return (len);
	}
	else
		len += ft_putchar_fd(base[nb], fd);
	return (len);
}

static int	ft_put_hex_ptr_fd(unsigned long long nb, int fd, int len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		len = ft_put_hexm_nbr_fd(nb / 16, fd, len);
		len += ft_putchar_fd(base[(nb % 16)], fd);
		return (len);
	}
	else
		len += ft_putchar_fd(base[nb], fd);
	return (len);
}

int	ft_putptr(unsigned long long val)
{
	int	len;

	len = write(1, "0x", 2);
	if (len < 0)
		return (-1);
	len += ft_put_hex_ptr_fd(val, 1, 0);
	return (len);
}