/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:27:16 by svanmeen          #+#    #+#             */
/*   Updated: 2022/12/01 10:50:11 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>
# include <limits.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putptr(uintptr_t val);
int	ft_putnbr_fd(long nb, int fd, int len);
int	ft_putunbr_fd(unsigned int nb, int fd, int len);
int	ft_put_hexc_nbr_fd(unsigned int nb, int fd, int len);
int	ft_put_hexm_nbr_fd(unsigned int nb, int fd, int len);
#endif
