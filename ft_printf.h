/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:35:45 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/07/15 14:57:59 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
size_t	ft_strlen(char *str);
int		ft_putchar(char str);
int		ft_putstr(char *str);
int		ft_putpointer(void *str);
int     ft_putnbr(int num);

#endif
