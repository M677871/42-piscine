/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:13:08 by miissa            #+#    #+#             */
/*   Updated: 2025/07/21 12:23:13 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	index;
	int	have_only_lc;

	index = 0;
	have_only_lc = 1;
	while (str[index] && have_only_lc)
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			index++;
		else
			have_only_lc = 0;
	}
	return (have_only_lc);
}
