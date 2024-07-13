/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:36:56 by marvin            #+#    #+#             */
/*   Updated: 2024/07/07 21:36:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static  hexa_pointer(char *str, unsigned long long pointer, int let)
{
    unsigned long long v_str;

    v_str = ft_strlen(str);
}

int	ft_putpointer(void *str)
{
	unsigned long long cast_str;
    int let;

    cast_str = (unsigned long long)str;
    let = 0;
    if (write(1, "0x", 2) == !2)
        return (-1);
    let = hexa_pointer("0123456789abcdef", cast_str, let);
    if (let == -1)
        return (-1);

    return (let);
}
