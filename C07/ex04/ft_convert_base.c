/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:48:37 by miissa            #+#    #+#             */
/*   Updated: 2025/08/04 19:03:07 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_digit_places(int nbr, char *base, int i);
void	ft_putnbr_base(int nbr, char *base, char *convert);

int	check_if_valid_base(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9')))
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	get_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (i >= ft_strlen(base))
		return (-1);
	return (i);
}

int	ft_pre_digits(char *str, int *ptr_sign)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*ptr_sign = sign;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	sum;
	int	current;
	int	base_size;

	sum = 0;
	sign = 1;
	base_size = check_if_valid_base(base);
	if (base_size >= 2)
	{
		i = ft_pre_digits(str, &sign);
		current = get_value(str[i], base);
		while (current != -1)
		{
			sum = (sum * base_size) + current;
			i++;
			current = get_value(str[i], base);
		}
		return (sum * sign);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*converted;
	int		i;
	int		decimal;

	if (check_if_valid_base(base_from) || check_if_valid_base(base_to))
		return (0);
	decimal = ft_atoi_base(nbr, base_from);
	i = ft_digit_places(decimal, base_to, 0);
	converted = (char *) malloc(sizeof(char) * (i + 1));
	if (!converted)
		return (0);
	ft_putnbr_base(decimal, base_to, converted);
	converted[i] = '\0';
	return (converted);
}
