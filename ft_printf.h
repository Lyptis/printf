/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:27:16 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/29 14:41:29 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>

int	ft_printf(const char *format, ...);

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putptr(unsigned long long val);
int	ft_putnbr_fd(int nb, int fd, int len);
int	ft_putunbr_fd(unsigned int nb, int fd, int len);
int	ft_put_hexc_nbr_fd(unsigned int nb, int fd, int len);
int	ft_put_hexm_nbr_fd(unsigned int nb, int fd, int len);
#endif
