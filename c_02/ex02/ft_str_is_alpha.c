/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 09:59:09 by miissa            #+#    #+#             */
/*   Updated: 2025/07/21 11:08:42 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	index;
	int	have_only_alphabet;

	index = 0;
	have_only_alphabet = 1;
	while (str[index] && have_only_alphabet)
	{
		if ((str[index] >= 'a' && str[index] <= 'z')
			|| (str[index] >= 'A' && str[index] <= 'Z'))
			index++;
		else
			have_only_alphabet = 0;
	}
	return (have_only_alphabet);
}
