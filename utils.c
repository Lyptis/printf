/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:48:13 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/29 13:58:39 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, sizeof(char)));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	while (s[i])
	{
		if (ft_putchar_fd(s[i], fd) > 0)
			i++;
		else
			return (-1);
	}
	return (i);
}

int	ft_putnbr_fd(int nb, int fd, int len)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		len += ft_putchar_fd('-', fd);
		nb *= -1;
		len = ft_putnbr_fd(nb, fd, len);
		return (len);
	}
	if (nb >= 10)
	{
		len = ft_putnbr_fd(nb / 10, fd, len);
		len += ft_putchar_fd((nb % 10) + '0', fd);
		return (len);
	}
	else
		len += ft_putchar_fd(nb + '0', fd);
	return (len);
}

int	ft_putunbr_fd(unsigned int nb, int fd, int len)
{
	if (nb >= 10)
	{
		len = ft_putunbr_fd(nb / 10, fd, len);
		len += ft_putchar_fd((nb % 10) + '0', fd);
		return (len);
	}
	else
		len += ft_putchar_fd(nb + '0', fd);
	return (len);
}
