/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:29:23 by miissa            #+#    #+#             */
/*   Updated: 2025/07/30 15:37:03 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*dest;

	if (min < max)
	{
		dest = (int *) malloc(sizeof(int) * (max - min + 1));
		if (dest)
		{
			i = 0;
			while (min < max)
			{
				dest[i] = min;
				min++;
				i++;
			}
			return (dest);
		}
		else
			return (0);
	}
	return (0);
}
