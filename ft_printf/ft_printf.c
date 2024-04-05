/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:35:43 by jseidere          #+#    #+#             */
/*   Updated: 2023/10/03 11:34:01 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include "./libft/libft.h"
#include "ft_printf.h"

int	format_checker(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_puthexa_ptr(va_arg(args, unsigned long long), 2));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putnbr_long_fd(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 2));
	else if (c == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), 1));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	apply_format(const char *format, va_list args)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_strchr("csidpxXu%", format[i]))
				result += format_checker(format[i], args);
			else
				result += ft_putchar_fd(format[i], 1);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			result++;
		}
		i++;
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	result = apply_format(format, args);
	va_end(args);
	return (result);
}
