/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:33:50 by miissa            #+#    #+#             */
/*   Updated: 2025/07/24 11:56:24 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!to_find[0])
		return (str);
	while (str[i])
	{
		while (str[i] == to_find[j])
		{
			i++;
			j++;
			if (!to_find[j])
				return (&str[i - j]);
		}
		i = i - j;
		i++;
		j = 0;
	}
	return (0);
	
}


