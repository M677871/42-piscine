/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:01:39 by miissa            #+#    #+#             */
/*   Updated: 2025/07/18 10:33:34 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	temp;

	start = 0;
	while (start < size / 2)
	{
		temp = tab[start];
		tab[start] = tab[size - 1 - start];
		tab[size - 1 - start++] = temp;
	}
}
