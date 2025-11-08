/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:51:52 by miissa            #+#    #+#             */
/*   Updated: 2025/08/04 19:00:49 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*dest;
	int	i;

	if (min < max)
	{
		dest = (int *) malloc(sizeof(int) * (max - min + 1));
		if (dest)
		{
			i = 0;
			while (min < max)
				dest[i++] = min++;
			*range = dest;
			return (i);
		}
		else
		{
			*range = 0;
			return (-1);
		}
	}
	else
	{
		*range = 0;
		return (0);
	}
}
