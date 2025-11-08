/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:32:11 by miissa            #+#    #+#             */
/*   Updated: 2025/07/31 19:21:26 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_total_size(int size, char **strs, char *sep)
{
	int	i;
	int	total;
	int	lengh_sep;

	i = 0;
	total = 0;
	lengh_sep = ft_strlen(sep);
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		if (i < size - 1)
			total += lengh_sep;
		i++;
	}
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total;
	int		i;
	char	*dest;

	if (size <= 0)
	{
		dest = (char *) malloc(sizeof(char));
		if (dest)
			dest[0] = '\0';
		return (dest);
	}
	total = get_total_size(size, strs, sep);
	dest = (char *)malloc(sizeof(char) * (total + 1));
	if (!dest)
		return (0);
	i = 0;
	dest[0] = '\0';
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}
