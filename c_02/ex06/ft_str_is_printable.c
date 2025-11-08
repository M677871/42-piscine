/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:04:04 by miissa            #+#    #+#             */
/*   Updated: 2025/07/21 21:15:43 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	is_printable;

	i = 0;
	is_printable = 1;
	while (str[i] && is_printable)
	{
		if (str[i] >= ' ' && str[i] <= '~')
			i++;
		else
			is_printable = 0;
	}
	return (is_printable);
}
