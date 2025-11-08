/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:25:01 by miissa            #+#    #+#             */
/*   Updated: 2025/07/21 13:01:21 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	index;
	int	is_upper;

	index = 0;
	is_upper = 1;
	while (str[index] && is_upper)
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
		{
			index++;
		}
		else
			is_upper = 0;
	}
	return (is_upper);
}
