/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:29:37 by jseidere          #+#    #+#             */
/*   Updated: 2023/10/02 15:34:41 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
long long	ft_putnbr_long_fd(long long n, int fd);
int			ft_puthexa(unsigned long long nbr, int check);
int			ft_puthexa_ptr(unsigned long long nbr, int check);

#endif // libft_h
