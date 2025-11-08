/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:06:19 by miissa            #+#    #+#             */
/*   Updated: 2025/07/28 15:27:51 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	product;

	if (nb >= 0)
	{
		if (nb == 0)
			return (1);
		else
		{
			i = 1;
			product = 1;
			while (i <= nb)
			{
				product *= i;
				i++;
			}
			return (product);
		}
	}
	else
		return (0);
}
