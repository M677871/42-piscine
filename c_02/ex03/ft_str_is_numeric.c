/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:38:31 by miissa            #+#    #+#             */
/*   Updated: 2025/07/21 12:11:13 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	index;
	int	have_only_numeric;

	index = 0;
	have_only_numeric = 1;
	while (str[index] && have_only_numeric)
	{
		if (str[index] >= '0' && str[index] <= '9')
			index++;
		else
			have_only_numeric = 0;
	}
	return (have_only_numeric);
}
