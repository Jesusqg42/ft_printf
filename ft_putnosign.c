/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnosign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:33:07 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/07/17 20:36:22 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnosign(unsigned int num)
{
	int	let;

	let = 0;
	if (num > 9)
	{
		let = ft_putnosign(num / 10);
		if (let == -1)
			return (-1);
		num = num % 10;
	}
	if (num <= 9)
	{
		if (ft_putchar(('0' + num)) == -1)
			return (-1);
		let++;
	}
	return (let);
}
