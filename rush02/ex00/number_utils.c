/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabdalla <pabdalla@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:47:31 by pabdalla          #+#    #+#             */
/*   Updated: 2025/08/03 22:48:46 by pabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_valid(char *s);
int	split_grp(char *num, char ***G);

int	is_valid(char *s)
{
	size_t	i;

	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	split_grp(char *num, char ***G)
{
	size_t	len;
	int		n;
	char	**a;
	int		i;
	int		l;
	char	*s;

	len = 0;
	while (num[len] != '\0')
		len++;
	n = (len + 2) / 3;
	a = malloc(n * sizeof(*a));
	if (a == NULL)
		return (-1);
	i = n - 1;
	while (i >= 0)
	{
		if (len >= 3)
			l = 3;
		else
			l = len;
		s = malloc(l + 1);
		if (s == NULL)
			return (-1);
		s[l] = '\0';
		while (l > 0)
		{
			len--;
			l--;
			s[l] = num[len];
		}
		a[i] = s;
		i--;
	}
	*G = a;
	return (n);
}
