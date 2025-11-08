/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:31:15 by miissa            #+#    #+#             */
/*   Updated: 2025/07/22 12:22:12 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

void	cov_to_hexadecimal(char c)
{
	char	*hexadecimal;

	hexadecimal = "0123456789abcdef";
	ft_putchar(hexadecimal[(unsigned char)c / 16]);
	ft_putchar(hexadecimal[(unsigned char)c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_printable(str[i]))
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			cov_to_hexadecimal(str[i]);
		}
		i++;
	}
}
