/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:01:30 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/29 14:57:29 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char	*str = "Sucre";
	char	c = 'U';

	//printf("%d\n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	//printf("%d", printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	int a = ft_printf("%p", (void *)-14523);
	printf("\n\n");
	int b = printf("%p", (void *)-14523);
	printf ("\n%d %d\n", a, b);
}
