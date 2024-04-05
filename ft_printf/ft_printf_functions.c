/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:32:21 by jseidere          #+#    #+#             */
/*   Updated: 2023/10/02 15:44:36 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

long long	ft_putnbr_long_fd(long long n, int fd)
{
	int	result;

	result = 0;
	if (n == -2147483648)
	{
		result += write (fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		result += ft_putnbr_long_fd(n / 10, fd);
		result += ft_putnbr_long_fd(n % 10, fd);
	}
	else
	{
		result += ft_putchar_fd(n + 48, fd);
	}
	return (result);
}

int	ft_puthexa(unsigned long long nbr, int check)
{
	char	hex[17];
	int		result;

	result = 0;
	if (check == 2)
		ft_strlcpy (hex, "0123456789abcdef", 17);
	else if (check == 1)
		ft_strlcpy (hex, "0123456789ABCDEF", 17);
	if (nbr > 15)
	{
		result += ft_puthexa(nbr / 16, check);
		result += ft_puthexa(nbr % 16, check);
	}
	else
	{
		result += write(1, &hex[nbr], 1);
	}
	return (result);
}

int	ft_puthexa_ptr(unsigned long long nbr, int check)
{
	char	hex[17];
	int		result;

	result = 0;
	if (nbr == 0)
		result += write(1, "(nil)", 5);
	if (nbr != 0)
	{
		result += write(1, "0x", 2);
		ft_strlcpy (hex, "0123456789abcdef", 17);
		if (nbr > 15)
		{
			result += ft_puthexa(nbr / 16, check);
			result += ft_puthexa(nbr % 16, check);
		}
		else
		{
			result += write(1, &hex[nbr], 1);
		}
	}
	return (result);
}
