/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:56:56 by miissa            #+#    #+#             */
/*   Updated: 2025/07/23 15:14:23 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	lenght;

	lenght = 0;
	while (str[lenght])
		lenght++;
	return (lenght);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	result;
	unsigned int	i;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (size > len_d)
		result = len_s + len_d;
	else
		result = len_s + size;
	i = 0;
	while (src[i] && (len_d + 1 < size))
	{
		dest[len_d] = src[i];
		len_d++;
		i++;
	}
	if (len_d < size)
		dest[len_d] = '\0';
	return (result);
}
